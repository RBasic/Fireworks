#ifndef FIREWORK_H
#define FIREWORK_H

#include <GL/gl.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

const GLint SCREEN_WIDTH = 800;
const GLint SCREEN_HEIGHT = 600;
const GLint SCREEN_BPP = 32;
const int FIREWORKS = 50;           // Number of fireworks
const int FIREWORK_PARTICLES = 100;  // Number of particles per firework
using namespace std;


class Firework
{
    public:
        GLfloat x[FIREWORK_PARTICLES];
        GLfloat y[FIREWORK_PARTICLES];
        GLfloat xSpeed[FIREWORK_PARTICLES];
        GLfloat ySpeed[FIREWORK_PARTICLES];

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

        Firework(); // Constructor declaration
        void initialise();
        void move();
        void explode();
};

#endif // FIREWORK_H
