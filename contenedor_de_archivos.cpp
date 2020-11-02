#include "contenedor_de_archivos.h"

Contenedor_Archivos::Contenedor_Archivos(ColaProtegida* cola, char** &argv,
                                          int &argc){
      this->cola_protegida = cola;
      this->argv = argv;
      this->argc = argc;
}
Contenedor_Archivos::~Contenedor_Archivos(){}
void Contenedor_Archivos::agregar_archivos(){
    int pos_argumento = 2;
    while (this->argc != 2){
        this->cola_protegida->cargar_nombre_archivo(this->argv[pos_argumento]);
        this->argc -=1;
        pos_argumento +=1;
    }
}
bool Contenedor_Archivos::esta_vacio(){
    return this->cola_protegida->esta_vacia();
}
std::string Contenedor_Archivos::dar_archivo(){
    return cola_protegida->dar_archivo_si_cola_no_esta_vacia();
}
