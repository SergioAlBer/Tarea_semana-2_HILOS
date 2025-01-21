#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <string>

// Funci�n que consume la CPU (antes era cpu_waster)
void cpu_waster() {
    while (true) {
        // Bucle infinito que consume CPU
    }
}

// Funci�n que solicita dos n�meros y los suma
void calculadora() {
    int num1, num2;
    std::cout << "Introduce el primer n�mero: ";
    std::cin >> num1;
    std::cout << "Introduce el segundo n�mero: ";
    std::cin >> num2;
    std::cout << "La suma de " << num1 << " y " << num2 << " es: " << num1 + num2 << std::endl;
}

// Funci�n que ejecuta un comando del sistema para obtener informaci�n
void obtener_info_sistema(const std::string& comando) {
    std::cout << "Ejecutando comando: " << comando << std::endl;
    system(comando.c_str()); // Ejecutar el comando
}

void mostrar_menu() {
    std::cout << "\nSeleccione una opci�n:\n";
    std::cout << "1. Ver cu�ntos procesos y hilos est� utilizando mi aplicaci�n\n";
    std::cout << "2. Ver cu�ntos procesos y hilos est� utilizando el sistema operativo\n";
    std::cout << "3. Ver cu�ntos procesos y hilos est� utilizando Microsoft Office\n";
    std::cout << "4. Ver cu�ntos procesos y hilos est� utilizando un juego espec�fico\n";
    std::cout << "5. Cambiar la funci�n cpu_waster a una calculadora que suma 2 n�meros\n";
    std::cout << "6. Salir\n";
}

int main() {
    int opcion;
    bool cambiar_funcion = false;  // Variable para saber si cambiar la funci�n cpu_waster

    while (true) {
        mostrar_menu();
        std::cout << "Ingrese una opci�n: ";
        std::cin >> opcion;

        if (opcion == 1) {
            // Opci�n 1: Ver los procesos y hilos de la aplicaci�n
            std::cout << "\nVerificando los procesos y hilos de la aplicaci�n...\n";
            // Comando para ver los procesos
            #ifdef _WIN32
            obtener_info_sistema("tasklist");
            #else
          
            obtener_info_sistema("ps aux --threads");
            #endif
        }
        else if (opcion == 2) {
            // Opci�n 2: Ver los procesos y hilos del sistema operativo
            std::cout << "\nVerificando los procesos y hilos del sistema operativo...\n";
            // Comando para obtener informaci�n sobre los procesos del sistema
            #ifdef _WIN32
            obtener_info_sistema("tasklist");
            #else
            obtener_info_sistema("ps aux --threads");
            #endif
        }
        else if (opcion == 3) {
            // Opci�n 3: Ver los procesos y hilos de Microsoft Office
            std::cout << "Verificando los procesos y hilos de Microsoft Office...\n";
            #ifdef _WIN32
            obtener_info_sistema("tasklist | findstr /i \"Word\"");
            obtener_info_sistema("tasklist | findstr /i \"Excel\"");
            #else
            obtener_info_sistema("ps aux | grep -i office");
            #endif
        }
        else if (opcion == 4) {
            // Opci�n 4: Ver los procesos y hilos de un juego espec�fico
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
            // Opci�n 5: Cambiar la funci�n cpu_waster a una calculadora
            std::cout << "\nCambiar la funci�n cpu_waster a una calculadora que suma dos n�meros...\n";
            cambiar_funcion = true;  // Activamos el cambio a la funci�n calculadora
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
            // Opci�n 6: Salir
            std::cout << "Saliendo...\n";
            break;
        }
        else {
            std::cout << "Opci�n no v�lida, intente nuevamente.\n";
        }

        // Si hemos cambiado la funci�n a la calculadora, significa que los hilos ya no est�n haciendo CPU-wasting.
        if (cambiar_funcion) {
            std::cout << "\nLos hilos ahora ejecutan una calculadora que suma dos n�meros. El uso de CPU ha disminuido significativamente.\n";
        }
    }

    return 0;
}

