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

FirstWindow::FirstWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Intro");
    setStyleSheet("background-color: #003E97;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);

    // Crear y configurar la etiqueta de bienvenida
    QLabel *welcomeLabel = new QLabel("Bienvenido a Millonario", this);
    welcomeLabel->setStyleSheet("font-size: 100px; font-weight: bold; color: white; margin: 50px;");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);

    // Crear y configurar la etiqueta de pregunta
    QLabel *questionLabel = new QLabel("¿Quieres empezar a jugar?", this);
    questionLabel->setStyleSheet("font-size: 30px; font-weight: bold; color: white; margin: 10px;");
    questionLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(questionLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *continueButton = new QPushButton("Empezar", this);
    QPushButton *outButton = new QPushButton("Salir", this);

    // Diseño redondo para los botones
    continueButton->setStyleSheet("border-radius: 25px; background-color: #26B12C; color: #FFF; font-weight: bold; font-size: 18px; max-width: 500px; height: 50px; margin: 20px;");
    outButton->setStyleSheet("border-radius: 25px; background-color: #E00000; color: #FFF; font-weight: bold; font-size: 18px; max-width: 500px; height: 50px; margin: 20px;");

    // Conectar los botones a sus slots
    connect(continueButton, &QPushButton::clicked, this, &FirstWindow::openMainWindow);
    connect(outButton, &QPushButton::clicked, this, &FirstWindow::goOut);

    // Añadir los botones al layout horizontal
    buttonLayout->addWidget(continueButton);
    buttonLayout->addWidget(outButton);
    layout->addLayout(buttonLayout);
}

void FirstWindow::openMainWindow() {
    // Crear la ventana principal
    MainWindow *mainWindow = new MainWindow();
    mainWindow->showMaximized();

    // Cerrar la ventana actual
    this->close();
}

void FirstWindow::goOut() {
    QApplication::quit();
}

#include "intro.moc"