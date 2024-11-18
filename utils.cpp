#include "utils.h"
#include <windows.h>
#include <cstdlib>

void moverCursor(HANDLE hConsole, int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
}

void limpiarPantalla(HANDLE hConsole) {
    system("cls");
}

int random() {
    return rand() % 10;
}