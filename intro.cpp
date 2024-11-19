#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Función para cambiar el color del texto
void setColor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    cout << "\033[" << color << "m";
#endif
}

// Restablecer el color
void resetColor() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    cout << "\033[0m";
#endif
}

// Función para mostrar texto ASCII con animación
void drawBigText(const vector<string> &bigText, int color, int delayMs) {
    setColor(color);
    for (const string &line : bigText) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    resetColor();
}

int main() {
    system("cls || clear"); // Limpia la pantalla

    // ASCII Art para "¿Quién?"
    vector<string> quienArt = {
        "   ######   ##      ##  ######  ##     ## ##    ##",
        "  ##    ##  ##  ##  ## ##    ## ##     ## ###   ##",
        "  ##        ##  ##  ## ##       ##     ## ####  ##",
        "  ##   #### ##  ##  ##  ######  ######### ## ## ##",
        "  ##    ##  ##  ##  ##       ## ##     ## ##  ####",
        "  ##    ##  ##  ##  ## ##    ## ##     ## ##   ###",
        "   ######    ###  ###   ######  ##     ## ##    ##"
    };

    // Mostrar "¿Quién?"
    drawBigText(quienArt, 33, 100);
    this_thread::sleep_for(chrono::seconds(1));
    system("cls || clear");

    // ASCII Art para "quiere ser"
    vector<string> quiereArt = {
        "  ##     ##  ##     ## #### ######## ########  ######## ",
        "  ##     ##  ##     ##  ##     ##    ##     ## ##       ",
        "  ##     ##  ##     ##  ##     ##    ##     ## ##       ",
        "  #########  ##     ##  ##     ##    ########  ######   ",
        "  ##     ##   ##   ##   ##     ##    ##   ##   ##       ",
        "  ##     ##    ## ##    ##     ##    ##    ##  ##       ",
        "  ##     ##     ###    ####    ##    ##     ## ######## "
    };

    // Mostrar "quiere ser"
    drawBigText(quiereArt, 32, 100);
    this_thread::sleep_for(chrono::seconds(1));
    system("cls || clear");

    // ASCII Art para "millonario"
    vector<string> millonarioArt = {
        "  ##     ## ##     ##  ######  ##       ##       ########  ######## ",
        "  ##     ## ##     ## ##    ## ##       ##       ##     ## ##       ",
        "  ##     ## ##     ## ##       ##       ##       ##     ## ##       ",
        "  ######### ##     ##  ######  ##       ##       ##     ## ######   ",
        "  ##     ## ##     ##       ## ##       ##       ##     ## ##       ",
        "  ##     ## ##     ## ##    ## ##       ##       ##     ## ##       ",
        "  ##     ##  #######   ######  ######## ######## ########  ######## "
    };

    // Mostrar "millonario"
    drawBigText(millonarioArt, 36, 100);
    this_thread::sleep_for(chrono::seconds(1));
    system("cls || clear");

    // ASCII Art para "¿Estás listo para el reto?"
    vector<string> listoArt = {
        " ########  ######## ##    ##  ######  #### ########  ########   ######  ",
        " ##     ## ##       ###   ## ##    ##  ##  ##     ## ##     ## ##    ## ",
        " ##     ## ##       ####  ## ##        ##  ##     ## ##     ## ##       ",
        " ########  ######   ## ## ## ##        ##  ##     ## ########   ######  ",
        " ##        ##       ##  #### ##        ##  ##     ## ##   ##         ## ",
        " ##        ##       ##   ### ##    ##  ##  ##     ## ##    ##  ##    ## ",
        " ##        ######## ##    ##  ######  #### ########  ##     ##  ######  "
    };

    // Mostrar "¿Estás listo para el reto?"
    drawBigText(listoArt, 35, 100);

    resetColor();
    return 0;
}
