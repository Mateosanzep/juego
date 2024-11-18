#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <vector>

using namespace std;


struct Question {
    string questionText;  
    string options[4];    
    int correctAnswerIndex;   
};

vector<Question> getQuestions();  
Question getQuestion(int index);       

#endif
