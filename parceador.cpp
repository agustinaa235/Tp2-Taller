#include "parceador.h"
#include <iostream>
#define EXITO 0;

Parceador::Parceador(const std::string nombre_archivo){
    this->archivo.open(nombre_archivo);
    if (!this->archivo.is_open()){
       std::cout << "No se pudo abrir el archivo \n";
    }
}

Parceador::~Parceador(){
    if (this->archivo.is_open()){
        this->archivo.close();
    }
}

int Parceador::parcear_archivo(){
    std::string instruccion;
    std::string etiqueta;
    std::string formatoDosPuntos(":");
    std::string ret = "ret";
    while (getline(this->archivo ,etiqueta, '\n')){
        size_t pos = etiqueta.find(formatoDosPuntos);
        if (pos > -1){ // soy una etiqueta y sigo
            std::cout << "soy etiqueta" << ' ' << etiqueta << ' ' << instruccion << "\n";
        } else {
            instruccion = etiqueta; // no encontre ningun :, soy una intrucccion;
            if(etiqueta.find(ret) != -1){
                std::cout << "soy intruccio de return " << ' ' << etiqueta << "\n";
            } else{
                std::cout << "soy otra intruccion" << ' ' << etiqueta << "\n";
            }
        }
    }
    return EXITO;
}
