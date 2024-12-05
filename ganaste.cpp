#include "intro.h"
#include "juego.h"
#include "tiempo.h"
#include "mal.h"
#include "game.h"
#include "constantes.h"
#include "config.h"
#include "questions.h"
#include "ganaste.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QProcess>
#include <QCoreApplication>



GanasteWindow::GanasteWindow( QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ganaste");
    setStyleSheet("background-color: #26B12C;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);

    // Crear y configurar la etiqueta de bienvenida
    QLabel *welcomeLabel = new QLabel("¡Felicidades, eres millonario!", this);
    welcomeLabel->setStyleSheet("font-size: 80px; font-weight: bold; color: white; margin: 50px;");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);

    QLabel *ganasteLabel = new QLabel("Ganaste $1,000,000", this);
    ganasteLabel->setStyleSheet("font-size: 30px; font-weight: bold; color: white; margin: 10px;");
    ganasteLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(ganasteLabel);

    // Crear y configurar la etiqueta de pregunta
    QLabel *questionLabel = new QLabel("¿Quieres volver a jugar?", this);
    questionLabel->setStyleSheet("font-size: 30px; font-weight: bold; color: white; margin: 10px;");
    questionLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(questionLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *continueButton = new QPushButton("Empezar", this);
    QPushButton *outButton = new QPushButton("Salir", this);

    // Diseño redondo para los botones
    continueButton->setStyleSheet("border-radius: 25px; background-color: #EC2300; color: #FFF; font-weight: bold; font-size: 18px; max-width: 500px; height: 50px; margin: 20px;");
    outButton->setStyleSheet("border-radius: 25px; background-color: #003E97; color: #FFF; font-weight: bold; font-size: 18px; max-width: 500px; height: 50px; margin: 20px;");

    // Conectar los botones a sus slots
    connect(continueButton, &QPushButton::clicked, this, &GanasteWindow::openMainWindow);
    connect(outButton, &QPushButton::clicked, this, &GanasteWindow::goOut);

    // Añadir los botones al layout horizontal
    buttonLayout->addWidget(continueButton);
    buttonLayout->addWidget(outButton);
    layout->addLayout(buttonLayout);
}


void GanasteWindow::openMainWindow() {
    // Obtener la ruta completa del ejecutable actual
    QString program = QCoreApplication::applicationFilePath();

    // Salir de la aplicación actual
    QApplication::exit(0);

    // Lanzar un nuevo proceso del mismo programa
    QProcess::startDetached(program, QStringList());
}

void GanasteWindow::goOut() {
    QApplication::quit();
}

#include "ganaste.moc"