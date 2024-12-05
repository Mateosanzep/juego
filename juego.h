#ifndef JUEGO_H
#define JUEGO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <vector>
#include <string>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    
private slots:
    void onButton1Click();
    void onButton2Click();
    void onButton3Click();
    void onOptionButtonClick(int option);
    void actualizarPreguntas();
    void reiniciarTemporizador();

private:
    int ronda;
    std::string respuestaCorrecta;
    QLabel *premio;
    QLabel *money[15];
    QLabel *labelPregunta;
    QLabel *labelPregunta2;
    QLabel *labelTiempo;
    QPushButton *button4, *button5, *button6, *button7;
    QTimer *timer; // Temporizador
    int tiempoRestante; // Tiempo restante
    bool dialogOpened = false;
};

#endif // JUEGO_H
