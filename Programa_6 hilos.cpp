#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <string>

// Función que consume la CPU (antes era cpu_waster)
void cpu_waster() {
    while (true) {
        // Bucle infinito que consume CPU
    }
}

// Función que solicita dos números y los suma
void calculadora() {
    int num1, num2;
    std::cout << "Introduce el primer número: ";
    std::cin >> num1;
    std::cout << "Introduce el segundo número: ";
    std::cin >> num2;
    std::cout << "La suma de " << num1 << " y " << num2 << " es: " << num1 + num2 << std::endl;
}

// Función que ejecuta un comando del sistema para obtener información
void obtener_info_sistema(const std::string& comando) {
    std::cout << "Ejecutando comando: " << comando << std::endl;
    system(comando.c_str()); // Ejecutar el comando
}

void mostrar_menu() {
    std::cout << "\nSeleccione una opción:\n";
    std::cout << "1. Ver cuántos procesos y hilos está utilizando mi aplicación\n";
    std::cout << "2. Ver cuántos procesos y hilos está utilizando el sistema operativo\n";
    std::cout << "3. Ver cuántos procesos y hilos está utilizando Microsoft Office\n";
    std::cout << "4. Ver cuántos procesos y hilos está utilizando un juego específico\n";
    std::cout << "5. Cambiar la función cpu_waster a una calculadora que suma 2 números\n";
    std::cout << "6. Salir\n";
}

int main() {
    int opcion;
    bool cambiar_funcion = false;  // Variable para saber si cambiar la función cpu_waster

    while (true) {
        mostrar_menu();
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            // Opción 1: Ver los procesos y hilos de la aplicación
            std::cout << "\nVerificando los procesos y hilos de la aplicación...\n";
            // Comando para ver los procesos
            #ifdef _WIN32
            obtener_info_sistema("tasklist");
            #else
          
            obtener_info_sistema("ps aux --threads");
            #endif
        }
        else if (opcion == 2) {
            // Opción 2: Ver los procesos y hilos del sistema operativo
            std::cout << "\nVerificando los procesos y hilos del sistema operativo...\n";
            // Comando para obtener información sobre los procesos del sistema
            #ifdef _WIN32
            obtener_info_sistema("tasklist");
            #else
            obtener_info_sistema("ps aux --threads");
            #endif
        }
        else if (opcion == 3) {
            // Opción 3: Ver los procesos y hilos de Microsoft Office
            std::cout << "Verificando los procesos y hilos de Microsoft Office...\n";
            #ifdef _WIN32
            obtener_info_sistema("tasklist | findstr /i \"Word\"");
            obtener_info_sistema("tasklist | findstr /i \"Excel\"");
            #else
            obtener_info_sistema("ps aux | grep -i office");
            #endif
        }
        else if (opcion == 4) {
            // Opción 4: Ver los procesos y hilos de un juego específico
            std::string nombre_app;
            std::cout << "Ingrese el nombre del juego (por ejemplo, 'Juego.exe'): ";
            std::cin.ignore();  // Limpiar el buffer
            std::getline(std::cin, nombre_app);

            std::string comando;
            #ifdef _WIN32
            comando = "tasklist | findstr /i \"" + nombre_app + "\"";
            #else
            comando = "ps aux | grep " + nombre_app;
            #endif
            obtener_info_sistema(comando);
        }
        else if (opcion == 5) {
            // Opción 5: Cambiar la función cpu_waster a una calculadora
            std::cout << "\nCambiar la función cpu_waster a una calculadora que suma dos números...\n";
            cambiar_funcion = true;  // Activamos el cambio a la función calculadora
            std::vector<std::thread> threads;
            
            // Crear 6 hilos que ejecutan la calculadora
            for (int i = 0; i < 6; ++i) {
                threads.push_back(std::thread(calculadora));
            }

            // Esperar a que todos los hilos terminen
            for (auto& t : threads) {
                t.join();
            }
        }
        else if (opcion == 6) {
            // Opción 6: Salir
            std::cout << "Saliendo...\n";
            break;
        }
        else {
            std::cout << "Opción no válida, intente nuevamente.\n";
        }

        // Si hemos cambiado la función a la calculadora, significa que los hilos ya no están haciendo CPU-wasting.
        if (cambiar_funcion) {
            std::cout << "\nLos hilos ahora ejecutan una calculadora que suma dos números. El uso de CPU ha disminuido significativamente.\n";
        }
    }

    return 0;
}

