#include "firework.h"

const GLfloat Firework::GRAVITY = 0.05f;
const GLfloat Firework::baselineYSpeed = -4.0f;
const GLfloat Firework::maxYSpeed = -4.0f;


Firework::Firework()
{
    initialise();
}

void Firework::initialise()
{

    effect.setSource(QUrl::fromLocalFile("explode.wav"));
    effect.setVolume(1.0f);
    effect.setLoopCount(1);
    float xLoc = (rand() / (float)RAND_MAX) * SCREEN_WIDTH;
    float xSpeedVal = -2 + (rand() / (float)RAND_MAX) * 4.0f;
    float ySpeedVal = baselineYSpeed + ((float)rand() / (float)RAND_MAX) * maxYSpeed;

    for (int i = 0; i < FIREWORK_PARTICLES; i++)
    {
        x[i] = xLoc;
        y[i] = SCREEN_HEIGHT + 10.0f;
        xSpeed[i] = xSpeedVal;
        ySpeed[i] = ySpeedVal;
    }

    red   = (rand() / (float)RAND_MAX);
    green = (rand() / (float)RAND_MAX);
    blue  = (rand() / (float)RAND_MAX);
    alpha = 1.0f;

    framesUntilLaunch = ((int)rand() % 400);

    particleSize = 1.0f + ((float)rand() / (float)RAND_MAX) * 3.0f;

    hasExploded = false;
}

void Firework::move()
{
    for (int i = 0; i < FIREWORK_PARTICLES; i++)
    {
        if (framesUntilLaunch <= 0)
        {
            x[i] += xSpeed[i];

            y[i] += ySpeed[i];

            ySpeed[i] += Firework::GRAVITY;
        }
    }
    framesUntilLaunch--;

    if (ySpeed[0] > 0.0f)
    {
        for (int j = 0; j < FIREWORK_PARTICLES; j++)
        {
            xSpeed[j] = -4 + (rand() / (float)RAND_MAX) * 8;
            ySpeed[j] = -4 + (rand() / (float)RAND_MAX) * 8;
        }
        effect.play();
        hasExploded = true;
    }
}

void Firework::explode()
{

    for (int i = 0; i < FIREWORK_PARTICLES; i++)
    {
        xSpeed[i] *= 0.99;

        x[i] += xSpeed[i];
        y[i] += ySpeed[i];


        ySpeed[i] += Firework::GRAVITY;
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
