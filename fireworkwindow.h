#ifndef FIREWORKWINDOW_H
#define FIREWORKWINDOW_H

#include "openglwindow.h"
#include <QKeyEvent>

class FireworkWindow : public OpenGLWindow
{
public:
    FireworkWindow();

    void initialize() Q_DECL_OVERRIDE;
    void render() Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event);
    void launch();

private:
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
};

#endif // FIREWORKWINDOW_H
