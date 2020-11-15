#include "contenedor_de_archivos.h"
#include <string>

Contenedor_Archivos::Contenedor_Archivos(char** &argv, const int &argc) :
      cola_protegida(),
      argv(argv),
      argc(argc){}

Contenedor_Archivos::~Contenedor_Archivos(){}
void Contenedor_Archivos::agregar_archivos(){
    int pos_argumento = 2;
    while (this->argc != 2){
        std::string nombre(this->argv[pos_argumento]);
        this->cola_protegida.cargar_nombre_archivo(nombre);
        this->argc -=1;
        pos_argumento +=1;
    }
}
bool Contenedor_Archivos::esta_vacio(){
    return this->cola_protegida.esta_vacia();
}
std::string Contenedor_Archivos::dar_archivo(){
    return cola_protegida.dar_archivo_si_cola_no_esta_vacia();
}
