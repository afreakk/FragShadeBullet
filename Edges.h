#ifndef EDGES_H
#define EDGES_H
#include <btBulletDynamicsCommon.h>
#include "glm/glm.hpp"
#define PI 3.1415926535897932384626433832795
class Edges
{
    public:
        Edges();
        void enableEdges();
        virtual ~Edges();
    protected:
    private:
        void enableBottomEdge();
        void enableTopEdge();
        void enableRightEdge();
        void enableLeftEdge();
        btBoxShape* makeSideShape();
        btBoxShape* makeHorizontalShape();
        btBoxShape* horShape;
        btBoxShape* sideShape;
        btRigidBody* botRigid;
        btRigidBody* rightRigid;
        btRigidBody* leftRigid;
        btRigidBody* topRigid;
        btScalar xyEdgeWidth;
        btScalar zEdgeWidth;
        btScalar extraWiggly;
        btScalar length;
};

#endif // EDGES_H
