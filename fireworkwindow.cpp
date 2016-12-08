#include "fireworkwindow.h"
#include "firework.h"
#include <SOIL.h>


Firework fw[FIREWORKS];
float r;
float g;
float b;
GLuint texture[1];

FireworkWindow::FireworkWindow()
    : m_program(0)
    , m_frame(0)
{
}

int LoadGLTextures()                                    // Load Bitmaps And Convert To Textures
{
    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture
        (
        "back.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS
        );

    if(texture[0] == 0)
        return false;


    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    return true;                                        // Return Success
}

void FireworkWindow::initialize()
{

    LoadGLTextures();                        // Jump To Texture Loading Routine ( NEW )

                                // Enable Texture Mapping ( NEW )

       glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        // Change to the projection matrix, reset the matrix and set up orthagonal projection (i.e. 2D)
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1); // Parameters: left, right, bottom, top, near, far

        //  Enable smooth shading (i.e. gouraud shading)
        glShadeModel(GL_SMOOTH);

        // Set our clear colour to opaque black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        // Disable depth testing (because we're working in 2D!)
        glDisable(GL_DEPTH_TEST);

        // Enable blending (we need this to be able to use an alpha component)
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Set the accumulation buffer clearing colour to opaque black
        glClearAccum(0.0f, 0.0f, 0.0f, 1.0f);

        glEnable(GL_POINT_SMOOTH);

}

void FireworkWindow::render()
{



        // Set ModelView matrix mode and reset to the default identity matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

            // Clear the accumulation buffer (don't worry, we re-grab the screen into the accumulation buffer after drawing our current frame!)


        // Displacement trick for exact pixelisation
        glTranslatef(0.375, 0.375, 0);

        glAccum(GL_RETURN, 1.0f);
        glColor4f(1.0f,1.0f,1.0f,1.0f);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, texture[0]);
            glBegin (GL_QUADS);
                glTexCoord2d(0.0,0.0); glVertex2d(0.0,0.0);
                glTexCoord2d(1.0,0.0); glVertex2d(800.0,0.0);
                glTexCoord2d(1.0,1.0); glVertex2d(800.0,600.0);
                glTexCoord2d(0.0,1.0); glVertex2d(0.0,600.0);
                glEnd();
                glDisable(GL_TEXTURE_2D);
        for (int loop = 0; loop < FIREWORKS; loop++)
            {
                for (int particleLoop = 0; particleLoop < FIREWORK_PARTICLES; particleLoop++)
                {
                    r   = (rand() / (float)RAND_MAX);
                    g = (rand() / (float)RAND_MAX);
                    b  = (rand() / (float)RAND_MAX);
                    // Set the point size of the firework particles (this needs to be called BEFORE opening the glBegin(GL_POINTS) section!)
                    glPointSize(fw[loop].particleSize);

                    glBegin(GL_POINTS);

                    // Set colour to yellow on way up, then whatever colour firework should be when exploded
                    if (fw[loop].hasExploded == false)
                    {
                        glColor4f(1.0f, 1.0f, 1.0, 1.0f);
                    }
                    else
                    {
                        if(loop%2==0){
                            glColor4f(r,g,b,1.0f);
                        }
                        else{
                            glColor4f(fw[loop].red, fw[loop].green, fw[loop].blue, fw[loop].alpha);
                        }
                    }

                    // Draw the point
                    glVertex2f(fw[loop].x[particleLoop], fw[loop].y[particleLoop]);
                    glEnd();
                }

                // Move the firework appropriately depending on its explosion state
                if (fw[loop].hasExploded == false)
                {
                    fw[loop].move();
                }
                else
                {
                    fw[loop].explode();
                }
            }
            glClear(GL_ACCUM_BUFFER_BIT);
        glAccum(GL_ACCUM, 0.70f);
}

void FireworkWindow::launch(){


}

void FireworkWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {

        case 'A':
        cout<<"coucou"<<endl;
            render();
            break;
    case 'ESC':
        cout<<"coucou"<<endl;
        break;
    }

}

