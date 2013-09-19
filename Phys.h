#ifndef PHYS_H
#define PHYS_H
#include <btBulletDynamicsCommon.h>
#include <vector>
#include "glm/gtc/quaternion.hpp"
#include "BulletCollision/CollisionDispatch/btGhostObject.h"
#include <BulletSoftBody/btSoftRigidDynamicsWorld.h>
#include <BulletSoftBody/btDefaultSoftBodySolver.h>
#include <BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.h>
#include <iostream>
class Phys
{
    public:
        static Phys * getInstance()
        {
            if(!pton)
                pton = new Phys();
            return pton;
        }
        void init();
        virtual ~Phys();
        void addRigid(btRigidBody* body);
        void update(const double& dTime);
        void addAction(btActionInterface* axion);
        void addConstrain(btTypedConstraint* constrain);
        void addGhost(btGhostObject* ghost);
        void addSoftBody(btSoftBody* sbody);
        btSoftRigidDynamicsWorld* getWorld();
    protected:
    private:
        static Phys *pton;
        Phys();
        btBroadphaseInterface* broadphase;
        btDefaultCollisionConfiguration* collisionConfiguration;        btCollisionDispatcher* dispatcher;
        btSequentialImpulseConstraintSolver* solver;
        btDefaultSoftBodySolver* softSolver;
        btSoftRigidDynamicsWorld* dynamicsWorld;
        std::vector<btRigidBody*> rigids;
        std::vector<btSoftBody*> softs;
        std::vector<btGhostObject*> ghosts;
//        std::vector<Object3D*> sNodes;
        std::vector<btBoxShape*> shapes;
        std::vector<btActionInterface*> actionInterfaces;
        std::vector<btTypedConstraint*> constrains;

};

#endif // PHYS_H
