#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "questions.h"

using namespace std;

// Declaración de la clase Game
class Game {
public:
    Game();
    void run();
private:
    bool sigueJugando;
    void mostrarRonda(int ronda, const Question& question);
    void temporizador();
    void validarRespuesta(const string& respuesta, const Question& question, int ronda);
    void reiniciarJuego();
};

#endif // GAME_H
