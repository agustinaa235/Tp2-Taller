#include "instruccion.h"
#include <vector>
#include <iostream>

Instruccion::Instruccion(const std::string& data, const bool& etiqueta){
    this->informacion = data;
    this->etiqueta = etiqueta;
}
Instruccion::Instruccion(const Instruccion& instruccion){
    this->informacion = instruccion.informacion;
    this->etiqueta = instruccion.etiqueta;
}

Instruccion::~Instruccion(){}

std::string Instruccion::get_informacion(){
    return this->informacion;
}
bool Instruccion::es_ret(){
    const std::string ret = "ret";
    int pos = this->informacion.find(ret);
    return (pos>-1?true:false);
}

bool Instruccion::es_salto(){
    bool es_salto = false;
    int i = 0;
    std::vector<std::string> saltos = {"jmp", "ja", "jeq", "jneq", "jlt",
                                        "jge", "jgt", "jle", "jne", "jset"};
    int cant_saltos = saltos.size();
    while (i<cant_saltos && !es_salto){
        int pos = this->informacion.find(saltos[i]);
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
      int tamanio_instruccion = this->informacion.size();
      for (int i = 0; i<tamanio_instruccion; i++){
          if (this->informacion[i] == ','){
              cant_de_comas++;
          }
      }
      return (cant_de_comas==1?true:false);
}
bool Instruccion::contiene_etiqueta(const std::string& instruccion,
                                    const std::string& etiqueta) const{
    int pos = instruccion.find(etiqueta);
    return (pos>-1?true:false);
}

bool Instruccion::etiqueta_con_salto(const std::string& instruccion,
                                     const std::string& etiqueta) const{
    int pos = instruccion.find(etiqueta);
    if (pos == -1){
        return false;
    }
    const std::string etiqueta1 = instruccion.substr(pos, instruccion.size()-1);
    const std::string etiqueta2 = etiqueta + ',';
    int pos2 = instruccion.find(etiqueta2);
    return (etiqueta == etiqueta1 || pos2 > -1);
}

void Instruccion::relacionar_instrucciones_con_etiqueta(Grafo& grafo,
                                        std::vector<Instruccion>& instrucciones,
                                        const int& pos_instruccion){
    const std::string formatoDosPuntos(":");
    int pos = this->informacion.find(formatoDosPuntos);
    int cant_instrucciones = instrucciones.size();
    if (pos > - 1){
      std::string etiqueta = this->informacion.substr(0, pos);
      for (int i = 0; i<cant_instrucciones; i++){
          if (contiene_etiqueta(instrucciones[i].get_informacion(), etiqueta)
              && i!=pos_instruccion && instrucciones[i].es_salto() &&
               etiqueta_con_salto(instrucciones[i].get_informacion(),etiqueta)){
                    grafo.agregar_arista(i, pos_instruccion);
          }
      }
    }
    if (pos_instruccion < cant_instrucciones - 1){
        grafo.agregar_arista(pos_instruccion, pos_instruccion + 1);
    }
}

void Instruccion::relacionarse_al_grafo(Grafo& grafo,
                                      const int& pos_instruccion,
                                      std::vector<Instruccion>& instrucciones){
    int cant_instrucciones = instrucciones.size();
    if (this->es_comun() && pos_instruccion < cant_instrucciones -1){
        grafo.agregar_arista(pos_instruccion, pos_instruccion + 1);
    } else if (this->es_salto() && this->instruccion_contiene_una_coma() &&
                pos_instruccion < cant_instrucciones -1){
        grafo.agregar_arista(pos_instruccion, pos_instruccion + 1);
    }
    if (this->etiqueta){
        this->relacionar_instrucciones_con_etiqueta(grafo, instrucciones,
                                                    pos_instruccion);
    }
}
