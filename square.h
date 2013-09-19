#ifndef SQUARE_H
#define SQUARE_H
#define GLEW_STATIC
#include <GL/glew.h>

class square
{
    public:
        square();
        virtual ~square();
        void bindSquare(GLuint shader);
        void draw();
    protected:
    private:
        GLint posAttrib;
        GLuint classShader;
        GLuint vbo;
};

#endif // SQUARE_H
