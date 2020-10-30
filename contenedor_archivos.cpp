#include "Contenedor_Archivos.h"

Contenedor_Archivos(){
    this->archivos = std::queque<std::string>>();
}

void Contenedor_Archivos::agregar_archivos(const char* argv[], conts int argc){
    int cantidad_de_archivos = argc;
    int pos_argumento = 1;
    while (cantidad_de_archivos != 0){
        this->archivo.push(argv[pos_argumento])
        cantidad_de_archivos -=1;
        posicion_argumento +=1;
    }
}

std::string Contenedor_Archivos::dar_archivo(){
      std::string nombre =  archivos.front());
      archivos.pop();
      return nombre;
}
