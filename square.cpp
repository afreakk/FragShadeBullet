#include "square.h"

square::square()
{
    glGenBuffers(1,&vbo);
}
void square::bindSquare(GLuint shader)
{
    classShader = shader;
    float vertices[] = {
     1.0f,  1.0f,
     -1.0f,  1.0f,
    -1.0f, -1.0f,

    -1.0f, -1.0f,
    1.0f, -1.0f,
    1.0, 1.0f
    };
    posAttrib = glGetAttribLocation(classShader, "position");
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer( posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray( posAttrib );

}
void square::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer( posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray( posAttrib );
    glDrawArrays(GL_TRIANGLES, 0,6);
}
square::~square()
{
    //dtor
}
