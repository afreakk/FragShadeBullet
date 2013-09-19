#include <iostream>
#include "Window.h"
#include "shaderCompile.h"
#include "square.h"
#include "Obj.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Phys.h"
#include "Edges.h"
#include "MouseFire.h"
#include "Rope.h"
#define PI 3.1415926535897932384626433832795
int main()
{
    Phys * physx= Phys::getInstance();
    physx->init();
    glm::vec2 res= glm::vec2(600.0f,600.0f);
    Window window;
    window.init(res.x,res.y);
    window.initGlew();
    shaderCompile shaderC;
    GLuint pixelShader = shaderC.loadShader("Shader/v","Shader/f");
    GLuint ropeShader = shaderC.loadShader("Shader/v","Shader/fBlue");
    glUseProgram(pixelShader);
    glUniform2fv(glGetUniformLocation(pixelShader,"resolution"),1,glm::value_ptr(res));
    {
        float startPos[254*2];
        for(int i=0; i<254*2; i++)
            startPos[i]=PI;
        glUniform2fv(glGetUniformLocation(pixelShader, "pos"), 254, startPos);
    }
    square sq;
    sq.bindSquare(pixelShader);



    double time = glfwGetTime();
    double globalTime = time;
    Edges edges;
    edges.enableEdges();
    MouseFire mouseFire(res.x,res.y,pixelShader);
    mouseFire.addSlegge(pixelShader,ropeShader);
    while(!window.quit())
    {
        globalTime = glfwGetTime()-time;
        time = glfwGetTime();
        physx->update(globalTime);
        mouseFire.check(0.001f);
        sq.draw();
        mouseFire.drawRope();
        window.swapB();
    }
    delete physx;
    return 0;
}
