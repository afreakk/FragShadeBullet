#ifndef WINDOW_H
#define WINDOW_H
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glfw.h>
#include <iostream>
class Window
{
    public:
        Window();
        virtual ~Window();
        void init(const unsigned int x, const unsigned int y);
        void initGlew();
        void swapB();
        void setTitle(const char* title);
        bool quit();
    protected:
    private:
};

#endif // WINDOW_H
