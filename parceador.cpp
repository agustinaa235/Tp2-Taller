#include "parceador.h"
#include <iostream>
#define EXITO 0;

Parceador::Parceador(const std::string nombre_archivo){
    this->archivo.open(nombre_archivo);
    if (!this->archivo.is_open()){
       std::cout << "No se pudo abrir el archivo \n";
    }
    this->instrucciones = std::vector<Instruccion>();
}

Parceador::~Parceador(){
    if (this->archivo.is_open()){
        this->archivo.close();
    }
}
/*
bool instruccion_contiene_etiqueta(const std::string instruccion, const std::string etiqueta){
    return instruccion.find(etiqueta)>-1?true:false;
}

bool instruccion_contiene_una_coma(const std::string instruccion){
      int cant_de_comas = 0;
      for (int i = 0; i<instruccion.size(); i++){
          if (instruccion[i] == ','){
              cant_de_comas++;
          }
      }
      return (cant_de_comas==1?true:false);
}

bool instruccion_es_un_ret(const std::string instruccion){
    std::string ret = "ret";
    return instruccion.find(ret)>-1?true:false;
}

bool es_salto(const std::string instruccion){
    bool es_salto = false;
    int i=0;
    std::vector<std::string> saltos = {"jmp", "ja", "jeq", "jneq", "jlt",
                                        "jge", "jgt", "jle", "jne", "jset"};
    while (i<saltos.size() && !es_salto){
        es_salto = saltos[i].find(instruccion)>-1?true:false;
        i++;
    }
    return es_salto;
}
/*
void Parceador::inicializar_grafo(Grafo grafo){
    std::string formatoDosPuntos(":");
    std::string instruccion;
    for (int i=0; i<this->instrucciones.size(); i++){
        //instruccion = this->instrucciones[i];
        size_t pos = instrucciones[i].find(formatoDosPuntos);
        std::cout << "pos:" << ' ' << pos <<"\n";
        if (pos > - 1){ // es etiqueta

            std::string etiqueta = instrucciones[i].substr(0, pos);
            std::string instruccion_etiqueta = instrucciones[i].substr(pos, instruccion.size());
            std::cout << "soy etiqueta" << ' ' << etiqueta << ' ' << instruccion_etiqueta << "\n";
            for (int j = 0; j<instrucciones.size(); j++){
                if (instruccion_contiene_etiqueta(instrucciones[j], etiqueta)){
                    grafo.agregar_arista(instruccion, instruccion_etiqueta);
                }
            }

        } else if (es_salto(instruccion)){
              if(instruccion_contiene_una_coma(instruccion)){
                  grafo.agregar_arista(instruccion, this->instrucciones[i+1]);
              } else {
                  grafo.agregar_nodo(instruccion);
              }
        } else if (instruccion_es_un_ret(instruccion)){
              grafo.agregar_nodo(instruccion);
              std::cout << "soy intruccio de return " << ' ' << instruccion << "\n";
        } else{
              grafo.agregar_nodo(instruccion);
              grafo.agregar_arista(instruccion, this->instrucciones[i+1]);
              std::cout << "soy clasica" << ' ' << instruccion << "\n";
        }
    }

}
*/
void Parceador::inicializar_grafo(Grafo &grafo){
    for(int i=0; i<instrucciones.size(); i++){
        if(i != (instrucciones.size() -1)){
        this->instrucciones[i].agregarse_al_grafo(grafo,
                                                  this->instrucciones[i+1],
                                                  this->instrucciones);
        std::cout << "agrego al grafo" << instrucciones[i].get_informacion() << "\n";                                          
        }
    }
}
Instruccion crearInstruccion(const std::string data){
    int pos = -1;
    std::string formatoDosPuntos(":");
    pos = data.find(formatoDosPuntos);
    //std::cout << "posicon de dos puntos:" << ' ' << pos << "\n";
    if(pos > -1){
        return Instruccion(data, true);
    } else {
        return Instruccion(data, false);
    }
}

int Parceador::parcear_archivo(Grafo& grafo){
    std::string data = "";

    while (getline(this->archivo ,data, '\n')){
        if(data.size() != 0){
          Instruccion instruccion = crearInstruccion(data);
          this->instrucciones.push_back(instruccion);
          grafo.agregar_nodo(instruccion.get_informacion());
          std::cout << "lo que imprime:" << ' ' << instruccion.get_informacion() << "\n";
        }

    }
    inicializar_grafo(grafo);
/*
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
    }*/
    return EXITO;
}
