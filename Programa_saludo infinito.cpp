#include <iostream>
#include <thread>  // Necesario para std::thread
#include <chrono>  // Necesario para std::chrono

// Funci�n para imprimir "Hola" infinitamente
void saludar_hola() {
    while (true) {
        std::cout << "Hola" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pausa para ver mejor la intercalaci�n
    }
}

// Funci�n para imprimir "Adi�s" infinitamente
void saludar_adios() {
    while (true) {
        std::cout << "Adi�s" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pausa para ver mejor la intercalaci�n
    }
}

int main() {
    // Creamos los hilos para "Hola" y "Adi�s"
    std::thread hilo_hola(saludar_hola);
    std::thread hilo_adios(saludar_adios);

    // El hilo principal imprimir� "Saludo infinito" de manera continua
    while (true) {
        std::cout << "Saludo infinito" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pausa para ver mejor la intercalaci�n
    }

    // Join de los hilos (en este caso, nunca se ejecutar� debido al while infinito en main)
    hilo_hola.join();
    hilo_adios.join();

    return 0;
}

