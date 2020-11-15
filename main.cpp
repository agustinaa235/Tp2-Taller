#include <iostream>
#include <vector>
#include <thread>
#include "cola_protegida.h"
#include "vector_protegido.h"
#include "thread.h"
#include "contenedor_de_archivos.h"
#include "contenedor_de_resultados.h"
#include "procesador_bpf.h"
#define EXITO 0
#define ERROR 1
#define TAMANIO_MAX 50
#define CANTIDAD_MINIMA_ARGUMENTOS 3
#define ERROR_CANT_MINIMA "Ingreso erroneo de cant de argumentos"

int main(int argc, char** argv){
    if (argc < CANTIDAD_MINIMA_ARGUMENTOS){
        std::cout << ERROR_CANT_MINIMA << "\n";
        return 0;
    }
    int cant_de_hilos = atoi(argv[1]);
    std::vector<Procesador_Bpf*> threads;
    Contenedor_Resultados contenedor_resultado = Contenedor_Resultados();
    Contenedor_Archivos contenedor_archivos = Contenedor_Archivos(argv,argc);
    contenedor_archivos.agregar_archivos();
    for (int i = 0; i < cant_de_hilos; i++) {
        threads.push_back(new Procesador_Bpf(contenedor_archivos,
                                             contenedor_resultado));
    }
    for (int i = 0; i<cant_de_hilos; i++){
        threads[i]->start();
    }
    for (int i = 0; i<cant_de_hilos; i++){
          threads[i]->join();
          delete threads[i];
    }
    contenedor_resultado.imprimir_resultados();
    return 0;
}
