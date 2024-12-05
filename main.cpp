#include <QApplication>
#include "intro.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Mostrar la primera ventana inicialmente
    FirstWindow firstWindow;
    firstWindow.showMaximized();

    return app.exec();
}
