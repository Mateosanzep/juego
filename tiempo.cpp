#include "intro.h"
#include "juego.h"
#include "tiempo.h"
#include "mal.h"
#include "ganaste.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QProcess>
#include <QCoreApplication>

TiempoWindow::TiempoWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Tiempo");
    setStyleSheet("background-color: #EC2300;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);

    // Crear y configurar la etiqueta de bienvenida
    QLabel *welcomeLabel = new QLabel("¡Se te acabó el tiempo!", this);
    welcomeLabel->setStyleSheet("font-size: 100px; font-weight: bold; color: white; margin: 50px;");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);

    // Crear y configurar la etiqueta de pregunta
    QLabel *questionLabel = new QLabel("¿Quieres volver a jugar?", this);
    questionLabel->setStyleSheet("font-size: 30px; font-weight: bold; color: white; margin: 10px;");
    questionLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(questionLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *continueButton = new QPushButton("Empezar", this);
    QPushButton *outButton = new QPushButton("Salir", this);

    // Diseño redondo para los botones
    continueButton->setStyleSheet("border-radius: 25px; background-color: #26B12C; color: #FFF; font-weight: bold; font-size: 18px; max-width: 500px; height: 50px; margin: 20px;");
    outButton->setStyleSheet("border-radius: 25px; background-color: #003E97; color: #FFF; font-weight: bold; font-size: 18px; max-width: 500px; height: 50px; margin: 20px;");

    // Conectar los botones a sus slots
    connect(continueButton, &QPushButton::clicked, this, &TiempoWindow::openMainWindow);
    connect(outButton, &QPushButton::clicked, this, &TiempoWindow::goOut);

    // Añadir los botones al layout horizontal
    buttonLayout->addWidget(continueButton);
    buttonLayout->addWidget(outButton);
    layout->addLayout(buttonLayout);
}

void TiempoWindow::openMainWindow() {
    // Crear la ventana principal
    QString program = QCoreApplication::applicationFilePath();

    // Salir de la aplicación actual
    QApplication::exit(0);

    // Lanzar un nuevo proceso del mismo programa
    QProcess::startDetached(program, QStringList());
}

void TiempoWindow::goOut() {
    QApplication::quit();
}

#include "tiempo.moc"