#include <iostream>
#include <thread>  // Necesario para std::thread
#include <chrono>  // Necesario para std::chrono

// Función para imprimir "Hola" infinitamente
void saludar_hola() {
    while (true) {
        std::cout << "Hola" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  
    }
}

// Función para imprimir "Adiós" infinitamente
void saludar_adios() {
    while (true) {
        std::cout << "Adiós" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  
    }
}

int main() {
    // Creamos los hilos para "Hola" y "Adiós"
    std::thread hilo_hola(saludar_hola);
    std::thread hilo_adios(saludar_adios);

    // El hilo principal imprimirá "Saludo infinito" de manera continua
    while (true) {
        std::cout << "Saludo infinito" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pausa 
    }

    // Join de los hilos 
    hilo_hola.join();
    hilo_adios.join();

    return 0;
}

