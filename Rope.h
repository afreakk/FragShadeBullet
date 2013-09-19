#ifndef ROPE_H
#define ROPE_H
#define GLEW_STATIC
#include <GL/glew.h>

class Rope
{
    public:
        Rope();
        void draw(float x1, float y1, float x2, float y2, GLuint shader);
        virtual ~Rope();
    protected:
    private:
        GLuint vbo;
        GLuint classShader;
};

#endif // ROPE_H
