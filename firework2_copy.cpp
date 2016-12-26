#include "firework2.h"

const GLfloat Firework2::GRAVITY = 0.05f;
const GLfloat Firework2::baselineYSpeed = -6.0f;
const GLfloat Firework2::maxYSpeed = -4.5f;


Firework2::Firework2()
{
    initialise();
}

void Firework2::initialise()
{
    float xLoc = SCREEN_WIDTH/2;
    float xSpeedVal;
    float ySpeedVal;

    for (int i = 0; i < FIREWORK_PARTICLES2; i++)
    {
        xSpeedVal =1- (rand() / (float)RAND_MAX) * 2.0f;
        ySpeedVal =-1+ ((float)rand() / (float)RAND_MAX) * maxYSpeed;
        x[i] = xLoc;
        y[i] = SCREEN_HEIGHT +10.0f;
        xSpeed[i] = xSpeedVal;
        ySpeed[i] = ySpeedVal;
    }

    red   = (rand() / (float)RAND_MAX);
    green = (rand() / (float)RAND_MAX);
    blue  = (rand() / (float)RAND_MAX);
    alpha = 1.0f;

    framesUntilLaunch = ((int)rand() % 400);
    particleSize = 1.0f + ((float)rand() / (float)RAND_MAX) * 2.0f;
}

void Firework2::move()
{
    for (int i = 0; i < FIREWORK_PARTICLES2; i++)
    {
        if (framesUntilLaunch <= 0)
        {
            hasExploded = true;
        }
    }
    framesUntilLaunch--;
}

void Firework2::explode()
{
    for (int i = 0; i < FIREWORK_PARTICLES2; i++)
    {
        xSpeed[i] *= 0.99;

        x[i] += xSpeed[i];
        y[i] += ySpeed[i];


        ySpeed[i] += Firework2::GRAVITY;
    }

    if (alpha > 0.0f)
    {
        alpha -= 0.01f;
    }
    else
    {
        initialise();
    }
}
