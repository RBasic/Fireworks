#ifndef FIREWORK2_H
#define FIREWORK2_H

#include "firework.h"

using namespace std;


class Firework2
{
    public:
        GLfloat x[FIREWORK_PARTICLES2];
        GLfloat y[FIREWORK_PARTICLES2];
        GLfloat xSpeed[FIREWORK_PARTICLES2];
        GLfloat ySpeed[FIREWORK_PARTICLES2];

        GLfloat red;
        GLfloat blue;
        GLfloat green;
        GLfloat alpha;

        GLint framesUntilLaunch;

        GLfloat particleSize;
        GLboolean hasExploded;
        static const GLfloat baselineYSpeed;
        static const GLfloat maxYSpeed;

        static const GLfloat GRAVITY;

        Firework2(); // Constructor declaration
        void initialise();
        void move();
        void explode();
};

#endif // FIREWORK_H
