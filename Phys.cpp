#include "Phys.h"
Phys *Phys::pton=0;
Phys::Phys():broadphase(0),collisionConfiguration(0),dispatcher(0),solver(0),dynamicsWorld(0)
{

}
void Phys::addGhost(btGhostObject* ghost)
{
    ghosts.push_back(ghost);
    dynamicsWorld->addCollisionObject(ghost);
}
void Phys::addRigid(btRigidBody* body)
{
    rigids.push_back(body);
    dynamicsWorld->addRigidBody(body);
}
void Phys::addConstrain(btTypedConstraint* constrain)
{
    constrains.push_back(constrain);
    dynamicsWorld->addConstraint(constrain);
}
void Phys::addAction(btActionInterface* axion)
{
    actionInterfaces.push_back(axion);
    dynamicsWorld->addAction(axion);
}
void Phys::update(const double& dTime)
{
    dynamicsWorld->stepSimulation(dTime,7);
    btTransform trans;
}
btSoftRigidDynamicsWorld* Phys::getWorld()
{
    return dynamicsWorld;
}
void Phys::init()
{
    // Build the broadphase
    broadphase = new btDbvtBroadphase();

    // Set up the collision configuration and dispatcher
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);

    // The actual physics solver
    solver = new btSequentialImpulseConstraintSolver;
    softSolver = new btDefaultSoftBodySolver();

    // The world.
    dynamicsWorld = new btSoftRigidDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration,softSolver);
    dynamicsWorld->setGravity(btVector3(0,-9.0,0));

}
void Phys::addSoftBody(btSoftBody* sbody)
{
    softs.push_back(sbody);
    dynamicsWorld->addSoftBody(sbody);
}
Phys::~Phys()
{
    for(unsigned i=0; i<rigids.size(); i++)
    {
        dynamicsWorld->removeRigidBody(rigids[i]);
    }
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete collisionConfiguration;
    delete broadphase;
}
