#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "openglwindow.h"
#include "firework.h"

struct point
{
    float x, y ,z;
};

class paramCamera
{
public:
    float rotX = -45.0;
    float rotY = -45.0;
    float ss = 1.0f;
    float anim = 0.0f;

    int etat = 0;
};

class GameWindow : public OpenGLWindow
{
Q_OBJECT

public:
    GameWindow();
    GameWindow(int maj);
    void initialize() Q_DECL_OVERRIDE;
    void render()Q_DECL_OVERRIDE;

    void displayColor(float);
    paramCamera* c;

private:
    int nbTick = 0;
    int m_frame = 0;
    int season, day;
    point* particules;
    bool master = false;

    QImage m_image;
    point *p;
    QOpenGLShaderProgram *m_program;
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;


    int m_for=0;
    int m_twist=0;

};



#endif // GameWindow_H
