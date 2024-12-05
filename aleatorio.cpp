#include <iostream>
#include <random>
#include <vector>

int generarNumeroAleatorioConPesos(int numeroConMayorPeso) {
    // Vector de números posibles
    std::vector<int> numeros = {0, 1, 2, 3};

    // Pesos base para cada número
    std::vector<int> pesos = {1, 1, 1, 1};

    // Aumentamos el peso del número deseado
    if (numeroConMayorPeso >= 0 && numeroConMayorPeso <= 3) {
        pesos[numeroConMayorPeso] = 5; // Este número tiene más probabilidad
    }

    // Crear una distribución discreta basada en los pesos
    std::random_device rd; // Generador de números aleatorios
    std::mt19937 gen(rd()); // Motor de aleatoriedad
    std::discrete_distribution<> distribucion(pesos.begin(), pesos.end());

    // Generar el número aleatorio
    return numeros[distribucion(gen)];
}

int main() {
    int numeroConMayorPeso;
    std::cout << "Introduce el número que tendrá mayor peso (0-3): ";
    std::cin >> numeroConMayorPeso;

    for (int i = 0; i < 15; i++)
    {
        int numeroAleatorio = generarNumeroAleatorioConPesos(numeroConMayorPeso);
        std::cout << "Número aleatorio generado: " << numeroAleatorio << std::endl;
    }
    

    // Generamos el número aleatorio con la distribución de pesos
    

    return 0;
}
