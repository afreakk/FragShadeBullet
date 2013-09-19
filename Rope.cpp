#include "Rope.h"

Rope::Rope()
{
    glGenBuffers(1,&vbo);
}

Rope::~Rope()
{
    //dtor
}
void Rope::draw(float x1, float y1, float x2, float y2, GLuint shader)
{
    classShader = shader;
    GLint posAttrib = glGetAttribLocation(shader, "position");
    float verticies[4];
    verticies[0]=x1,verticies[1]=y1,verticies[2]=x2,verticies[3]=y2;
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies),verticies,GL_STREAM_DRAW);
    glVertexAttribPointer( posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray( posAttrib );
    glDrawArrays(GL_LINES,0,2);
}
