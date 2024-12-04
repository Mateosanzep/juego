#include "game.h"
#include <chrono>
#include "constantes.h"
#include "config.h"
#include "questions.h"
#include "juego.h"
#include <QDebug>
#include <iostream>

using namespace std;

// Genera el orden una sola vez
vector<int> Orden() {
    srand(time(NULL));
    vector<int> orden(TOTAL_RONDAS);
    for (int i = 0; i < TOTAL_RONDAS; i++) {
        orden[i] = niveles[i][random()];  // Generación aleatoria (depende de cómo definas `niveles`)
    }
    return orden;
}

// Variable global que almacena el orden único
vector<int> ordenUnico = Orden();

string Pregunta(int index) {
    vector<Question> questions = getQuestions();  // Asumiendo que `getQuestions()` devuelve un vector de preguntas
    int questionIndex = ordenUnico[index] - 1;  // Obtener el índice de la pregunta
    Question question = getQuestion(questionIndex);  // Obtener la pregunta

    return question.questionText;  // Retorna el texto de la pregunta
}

vector<string> Opciones(int in) {
    vector<Question> questions = getQuestions();  // Obtener las preguntas disponibles
    int questionIndex = ordenUnico[in] - 1;  // Obtener el índice de la pregunta
    Question pregunta = getQuestion(questionIndex);  // Obtener la pregunta

    // Crear un vector con las opciones y retornarlo
    vector<string> opciones;
    for (int i = 0; i < 4; ++i) {
        opciones.push_back(pregunta.options[i]);  // Agregar cada opción al vector
    }

    return opciones;  // Retornar el vector con las opciones
}

bool selectedOption(int inde, int option) {
    vector<Question> questions = getQuestions();  // Obtener las preguntas disponibles
    int questionIndex = ordenUnico[inde] - 1;  // Obtener el índice de la pregunta
    Question pregunta = getQuestion(questionIndex);
    int respuestaCorrecta = pregunta.correctAnswerIndex;  // Obtener la respuesta correcta
    if (option == respuestaCorrecta) {
        return true;
    } else {
        return false;
    }
}
