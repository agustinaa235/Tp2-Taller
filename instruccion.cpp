#include "instruccion.h"
#include <vector>
#include <iostream>

Instruccion::Instruccion(const std::string data, const bool etiqueta){
    this->informacion = data;
    this->etiqueta = etiqueta;
}
Instruccion::Instruccion(const Instruccion& instruccion){
    this->informacion = instruccion.informacion;
    this->etiqueta = instruccion.etiqueta;
}

Instruccion::~Instruccion(){

}
std::string Instruccion::get_informacion(){
    return this->informacion;
}
bool Instruccion::es_ret(){
    std::string ret = "ret";
    int pos = -1;
    pos = this->informacion.find(ret);
    return (pos>-1?true:false);
}

bool Instruccion::es_salto(){
    bool es_salto = false;
    int i=0;
    int pos = -1;
    std::vector<std::string> saltos = {"jmp", "ja", "jeq", "jneq", "jlt",
                                        "jge", "jgt", "jle", "jne", "jset"};
    while (i<saltos.size() && !es_salto){
        pos = this->informacion.find(saltos[i]);
        if (pos > -1){
            es_salto = true;
          }
        i++;
    }
    return es_salto;
}

bool Instruccion::es_comun(){
    return (!this->es_salto() && !this->es_ret() && !this->etiqueta);
}
bool Instruccion::instruccion_contiene_una_coma(){
      int cant_de_comas = 0;
      for (int i = 0; i<this->informacion.size(); i++){
          if (this->informacion[i] == ','){
              cant_de_comas++;
          }
      }
      return (cant_de_comas==1?true:false);
}
bool Instruccion::contiene_etiqueta(const std::string instruccion,
                                  const std::string etiqueta){
    int pos = -1;
    pos = instruccion.find(etiqueta);
    return (pos>-1?true:false);
}
/*
void Instruccion::agregarse_al_grafo(Grafo &grafo, int pos_siguienteInstruccion, std::vector<Instruccion> instrucciones){
      std::cout << "tipo:" << ' ' << this->etiqueta << "\n";
      if(this->etiqueta){
        std::cout << "soy etiqueta" <<' ' << this->informacion << "\n";
        for (int j = 0; j<instrucciones.size(); j++){

            if (instruccion_contiene_etiqueta(instrucciones[j].get_informacion(), this->informacion)){

                  grafo.agregar_arista(instrucciones[j].get_informacion(), this->informacion);
                  std::cout << ' ' << instrucciones[j].get_informacion() << "->"<< ' '<< this->informacion << "\n";
            }
        }
      } else {
          if(this->es_salto() && this->instruccion_contiene_una_coma()){
              grafo.agregar_arista(this->informacion, instrucciones[pos_siguienteInstruccion].get_informacion());
              std::cout << "soy salto con una coma" << ' ' << this->informacion << "\n";
          } else if (this->es_ret()){
              std::cout << " soy ret" << ' ' << this->informacion << "\n";
          } else {
            grafo.agregar_arista(this->informacion, instrucciones[pos_siguienteInstruccion].get_informacion());
            std::cout << "soy clasica" << ' ' << this->informacion << "\n";
          }

      }
}*/

bool Instruccion::etiqueta_con_salto(std::string instruccion, std::string etiqueta){
    int pos = instruccion.find(etiqueta);
    if (pos == -1){
        return false;
    }
    std::string etiqueta1 = instruccion.substr(pos, instruccion.size() -1);
    std::string etiqueta2 = etiqueta + ',';
    int pos2 = instruccion.find(etiqueta2);
    return (etiqueta == etiqueta1 || pos2 > -1);
}

void Instruccion::relacionar_instrucciones_con_etiqueta(Grafo& grafo, std::vector<Instruccion> instrucciones, int pos_instruccion){
    std::string formatoDosPuntos(":");
    int pos = this->informacion.find(formatoDosPuntos);
    if (pos > - 1){
      std::string etiqueta = this->informacion.substr(0, pos);
      for (int i = 0; i<instrucciones.size(); i++){
          if(contiene_etiqueta(instrucciones[i].get_informacion(), etiqueta)
            && i!=pos_instruccion && instrucciones[i].es_salto() && etiqueta_con_salto(instrucciones[i].get_informacion(), etiqueta)){
              grafo.agregar_arista(i, pos_instruccion);
              std::cout << ' ' << instrucciones[i].get_informacion() << "->"<< ' '<< this->informacion << "\n";
          }
      }
    }
    if(pos_instruccion < instrucciones.size() -1){
        grafo.agregar_arista(pos_instruccion, pos_instruccion + 1);
    }
}

void Instruccion::agregarse_al_grafo(Grafo& grafo, int pos_instruccion, std::vector<Instruccion> instrucciones){
    if (this->es_comun() && pos_instruccion < instrucciones.size() -1){
        std::cout << "soy clasica" << ' ' << this->informacion << "\n";
        grafo.agregar_arista(pos_instruccion, pos_instruccion + 1);
    } else if (this->es_salto() && this->instruccion_contiene_una_coma() && pos_instruccion < instrucciones.size() -1){
        std::cout << "soy salto con una coma" << ' ' << this->informacion << "\n";
        grafo.agregar_arista(pos_instruccion, pos_instruccion + 1);
    }
    if( this->etiqueta){
        std::cout << "soy etiqueta" <<' ' << this->informacion << "\n";
        this->relacionar_instrucciones_con_etiqueta(grafo, instrucciones, pos_instruccion);
    }
}
