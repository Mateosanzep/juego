#include "juego.h"
#include <QMessageBox>
#include <QHBoxLayout>
#include <QFrame>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QPalette>
#include <QDebug>
#include <QDialog>
#include "constantes.h"
#include "config.h"
#include "questions.h"
#include "game.h"
#include "tiempo.h"
#include "mal.h"
#include "intro.h"
#include "ganaste.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    // Crear la ventana principal
    setWindowTitle("Millonario");
    setStyleSheet("background-color: #003E97; margin: 0px;");
    ronda = 0;
    std::string respuestaCorrecta;

    // Crear el layout principal en forma de grid
    QGridLayout *gridLayout = new QGridLayout;

    // Primera fila completa: Texto "Millonario"
    QLabel *titleLabel = new QLabel("Millonario");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 30px; font-weight: bold; background-color: #000074; color: white; min-height: 50px; min-width: 100%;");
    gridLayout->addWidget(titleLabel, 0, 0, 1, 2); // Ocupa 1 fila y 2 columnas

    // Segunda parte: Centro (2/3 de la ventana)
    QFrame *mainArea = new QFrame;
    mainArea->setStyleSheet("background-color: #003E97;");
    gridLayout->addWidget(mainArea, 1, 0); // Ocupa la parte izquierda (2/3)

    // Crear un layout vertical dentro de la parte izquierda
    QVBoxLayout *leftLayout = new QVBoxLayout;

    // Primer nivel: Tres botones en una fila horizontal
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    button1 = new QPushButton(this);
    button2 = new QPushButton(this);
    button3 = new QPushButton(this);
    button1->setText(QString("Publico"));
    button2->setText(QString("Llamada"));
    button3->setText(QString("50:50"));
    // Diseño redondo para los botones
    button1->setStyleSheet("border-radius: 25px; background-color: #FFCE29; color: #000000; font-weight: bold; font-size: 18px; width: 50px; height: 50px; margin: 20px;");
    button2->setStyleSheet("border-radius: 25px; background-color: #FFCE29; color: #000000; font-weight: bold; font-size: 18px; width: 50px; height: 50px; margin: 20px;");
    button3->setStyleSheet("border-radius: 25px; background-color: #FFCE29; color: #000000; font-weight: bold; font-size: 18px; width: 50px; height: 50px; margin: 20px;");

    // Conectar los botones a sus slots
    connect(button1, &QPushButton::clicked, this, &MainWindow::onButton1Click);
    connect(button2, &QPushButton::clicked, this, &MainWindow::onButton2Click);
    connect(button3, &QPushButton::clicked, this, &MainWindow::onButton3Click);

    // Añadir los botones al layout horizontal
    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    buttonLayout->addWidget(button3);
    leftLayout->addLayout(buttonLayout);

    // Segundo nivel: Texto "Pregunta 1"
    labelPregunta = new QLabel(this);
    labelPregunta->setAlignment(Qt::AlignCenter);
    labelPregunta->setStyleSheet("font-size: 25px; font-weight: bold; color: white;");
    labelPregunta->setMargin(0);
    leftLayout->addWidget(labelPregunta);

    // Temporizador
    tiempoRestante = TIEMPO_LIMITE; // Inicializar con 30 segundos
    timer = new QTimer(this);

    // Segunda parte: Centro (2/3 de la ventana)
    labelTiempo = new QLabel(this);
    labelTiempo->setAlignment(Qt::AlignCenter);
    labelTiempo->setStyleSheet("font-size: 25px; font-weight: bold; color: white; "
                               "background-color: #E00000; min-width: 120px; min-height: 45px; "
                               "border-radius: 22px;");

    // Usar un QHBoxLayout para centrar el QLabel
    QHBoxLayout *hLayoutTiempo = new QHBoxLayout();
    hLayoutTiempo->addWidget(labelTiempo);
    hLayoutTiempo->setAlignment(Qt::AlignCenter);  // Centra el widget dentro del layout

    leftLayout->addLayout(hLayoutTiempo);

    connect(timer, &QTimer::timeout, this, [=]() {
        tiempoRestante--;
        labelTiempo->setText(QString::number(tiempoRestante) + " s");
        if (tiempoRestante <= 0) {
            timer->stop();
            // Crear la nueva ventana
            TiempoWindow *tiempowindow = new TiempoWindow();
            tiempowindow->showMaximized();
            // Cerrar la ventana actual
            this->close();
        }
    });

    timer->start(1000);

    labelPregunta2 = new QLabel(this);
    labelPregunta2->setAlignment(Qt::AlignCenter);
    labelPregunta2->setStyleSheet("font-size: 25px; font-weight: bold; max-width: 900px; min-width: 650px; min-height: 45px; border-radius: 22px; color: white; background-color: #502993; border: 2px solid white;");
    labelPregunta2->setWordWrap(true);
    QHBoxLayout *hLayoutPregunta = new QHBoxLayout();
    hLayoutPregunta->addWidget(labelPregunta2);
    hLayoutPregunta->setAlignment(Qt::AlignCenter);  // Centra el widget dentro del layout

    leftLayout->addLayout(hLayoutPregunta);

    // Quinto nivel: Grilla 2x2 con 4 botones
    QGridLayout *gridLayout2x2 = new QGridLayout;

    button4 = new QPushButton(this);
    button5 = new QPushButton(this);
    button6 = new QPushButton(this);
    button7 = new QPushButton(this);

    // Diseño redondo para los botones de la grilla 2x2
    button4->setStyleSheet("font-size: 25px; font-weight: bold; border-radius: 50px; background-color: #8C65CF; border: 2px solid white; color: white; width: 100px; height: 100px; margin: 20px;");
    button5->setStyleSheet("font-size: 25px; font-weight: bold; border-radius: 50px; background-color: #8C65CF; border: 2px solid white; color: white; width: 100px; height: 100px; margin: 20px;");
    button6->setStyleSheet("font-size: 25px; font-weight: bold; border-radius: 50px; background-color: #8C65CF; border: 2px solid white; color: white; width: 100px; height: 100px; margin: 20px;");
    button7->setStyleSheet("font-size: 25px; font-weight: bold; border-radius: 50px; background-color: #8C65CF; border: 2px solid white; color: white; width: 100px; height: 100px; margin: 20px;");

    // Conectar los botones de la grilla
    connect(button4, &QPushButton::clicked, this, [=]() { onOptionButtonClick(0); });
    connect(button5, &QPushButton::clicked, this, [=]() { onOptionButtonClick(1); });
    connect(button6, &QPushButton::clicked, this, [=]() { onOptionButtonClick(2); });
    connect(button7, &QPushButton::clicked, this, [=]() { onOptionButtonClick(3); });

    // Añadir los botones al layout de la grilla 2x2
    gridLayout2x2->addWidget(button4, 0, 0); // Fila 0, Columna 0
    gridLayout2x2->addWidget(button5, 0, 1); // Fila 0, Columna 1
    gridLayout2x2->addWidget(button6, 1, 0); // Fila 1, Columna 0
    gridLayout2x2->addWidget(button7, 1, 1); // Fila 1, Columna 1

    // Añadir la grilla 2x2 al layout principal
    leftLayout->addLayout(gridLayout2x2);

    // Asignar el layout vertical a la parte izquierda
    mainArea->setLayout(leftLayout);

    // Tercera parte: Lado derecho (1/3 de la ventana)
    QFrame *sideArea = new QFrame;
    sideArea->setStyleSheet("background-color: #3357FF;");
    gridLayout->addWidget(sideArea, 1, 1); // Ocupa la parte derecha (1/3)

    // Crear un layout vertical para los 15 QLabels en la parte derecha
    QVBoxLayout *rightLayout = new QVBoxLayout;
    premio = new QLabel("Premio");
    premio->setAlignment(Qt::AlignCenter);
    premio->setStyleSheet("font-size: 23px; margin: 2px; color: black; background-color: #FFCE29; border-radius: 5px; max-width: 400px; min-width: 200px; min-height: 40px; font-weight: bold;");
    QHBoxLayout *hLayoutPremio = new QHBoxLayout();
    hLayoutPremio->addWidget(premio);
    hLayoutPremio->setAlignment(Qt::AlignCenter);  // Centra el widget dentro del layout

    rightLayout->addLayout(hLayoutPremio);
    for (int i = 14; i >= 0; --i) {
        money[i] = new QLabel(QString::fromStdString(dinero[i]));
        money[i]->setAlignment(Qt::AlignCenter);
        money[i]->setStyleSheet("font-size: 20px; font-weight: bold; color: white;");
        int width = 200 - (14 - i) * 10; // Aumentar el ancho a medida que subimos en la pirámide
            money[i]->setMinimumWidth(width);
            QHBoxLayout *hLayout = new QHBoxLayout();
            hLayout->addWidget(money[i]);
            hLayout->setAlignment(Qt::AlignCenter);
        
            rightLayout->addLayout(hLayout);
        }
    

    // Asignar el layout vertical a la parte derecha
    sideArea->setLayout(rightLayout);
    gridLayout->setColumnStretch(0, 2); // 2/3 para la columna izquierda
    gridLayout->setColumnStretch(1, 1); // 1/3 para la columna derecha
    gridLayout->setRowStretch(1, 1);
    // Asignar el layout principal
    setLayout(gridLayout);

    // Inicializar la pregunta y las opciones
    actualizarPreguntas();
}

#include "juego.h"
#include <QMessageBox>
#include <QDebug>

void MainWindow::onButton1Click() {
    if (dialogOpened) {
        // Si ya se abrió, no hacer nada
        return;
    }

    // Marcar que el diálogo ya se abrió
    dialogOpened = true;
    button1->setStyleSheet("border-radius: 25px; background-color: #EC2300; color: #000000; font-weight: bold; font-size: 18px; width: 50px; height: 50px; margin: 20px;");

    // Crear un diálogo no modal
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Público");
    dialog->setAttribute(Qt::WA_DeleteOnClose); // Asegura que se elimine automáticamente al cerrarlo

    int correcta = indiceCorrecto(ronda);
    vector<int> contador(4, 0);
    for (int i = 0; i < 30; i++) {
        int numeroAleatorio = generarOpcionAleatoria(correcta);
        contador[numeroAleatorio]++;
    }
    vector<string> opcionesPregunta = Opciones(ronda);

    // Crear un layout para el contenido del diálogo
    QVBoxLayout *layout = new QVBoxLayout(dialog);

    // Agregar un texto al diálogo
    QLabel *label = new QLabel("¡El público te ayudará, pero no te dejes llevar!", dialog);
    label->setStyleSheet("font-size: 30px; font-weight: bold; color: white; margin: 10px;");
    layout->addWidget(label);
    for (int i = 0; i < 4; i++) {
        string numeroString = to_string(contador[i]);
        string opcionVariable = opcionesPregunta[i];
        string labelCorrecta = numeroString + " Personas votaron por: " + opcionVariable;
        QLabel *labelPersonas = new QLabel(QString::fromStdString(labelCorrecta), dialog);
        labelPersonas->setStyleSheet("font-size: 20px; font-weight: bold; color: white; margin: 10px;");
        layout->addWidget(labelPersonas);
        // std::cout << "Número " << i << ": " << contador[i] << " veces\n";
    }

    // Crear un botón para cerrar el diálogo
    QPushButton *closeButton = new QPushButton("Cerrar", dialog);
    closeButton->setStyleSheet("border-radius: 25px; background-color: #26B12C; color: #FFF; font-weight: bold; font-size: 18px; min-width: 100px; height: 50px; margin: 20px;");
    layout->addWidget(closeButton);

    // Conectar el botón para cerrar el diálogo
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::close);

    // Mostrar el diálogo de forma no modal
    dialog->show();
}


void MainWindow::onButton2Click() {
    if (cambioRespuesta) {
        // Si ya se abrió, no hacer nada
        return;
    }
    button2->setStyleSheet("border-radius: 25px; background-color: #EC2300; color: #000000; font-weight: bold; font-size: 18px; width: 50px; height: 50px; margin: 20px;");

    // Marcar que el diálogo ya se abrió
    cambioRespuesta = true;
    
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Llamada");
    dialog->setAttribute(Qt::WA_DeleteOnClose); // Asegura que se elimine automáticamente al cerrarlo

    // Crear un layout para el contenido del diálogo
    QVBoxLayout *layout = new QVBoxLayout(dialog);

    // Agregar un texto al diálogo
    QLabel *label = new QLabel("Llamando a un experto...", dialog);
    label->setStyleSheet("font-size: 30px; font-weight: bold; color: white; margin: 10px;");
    layout->addWidget(label);

    string respuesta = imprimirCorrecta(ronda);
    
    string labelRespuesta = "...mmm, bueno, es una pregunta dificil, pero creo que es: " + respuesta + ", ojala este bien, suerte, bye";
    QLabel *labelLlamada = new QLabel(QString::fromStdString(labelRespuesta), dialog);
    labelLlamada->setStyleSheet("font-size: 20px; font-weight: bold; color: white; margin: 10px;");
    layout->addWidget(labelLlamada);

    // Crear un botón para cerrar el diálogo
    QPushButton *closeButton = new QPushButton("Cerrar", dialog);
    closeButton->setStyleSheet("border-radius: 25px; background-color: #26B12C; color: #FFF; font-weight: bold; font-size: 18px; min-width: 100px; height: 50px; margin: 20px;");
    layout->addWidget(closeButton);

    // Conectar el botón para cerrar el diálogo
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::close);

    // Mostrar el diálogo de forma no modal
    dialog->show();

    
}

void MainWindow::onButton3Click() { // 50:50
if (quitarRespuestas) {
        // Si ya se abrió, no hacer nada
        return;
    }
    button3->setStyleSheet("border-radius: 25px; background-color: #EC2300; color: #000000; font-weight: bold; font-size: 18px; width: 50px; height: 50px; margin: 20px;");

    // Marcar que el diálogo ya se abrió
    quitarRespuestas = true;
    int respuesta = indiceCorrecto(ronda);
    if (respuesta == 2 || respuesta == 3){
            button4 -> hide();
            button5 -> hide();
        }
    else if (respuesta == 0|| respuesta == 1){
        button7 -> hide();
        button6 -> hide();
    }
}

void MainWindow::onOptionButtonClick(int option) {
    // Lógica cuando el jugador selecciona una opción en los botones de respuestas
    bool isCorrect = selectedOption(ronda, option); // Verifica si la opción seleccionada es correcta

    if (isCorrect) {
        ronda++; // Incrementar la ronda
        if (ronda < TOTAL_RONDAS) {
            reiniciarTemporizador(); // Reiniciar el temporizador
            actualizarPreguntas(); // Actualizar las preguntas para la siguiente ronda
        } else {
            GanasteWindow *ganastewindow = new GanasteWindow();
            this->close();
            ganastewindow->showMaximized();
        }
    } else {
        MalWindow *malwindow = new MalWindow(ronda);
        this->close();
            malwindow->showMaximized();
            // Cerrar la ventana actual
            
    }
}

void MainWindow::actualizarPreguntas() {
    // Actualizar la pregunta y las opciones según la ronda actual
    labelPregunta->setText(QString::fromStdString(preguntas[ronda])); // Establecer el texto de la pregunta
    labelPregunta2->setText(QString::fromStdString(Pregunta(ronda))); // Establecer el texto de la pregunta secundaria


    // Obtener las opciones de la pregunta actual
    vector<string> opcionesPregunta = Opciones(ronda);

    button4->show();
    button5->show();
    button6->show();
    button7->show();

    // Asignar las opciones a los botones
    button4->setText(QString::fromStdString(opcionesPregunta[0]));
    button5->setText(QString::fromStdString(opcionesPregunta[1]));
    button6->setText(QString::fromStdString(opcionesPregunta[2]));
    button7->setText(QString::fromStdString(opcionesPregunta[3]));

    // Actualizar la interfaz de los premios
    for (int i = 0; i < 15; ++i) {
        if (i < ronda) {
            money[i]->setStyleSheet("font-size: 18px; margin: 1px; color: white; background-color: #26B12C; border-radius: 5px; min-height: 30px;"); 
            int width = 200 - (14 - i) * 10; // Aumentar el ancho a medida que subimos en la pirámide
            money[i]->setMinimumWidth(width); // Cambiar color de fondo si la ronda ya fue superada
        } else if (i == ronda) {
            money[i]->setStyleSheet("font-size: 18px; margin: 1px; color: white; background-color: #FF7429; border-radius: 5px; min-height: 30px;");
            int width = 200 - (14 - i) * 10; // Aumentar el ancho a medida que subimos en la pirámide
            money[i]->setMinimumWidth(width); // Resaltar el premio de la ronda actual
        } else {
            money[i]->setStyleSheet("font-size: 18px; margin: 1px; color: white; background-color: #65C0FF; border-radius: 5px; min-height: 30px;");
            int width = 200 - (14 - i) * 10; // Ajustar ancho para las rondas por venir
            money[i]->setMinimumWidth(width); // Color original
        }
    }
}

void MainWindow::reiniciarTemporizador() {
    // Reiniciar el temporizador a su valor inicial
    tiempoRestante = TIEMPO_LIMITE; // Reestablecer el tiempo a 30 segundos
    labelTiempo->setText(QString::number(tiempoRestante) + " s"); // Actualizar la etiqueta con el tiempo restante
    timer->start(1000); // Iniciar el temporizador nuevamente
}

#include "juego.moc"