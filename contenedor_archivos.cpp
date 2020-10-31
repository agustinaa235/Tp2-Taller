#include "Contenedor_Archivos.h"

Contenedor_Archivos() : public thread{
      ColaProtegida &cola;
}

void Contenedor_Archivos::agregar_archivos(const char* argv[], conts int argc){
    int cantidad_de_archivos = argc;
    int pos_argumento = 1;
    while (cantidad_de_archivos != 0){
        cola.cargar_nombre_archivo(argv[pos_argumento])
        cantidad_de_archivos -=1;
        posicion_argumento +=1;
    }
}

virtual void run() override {
    std::string archivo = cola_protegida.dar_archivo_si_cola_no_esta_vacia();
    Parceador parcer(archivo);
    Grafo grafo = Grafo();
    parcer.parcear_archivo(grafo);

    if (grafo.dfs()){
        std::cout << "FAIL" << "\n";
    } else {
        std::cout <<"GOOD" << "\n";
    }
}
