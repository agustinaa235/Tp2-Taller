#include "parceador.h"
#include <iostream>
#define EXITO 0;
#define ERROR_ARCHIVO "No se pudo abrir el archivo"

Parceador::Parceador(const std::string& nombre_archivo){
    this->archivo.open(nombre_archivo);
    if (!this->archivo.is_open()){
       std::cout << "ERROR_ARCHIVO \n";
    }
    this->instrucciones = std::vector<Instruccion>();
}

Parceador::~Parceador(){
    if (this->archivo.is_open()){
        this->archivo.close();
    }
}
void Parceador::relacionar_instrucciones_con_grafo(Grafo& grafo){
    int cant_instrucciones = this->instrucciones.size();
    for (int i=0; i<cant_instrucciones; i++){
        this->instrucciones[i].relacionarse_al_grafo(grafo,i,
                                                     this->instrucciones);
    }
}
Instruccion crearInstruccion(const std::string& data){
    int pos = -1;
    std::string formatoDosPuntos(":");
    pos = data.find(formatoDosPuntos);
    if (pos > -1){
        return Instruccion(data, true);
    } else {
        return Instruccion(data, false);
    }
}

int Parceador::parcear_archivo(Grafo& grafo){
    std::string data = "";
    while (getline(this->archivo ,data, '\n')){
        if (data.size() != 0){
          Instruccion instruccion = crearInstruccion(data);
          this->instrucciones.push_back(instruccion);
          grafo.agregar_nodo(instruccion.get_informacion());
        }
    }
    relacionar_instrucciones_con_grafo(grafo);
    return EXITO;
}
