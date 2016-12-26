#include "fireworkwindow.h"
#include "firework.h"


int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;

    FireworkWindow window;
    window.setFormat(format);
    window.resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    window.show();

    window.setAnimating(true);

    return app.exec();
}
