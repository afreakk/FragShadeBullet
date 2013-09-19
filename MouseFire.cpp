#include "MouseFire.h"

MouseFire::MouseFire(float resX,float resY,GLuint pixShader):mX(0),mY(0),rX(resX),rY(resY),slegge(0),mouseObject(0),scale(PI*2.0/35.0)
,rope(0)
{
    zeroObject = new Obj(0,0,pixelShader);
    zeroObject->enablePhysicsBox(0,scale);
}
bool released=false;
template <typename T> T CLAMP(const T& value, const T& low, const T& high)
{
  return value < low ? low : (value > high ? high : value);
}
void MouseFire::addSlegge(GLuint pixShader, GLuint rShader)
{
    pixelShader = pixShader;
    ropeShader = rShader;
    btScalar hingeLength = PI/2.0;
    btScalar mass = 100.001;
    btVector3 from = btVector3(PI,PI,1.0);
    btVector3 to = btVector3(PI,PI-hingeLength,1.0);
    mouseObject = new Obj(from.x(),from.y(),pixelShader);
    slegge = new Obj(to.x(),to.y(),pixelShader);
    slegge->enablePhysicsBox(mass,scale);
    mouseObject->enablePhysicsBox(0,scale/10.0);

    Phys::getInstance()->addAction(this);
    rope = new Rope();


    ropeBody=btSoftBodyHelpers::CreateRope(Phys::getInstance()->getWorld()->getWorldInfo(),from,to,8,0);
    ropeBody->appendAnchor(0,mouseObject->getBody());
    ropeBody->appendAnchor(9,slegge->getBody());
    Phys::getInstance()->addSoftBody(ropeBody);

}
void MouseFire::updateAction(btCollisionWorld* collworld,btScalar time)
{
    mouseObject->getBody()->getWorldTransform().setOrigin(btVector3(mX,mY,1.0));
}
void MouseFire::debugDraw(btIDebugDraw* lol)
{
}
void MouseFire::check(float mass)
{
    int iX,iY;
    glfwGetMousePos(&iX,&iY);
    mX = iX,mY=iY;
    mX = (mX/rX)*(PI*2.0);
    mY = (mY/rY)*(PI*2.0);
    mY *= -1.0;
    mY += PI*2.0;
    mY = CLAMP(mY,0.1f,float(PI*2.0-0.1f));
    mX = CLAMP(mX,0.1f,float(PI*2.0-0.1f));
    if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)==GLFW_RELEASE)
        released = true;
    if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS)
    {
        Obj * obj = new Obj(mX,mY,pixelShader);
        obj->enablePhysicsBox(mass,scale);
        objects.push_back(obj);
        released=false;
    }
}
void MouseFire::drawRope()
{
    float fX= mX/PI-1.0;
    float fY= mY/PI-1.0;
    float tX = slegge->getPosition().x/PI-1.0;
    float tY = slegge->getPosition().y/PI-1.0;
    glUseProgram(ropeShader);
    btSoftBody::tLinkArray&   links(ropeBody->m_links);
    rope->draw(fX,fY,links[0].m_n[0]->m_x.x()/PI-1.0,links[0].m_n[0]->m_x.y()/PI-1.0,ropeShader);
    for(int j=0;j<links.size();++j)
   {
      btSoftBody::Node*   node_0=links[j].m_n[0];
      btSoftBody::Node*   node_1=links[j].m_n[1];
      rope->draw(node_0->m_x.x()/PI-1.0,node_0->m_x.y()/PI-1.0,node_1->m_x.x()/PI-1.0,node_1->m_x.y()/PI-1.0,ropeShader);
   }
    rope->draw(tX,tY,links[links.size()-1].m_n[1]->m_x.x()/PI-1.0,links[links.size()-1].m_n[1]->m_x.y()/PI-1.0,ropeShader);
    glUseProgram(pixelShader);
}
MouseFire::~MouseFire()
{
    for(int i=0; i<objects.size();i++)
    {
        if(objects[i])
            delete objects[i];
    }
    if(slegge)
        delete slegge;
}

