#include <QApplication>
#include <QScreen>
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include "constantes.h"
#include "config.h"
#include "questions.h"
#include "game.h"
#include "juego.h"


class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // Crear la ventana principal
        setWindowTitle("Millonario");
        
        ronda = 0;

        // Crear el layout principal en forma de grid
        QGridLayout *gridLayout = new QGridLayout;

        // Primera fila completa: Texto "Millonario"
        QLabel *titleLabel = new QLabel("Millonario");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet("font-size: 30px; font-weight: bold; background-color: #FF5733; color: white;");
        gridLayout->addWidget(titleLabel, 0, 0, 1, 2); // Ocupa 1 fila y 2 columnas

        // Segunda parte: Centro (2/3 de la ventana)
        QFrame *mainArea = new QFrame;
        mainArea->setStyleSheet("background-color: #33FF57; border: 1px solid #ccc;");
        gridLayout->addWidget(mainArea, 1, 0); // Ocupa la parte izquierda (2/3)

        // Crear un layout vertical dentro de la parte izquierda
        QVBoxLayout *leftLayout = new QVBoxLayout;

        // Primer nivel: Tres botones en una fila horizontal
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        QPushButton *button1 = new QPushButton("Publico");
        QPushButton *button2 = new QPushButton("Llamada");
        QPushButton *button3 = new QPushButton("50:50");

        // Diseño redondo para los botones
        button1->setStyleSheet("border-radius: 25px; background-color: #FF5733; color: white; width: 50px; height: 50px; margin: 20px;");
        button2->setStyleSheet("border-radius: 25px; background-color: #33FF57; color: white; width: 50px; height: 50px; margin: 20px;");
        button3->setStyleSheet("border-radius: 25px; background-color: #3357FF; color: white; width: 50px; height: 50px; margin: 20px;");

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
        QLabel *labelPregunta = new QLabel("Pregunta 1");
        labelPregunta->setAlignment(Qt::AlignCenter);
        labelPregunta->setStyleSheet("font-size: 25px;");
        labelPregunta->setMargin(0);
        leftLayout->addWidget(labelPregunta);

       // Temporizador
        tiempoRestante = TIEMPO_LIMITE; // Inicializar con 30 segundos
        timer = new QTimer(this);

        // Segunda parte: Centro (2/3 de la ventana)
        labelTiempo = new QLabel(this);
        labelTiempo->setAlignment(Qt::AlignCenter);
        labelTiempo->setStyleSheet("font-size: 18px; font-weight: bold;");
        leftLayout->addWidget(labelTiempo);

        connect(timer, &QTimer::timeout, this, [=]() {
            tiempoRestante--;
            labelTiempo->setText(QString::number(tiempoRestante) + " s");
            if (tiempoRestante <= 0) {
                timer->stop();
                QMessageBox::information(this, "Fin del Tiempo", "¡Se acabó el tiempo!");
            }
        });

        timer->start(1000);

        labelPregunta2 = new QLabel(this);
        labelPregunta2->setAlignment(Qt::AlignCenter);
        labelPregunta2->setStyleSheet("font-size: 25px; font-weight: bold; max-width: 900px");
        labelPregunta2->setWordWrap(true);
        leftLayout->addWidget(labelPregunta2);

        // Quinto nivel: Grilla 2x2 con 4 botones
        QGridLayout *gridLayout2x2 = new QGridLayout;
        
        button4 = new QPushButton(this);
        button5 = new QPushButton(this);
        button6 = new QPushButton(this);
        button7 = new QPushButton(this);


        // Diseño redondo para los botones de la grilla 2x2
        button4->setStyleSheet("font-size: 20px; font-weight: bold; border-radius: 50px; background-color: #FF5733; color: white; width: 100px; height: 100px; margin: 20px;");
        button5->setStyleSheet("font-size: 20px; font-weight: bold; border-radius: 50px; background-color: #33FF57; color: white; width: 100px; height: 100px; margin: 20px;");
        button6->setStyleSheet("font-size: 20px; font-weight: bold; border-radius: 50px; background-color: #3357FF; color: white; width: 100px; height: 100px; margin: 20px;");
        button7->setStyleSheet("font-size: 20px; font-weight: bold; border-radius: 50px; background-color: #FF8C00; color: white; width: 100px; height: 100px; margin: 20px;");

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
        sideArea->setStyleSheet("background-color: #3357FF; border: 1px solid #aaa;");
        gridLayout->addWidget(sideArea, 1, 1); // Ocupa la parte derecha (1/3)

        // Crear un layout vertical para los 15 QLabels en la parte derecha
        QVBoxLayout *rightLayout = new QVBoxLayout;

        
        // Crear 15 QLabel con el texto "$100"
        for (int i = 14; i >= 0; --i) {
            QLabel *label = new QLabel(QString::number(dinero[i]));
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("font-size: 18px; margin: 10px; color: white; background-color: #4CAF50; border-radius: 5px;");
            rightLayout->addWidget(label);
            }


        // Asignar el layout a la parte derecha
        sideArea->setLayout(rightLayout);

        // Configuración de proporciones
        gridLayout->setColumnStretch(0, 2); // 2/3 para la columna izquierda
        gridLayout->setColumnStretch(1, 1); // 1/3 para la columna derecha
        gridLayout->setRowStretch(1, 1);    // Segunda fila se expande

        // Aplicar el layout a la ventana principal
        setLayout(gridLayout);
        actualizarPreguntas();
    }
private slots:
    void onButton1Click() {
        // Acción cuando se presiona el Botón 1
        QMessageBox::information(this, "Acción", "Botón 1 presionado");
    }

    void onButton2Click() {
        // Acción cuando se presiona el Botón 2
        QMessageBox::information(this, "Acción", "Botón 2 presionado");
    }

    void onButton3Click() {
        // Acción cuando se presiona el Botón 3
        QMessageBox::information(this, "Acción", "Botón 3 presionado");
    }

private:
    int ronda;
    QLabel *labelPregunta2;
    QLabel *labelTiempo;
    QPushButton *button4, *button5, *button6, *button7;
    QTimer *timer; // Temporizador
    int tiempoRestante; // Tiempo restante
private slots:
    void onOptionButtonClick(int option) {
        bool isCorrect = selectedOption(ronda, option); // Verifica si la opción es correcta

        if (isCorrect) {
            ronda++; // Incrementar la ronda
            if (ronda < TOTAL_RONDAS) {
                reiniciarTemporizador();
                actualizarPreguntas(); // Actualizar las preguntas
            }else{
                QMessageBox::information(this, "Fin del juego", "¡Felicidades! Has completado");
            }
            } else{
                QMessageBox::information(this, "Error", "La opción seleccionada es incorrecta");
            }
    }
    void actualizarPreguntas() {
        labelPregunta2->setText(QString::fromStdString(Pregunta(ronda)));
        vector<string> opcionesPregunta = Opciones(ronda);
        button4->setText(QString::fromStdString(opcionesPregunta[0]));
        button5->setText(QString::fromStdString(opcionesPregunta[1]));
        button6->setText(QString::fromStdString(opcionesPregunta[2]));
        button7->setText(QString::fromStdString(opcionesPregunta[3]));
    }
    void reiniciarTemporizador() {
        tiempoRestante = TIEMPO_LIMITE; // Reiniciar el tiempo a 30 segundos
        labelTiempo->setText(QString::number(tiempoRestante) + " s");
        timer->start(1000); // Reiniciar el temporizador
    }
    };



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;


        window.showMaximized();
        return app.exec();
    
}
#include "juego.moc"