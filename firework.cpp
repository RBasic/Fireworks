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
    // Pick an initial x location and  random x/y speeds
    float xLoc = (rand() / (float)RAND_MAX) * SCREEN_WIDTH;
    float xSpeedVal = -2 + (rand() / (float)RAND_MAX) * 4.0f;
    float ySpeedVal = baselineYSpeed + ((float)rand() / (float)RAND_MAX) * maxYSpeed;

    // Set initial x/y location and speeds
    for (int loop = 0; loop < FIREWORK_PARTICLES; loop++)
    {
        x[loop] = xLoc;
        y[loop] = SCREEN_HEIGHT + 10.0f; // Push the particle location down off the bottom of the screen
        xSpeed[loop] = xSpeedVal;
        ySpeed[loop] = ySpeedVal;
    }

    // Assign a random colour and full alpha (i.e. particle is completely opaque)
    red   = (rand() / (float)RAND_MAX);
    green = (rand() / (float)RAND_MAX);
    blue  = (rand() / (float)RAND_MAX);
    alpha = 1.0f;

    // Firework will launch after a random amount of frames between 0 and 400
    framesUntilLaunch = ((int)rand() % 400);

    // Size of the particle (as thrown to glPointSize) - range is 1.0f to 4.0f
    particleSize = 1.0f + ((float)rand() / (float)RAND_MAX) * 3.0f;

    // Flag to keep trackof whether the firework has exploded or not
    hasExploded = false;

    cout << "Initialised a firework." << endl;
}

void Firework::move()
{
    for (int loop = 0; loop < FIREWORK_PARTICLES; loop++)
    {
        // Once the firework is ready to launch start moving the particles
        if (framesUntilLaunch <= 0)
        {
            x[loop] += xSpeed[loop];

            y[loop] += ySpeed[loop];

            ySpeed[loop] += Firework::GRAVITY;
        }
    }
    framesUntilLaunch--;

    // Once a fireworks speed turns positive (i.e. at top of arc) - blow it up!
    if (ySpeed[0] > 0.0f)
    {
        for (int loop2 = 0; loop2 < FIREWORK_PARTICLES; loop2++)
        {
            // Set a random x and y speed beteen -4 and + 4
            xSpeed[loop2] = -4 + (rand() / (float)RAND_MAX) * 8;
            ySpeed[loop2] = -4 + (rand() / (float)RAND_MAX) * 8;
        }

        cout << "Boom!" << endl;
        hasExploded = true;
    }
}

void Firework::explode()
{
    for (int loop = 0; loop < FIREWORK_PARTICLES; loop++)
    {
        // Dampen the horizontal speed by 1% per frame
        xSpeed[loop] *= 0.99;

        // Move the particle
        x[loop] += xSpeed[loop];
        y[loop] += ySpeed[loop];

        // Apply gravity to the particle's speed
        ySpeed[loop] += Firework::GRAVITY;
    }

    // Fade out the particles (alpha is stored per firework, not per particle)
    if (alpha > 0.0f)
    {
        alpha -= 0.01f;
    }
    else // Once the alpha hits zero reset the firework
    {
        initialise();
    }
}
