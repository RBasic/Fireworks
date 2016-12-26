#include "fireworkwindow.h"
#include "firework.h"
#include "firework2.h"
#include <SOIL.h>



Firework fw[FIREWORKS];
Firework2 fw2[FIREWORKS2];
float r;
float g;
float b;
GLuint texture[1];

FireworkWindow::FireworkWindow()
    : m_program(0)
{
}

int LoadGLTextures()
{
    texture[0] = SOIL_load_OGL_texture
        (
        "back.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS
        );

    if(texture[0] == 0){
        return false;
    }
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    return true;
}

void FireworkWindow::initialize()
{
        LoadGLTextures();
        glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);

        glShadeModel(GL_SMOOTH);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glDisable(GL_DEPTH_TEST);

        glEnable(GL_BLEND);
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glClearAccum(0.0f, 0.0f, 0.0f, 1.0f);

        glEnable(GL_POINT_SMOOTH);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.375, 0.375, 0);
}

void FireworkWindow::render()
{
    if(BACKGROUND){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glBegin (GL_QUADS);
        glTexCoord2d(0.0,0.0); glVertex2d(0.0,0.0);
        glTexCoord2d(1.0,0.0); glVertex2d(SCREEN_WIDTH,0.0);
        glTexCoord2d(1.0,1.0); glVertex2d(SCREEN_WIDTH,SCREEN_HEIGHT);
        glTexCoord2d(0.0,1.0); glVertex2d(0.0,SCREEN_HEIGHT);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
        glAccum(GL_RETURN, 1.0f);
        glColor4f(1.0f,1.0f,1.0f,1.0f);


        for(int i=0;i<FIREWORKS2;i++){
            for (int j = 0; j < FIREWORK_PARTICLES2; j++)
            {
                glPointSize(fw2[i].particleSize);

                glBegin(GL_POINTS);
                glColor4f(1, 1, 0, 1);
                glVertex2f(fw2[i].x[j], fw2[i].y[j]);
                glEnd();
            }
            if (fw2[i].hasExploded == false)
            {
                fw2[i].move();
            }
            else
            {
                fw2[i].explode();
            }
        }

        for (int i = 0; i < FIREWORKS; i++)
            {
                for (int j = 0; j < FIREWORK_PARTICLES; j++)
                {
                    r   = (rand() / (float)RAND_MAX);
                    g = (rand() / (float)RAND_MAX);
                    b  = (rand() / (float)RAND_MAX);
                    glPointSize(fw[i].particleSize);

                    glBegin(GL_POINTS);

                    if (fw[i].hasExploded == false)
                    {
                        glColor4f(1.0f, 1.0f, 1.0, 1.0f);
                    }
                    else
                    {
                        if(i%2==0){
                            glColor4f(r,g,b,1.0f);
                        }
                        else{
                            glColor4f(fw[i].red, fw[i].green, fw[i].blue, fw[i].alpha);
                        }
                    }

                    glVertex2f(fw[i].x[j], fw[i].y[j]);
                    glEnd();
                }

                if (fw[i].hasExploded == false)
                {
                    fw[i].move();
                }
                else
                {
                    fw[i].explode();
                }

            }
            glClear(GL_ACCUM_BUFFER_BIT);

        glAccum(GL_ACCUM, 0.90f);
}


void FireworkWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        exit(EXIT_FAILURE);
        break;
    }

}

