#include "Obj.h"
#include "hMotionState.h"
unsigned int Obj::GlobalIndex =0;
Obj::Obj(float x, float y, GLuint shaderX):rigidBody(0)
{
    shader = shaderX;
    index = GlobalIndex;
    GlobalIndex++;
    name= std::string("pos[");
    name += convertInt(index);
    name += ']';
    position.x = x;
    position.y = y;
    glUniform2fv(glGetUniformLocation(shader, name.c_str()), 1, glm::value_ptr(position));
}
glm::vec2 Obj::getPosition()
{
    return position;
}

void Obj::enablePhysicsBox(float MASS,float radius, btSphereShape* box)
{
    hMotionState* motionState = new hMotionState(this,btTransform(btQuaternion::getIdentity(),btVector3(position.x,position.y,1.0)));
    btScalar mass = MASS;
    btVector3 cubeInertia(0.0, 0.0, 0.0);
    if(!box)
        cubeShape= new btSphereShape(radius); //testx2
    else
        cubeShape = box;
    cubeShape->calculateLocalInertia(mass,cubeInertia);
    btRigidBody::btRigidBodyConstructionInfo cubeRigidCI(mass,motionState,cubeShape,cubeInertia);
    rigidBody = new btRigidBody(cubeRigidCI);
    rigidBody->setLinearFactor(btVector3(1.0,1.0,0.0));
    Phys::getInstance()->addRigid(rigidBody);
    //Phys::getInstance()->addAction(this);
}
btRigidBody* Obj::getBody()
{
    return rigidBody;
}
void Obj::translate(float x, float y)
{
    glm::vec2 translation = glm::vec2(x,y);
    position += translation;
    glUniform2fv(glGetUniformLocation(shader, name.c_str()), 1, glm::value_ptr(position));
}
void Obj::setPosition(float x, float y)
{
    glm::vec2 newPos= glm::vec2(x,y);
    position = newPos;
    glUniform2fv(glGetUniformLocation(shader, name.c_str()), 1, glm::value_ptr(position));
}
Obj::~Obj()
{
    //dtor
}
std::string Obj::convertInt(unsigned int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
