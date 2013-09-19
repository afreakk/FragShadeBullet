#ifndef OBJ_H
#define OBJ_H
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glfw.h>
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include <sstream>
#include <btBulletDynamicsCommon.h>
#include "Phys.h"
#define PI 3.1415926535897932384626433832795
class Obj
{
    public:
        Obj(float x, float y, GLuint shaderX);
        virtual ~Obj();
        void translate(float, float);
        void setPosition(float, float);
        void enablePhysicsBox(float MASS,float radius, btSphereShape* box=0);
        btRigidBody* getBody();
        glm::vec2 getPosition();
    protected:
    private:
        GLuint shader;
        std::string name;
        std::string convertInt(unsigned int number);
        glm::vec2 position;
        unsigned int index;
        static unsigned int GlobalIndex;
        btRigidBody*rigidBody;
        btSphereShape* cubeShape;
};

#endif // OBJ_H
