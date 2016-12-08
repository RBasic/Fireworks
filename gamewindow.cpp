#include "gamewindow.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>

#include <QtGui/QScreen>
#include <windows.h>
#include <QtCore/qmath.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <time.h>
#include <iostream>

#include <QtCore>
#include <QtGui>

#include <omp.h>

int numParticules = 5000;
int minP = 0;
int maxP = 360;
GLfloat* vertices ;
GLfloat* colors ;
using namespace std;


GameWindow::GameWindow(int id)
{
    nbTick = 0;
    m_frame = 0;
    setTitle("Fireworks");
}


void GameWindow::initialize()
{
        glShadeModel(GL_SMOOTH);

        // Set our clear colour to black with full opacity. Syntax is (r, g, b, alpha).
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        // Disable depth testing (because we're working in 2D!)
        glDisable(GL_DEPTH_TEST);

        // Enable blending (we need this to be able to use an alpha component)
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Set the accumulation buffer clearing colour to black at 0,0f alpha
        glClearAccum(0.0f, 0.0f, 0.0f, 1.0f);

        glPointSize(5.0f);

}

void GameWindow::render()
{/*

        glClear(GL_COLOR_BUFFER_BIT);

        // Take the contents of the current accumulation buffer and copy it to the colour buffer with each pixel multiplied by a factor
        // i.e. we clear the screen, draw the last frame again (which we saved in the accumulation buffer), then draw our stuff at its new location on top of that
        glAccum(GL_RETURN, 0.95f);

        // Clear the accumulation buffer (don't worry, we re-grab the screen into the accumulation buffer after drawing our current frame!)
        glClear(GL_ACCUM_BUFFER_BIT);

        // Set ModelView matrix mode and reset to the default identity matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Displacement trick for exact pixelisation
        glTranslatef(0.375, 0.375, 0);
        for (int loop = 0; loop < FIREWORKS; loop++){
                for (int particleLoop = 0; particleLoop < FIREWORK_PARTICLES; particleLoop++){

                    // Set the point size of the firework particles (this needs to be called BEFORE opening the glBegin(GL_POINTS) section!)
                    glPointSize(fw[loop].particleSize);

                    glBegin(GL_POINTS);

                        // Set colour to yellow on way up, then whatever colour firework should be when exploded
                        if (fw[loop].hasExploded == false)
                        {
                            glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                        }
                        else
                        {
                            glColor4f(fw[loop].red, fw[loop].green, fw[loop].blue, fw[loop].alpha);
                        }

                        // Draw the point
                        glVertex2f(fw[loop].x[particleLoop], fw[loop].y[particleLoop]);
                    glEnd();
                }
                if (fw[loop].hasExploded == false)
                        {
                            fw[loop].move();
                        }
                        else
                        {
                            fw[loop].explode();
                        }
        }

        // Take the contents of the current draw buffer and copy it to the accumulation buffer with each pixel modified by a factor
        // The closer the factor is to 1.0f, the longer the trails... Don't exceed 1.0f - you get garbage.
        glAccum(GL_ACCUM, 0.9f);*/

}
