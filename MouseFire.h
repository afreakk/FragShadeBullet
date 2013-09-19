#ifndef MOUSEFIRE_H
#define MOUSEFIRE_H
#include "glm/glm.hpp"
#include "Obj.h"
#include <vector>
#include <iostream>
#include "Phys.h"
#include "DistanceConstraint.h"
#include "hMotionState.h"
#include "Rope.h"
#include <BulletSoftBody/btSoftBodyHelpers.h>
#define PI 3.1415926535897932384626433832795

class MouseFire:public btActionInterface
{
    public:
        MouseFire(float resX, float resY,GLuint pixShader);
        void check(float mass);
        void addSlegge(GLuint pixShader, GLuint rShader);
        void drawRope();
        void updateAction(btCollisionWorld* ,btScalar);
        void debugDraw(btIDebugDraw*);
        virtual ~MouseFire();
    protected:
    private:
        Obj* zeroObject;
        GLuint pixelShader;
        GLuint ropeShader;
        float scale;
        float rX;
        float rY;
        float mX;
        float mY;
        Obj* mouseObject;
        btSoftBody* ropeBody;
        std::vector<Obj*> objects;
        Obj* slegge;
        Rope* rope;


};

#endif // MOUSEFIRE_H
