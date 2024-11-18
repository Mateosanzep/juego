#include "game.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include "constantes.h"
#include "config.h"
#include "utils.h"

using namespace std;

Game::Game() : sigueJugando(true) {}

void Game::run() {
    do {
        srand(time(NULL));
        int orden[TOTAL_RONDAS];
        for (int i = 0; i < TOTAL_RONDAS; i++) {
            orden[i] = niveles[i][random()];
        }

        for (int j = 0; j < TOTAL_RONDAS; j++) {
            vector<Question> questions = getQuestions();
            int questionIndex = orden[j] - 1; 
            Question question = getQuestion(questionIndex);

            // Temporizador
            string respuesta = ""; 
            bool enterPresionado = false;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
            SetConsoleOutputCP(65001); 
            SetConsoleCP(65001);

            limpiarPantalla(hConsole);
            mostrarRonda(j + 1, question);

            auto inicio = chrono::steady_clock::now();
            int tiempo_restante = TIEMPO_LIMITE;

            while (tiempo_restante > 0 && !enterPresionado) {
                if (_kbhit()) {
                    char tecla = _getch();
                    if (tecla == '\r') {
                        enterPresionado = true;
                    } else if (tecla == '\b') {
                        if (!respuesta.empty()) {
                            respuesta.pop_back();
                        }
                    } else {
                        respuesta += tecla;
                    }
                }

                auto ahora = chrono::steady_clock::now();
                int tiempo_transcurrido = chrono::duration_cast<chrono::seconds>(ahora - inicio).count();
                tiempo_restante = TIEMPO_LIMITE - tiempo_transcurrido;

                if (tiempo_restante >= 0) {
                    moverCursor(hConsole, 0, 2);
                    cout << "Tiempo: " << tiempo_restante << "s" << flush;
                }

                moverCursor(hConsole, 0, 4);
                cout << question.questionText << endl;

                for (int i = 0; i < 4; ++i) {
                    cout << i + 1 << ". " << question.options[i] << endl;
                }

                moverCursor(hConsole, 0, 9);
                cout << "Ingresa el número de tu respuesta: " << respuesta << flush;

                this_thread::sleep_for(chrono::milliseconds(50));
            }

            // Validación de respuesta
            validarRespuesta(respuesta, question, j);

            // Si el jugador ha fallado y no desea reiniciar, termina el juego
            if (!sigueJugando) {
                break;
            }

            if (sigueJugando) {
                cout << "Presiona Enter para continuar a la siguiente ronda..." << endl;
                while (!_kbhit() || _getch() != '\r') {
                    this_thread::sleep_for(chrono::milliseconds(50));
                }
            }
        }
    } while (sigueJugando);

    cout << "Presiona Enter para salir..." << endl;
    while (!_kbhit() || _getch() != '\r') {
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

void Game::mostrarRonda(int ronda, const Question& question) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    moverCursor(hConsole, 0, 0);
    cout << "Ronda " << ronda << endl;
    cout << "Dinero a ganar: $" << dinero[ronda - 1] << endl;
}

void Game::validarRespuesta(const string& respuesta, const Question& question, int ronda) {
    int userAnswer;
    if (respuesta.empty()) {
        cout << "Tiempo agotado." << endl;
    } else {
        cout << endl;
        userAnswer = stoi(respuesta);
        if (userAnswer - 1 == question.correctAnswerIndex) {
            cout << "¡Correcto! Ganaste $" << dinero[ronda] << endl;
        } else {
            cout << "Incorrecto. La respuesta correcta era: " 
                 << question.options[question.correctAnswerIndex] << endl;
            reiniciarJuego();
        }
    }
}

void Game::reiniciarJuego() {
    cout << "¿Quieres reiniciar el juego? (s/n): ";
    char respuestaReiniciar;
    cin >> respuestaReiniciar;

    if (respuestaReiniciar == 'n' || respuestaReiniciar == 'N') {
        sigueJugando = false;
        cout << "¡Gracias por jugar! Fin del juego." << endl;
    } else if (respuestaReiniciar == 's' || respuestaReiniciar == 'S') {
        cout << "Reiniciando el juego..." << endl;
        sigueJugando = true;
    }
}
