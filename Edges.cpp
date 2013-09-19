#include "Edges.h"
#include "hMotionState.h"
Edges::Edges():horShape(0),botRigid(0),xyEdgeWidth(0.6),zEdgeWidth(10.0),extraWiggly(0.5),length(PI*2.1)
,topRigid(0),leftRigid(0),rightRigid(0)
{

}

Edges::~Edges()
{
    if(botRigid)
        delete botRigid;
    if(topRigid)
        delete topRigid;
    if(leftRigid)
        delete leftRigid;
    if(rightRigid)
        delete rightRigid;
}

void Edges::enableEdges()
{
    sideShape = makeSideShape();
    horShape = makeHorizontalShape();
    enableBottomEdge();
    enableTopEdge();
    enableLeftEdge();
    enableRightEdge();
}
btBoxShape* Edges::makeHorizontalShape()
{
    btScalar mass = 0.0;
    btVector3 cubeInertia(0.0, 0.0, 0.0);
    btBoxShape* shape= new btBoxShape(btVector3(length, xyEdgeWidth,zEdgeWidth)); //testx2
    shape->calculateLocalInertia(mass,cubeInertia);
    return shape;
}
void Edges::enableBottomEdge()
{
    btVector3 pos = btVector3(PI,-extraWiggly,1.0);
    btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion::getIdentity(),pos));
    btScalar mass = 0.0;
    btVector3 cubeInertia(0.0, 0.0, 0.0);
    btRigidBody::btRigidBodyConstructionInfo cubeRigidCI(mass,motionState,horShape,cubeInertia);
    botRigid = new btRigidBody(cubeRigidCI);
    Phys::getInstance()->addRigid(botRigid);
}
void Edges::enableTopEdge()
{
    btVector3 pos = btVector3(PI,PI*2.0+extraWiggly,1.0);
    btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion::getIdentity(),pos));
    btScalar mass = 0.0;
    btVector3 cubeInertia(0.0, 0.0, 0.0);
    btRigidBody::btRigidBodyConstructionInfo cubeRigidCI(mass,motionState,horShape,cubeInertia);
    topRigid = new btRigidBody(cubeRigidCI);
    Phys::getInstance()->addRigid(topRigid);
}
btBoxShape* Edges::makeSideShape()
{
    btVector3 cubeInertia(0.0, 0.0, 0.0);
    btScalar mass = 0.0;
    btBoxShape* shape= new btBoxShape(btVector3(xyEdgeWidth, length,zEdgeWidth)); //testx2
    shape->calculateLocalInertia(mass,cubeInertia);
    return shape;
}
void Edges::enableRightEdge()
{
    btVector3 pos = btVector3(PI*2.0+extraWiggly,PI,1.0);
    btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion::getIdentity(),pos));
    btVector3 cubeInertia(0.0, 0.0, 0.0);
    btScalar mass = 0.0;
    btRigidBody::btRigidBodyConstructionInfo cubeRigidCI(mass,motionState,sideShape,cubeInertia);
    rightRigid = new btRigidBody(cubeRigidCI);
    Phys::getInstance()->addRigid(rightRigid);
}
void Edges::enableLeftEdge()
{
    btVector3 pos = btVector3(-extraWiggly,PI,1.0);
    btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion::getIdentity(),pos));
    btVector3 cubeInertia(0.0, 0.0, 0.0);
    btScalar mass = 0.0;
    btRigidBody::btRigidBodyConstructionInfo cubeRigidCI(mass,motionState,sideShape,cubeInertia);
    leftRigid = new btRigidBody(cubeRigidCI);
    Phys::getInstance()->addRigid(leftRigid);
}
