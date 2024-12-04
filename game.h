#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "constantes.h"
#include "config.h"
#include "questions.h"   // Asegúrate de definir las funciones getQuestions() y getQuestion() aquí

// Declaración de las funciones
std::vector<int> Orden();
std::string Pregunta(int index);
std::vector<std::string> Opciones(int in);
bool selectedOption(int inde, int option);



// Prototipos de las funciones para obtener preguntas (puedes adaptarlas según tu implementación)
std::vector<Question> getQuestions();
Question getQuestion(int index);

#endif // GAME_H
