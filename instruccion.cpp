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
bool Instruccion::es_salto(){
    bool es_salto = false;
    int i=0;
    int pos = -1;
    std::vector<std::string> saltos = {"jmp", "ja", "jeq", "jneq", "jlt",
                                        "jge", "jgt", "jle", "jne", "jset"};

    while (i<saltos.size() && !es_salto){
        pos = this->informacion.find(saltos[i]);
        if (pos > -1){
            //std::cout << "entre" << "\n";
            es_salto = true;
          }
        //es_salto = saltos[i].find(this->informacion)>-1?true:false;
        i++;
    }
    //std::cout << "salto:" << ' ' << es_salto << "\n";
    return es_salto;
}
bool Instruccion::es_ret(){
    std::string ret = "ret";
    int pos = -1;
    pos = this->informacion.find(ret);
    return (pos>-1?true:false);
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
bool Instruccion::instruccion_contiene_etiqueta(const std::string instruccion,
                                  const std::string etiqueta){
    return instruccion.find(etiqueta)>-1?true:false;
}

void Instruccion::agregarse_al_grafo(Grafo &grafo, Instruccion siguienteInstruccion, std::vector<Instruccion> instrucciones){
      std::cout << "tipo:" << ' ' << this->etiqueta << "\n";
      if(this->etiqueta){
        for (int j = 0; j<instrucciones.size(); j++){
            std::cout << "soy etiqueta" <<' ' << this->informacion << "\n";
            if (instruccion_contiene_etiqueta(instrucciones[j].get_informacion(), this->informacion)){
                grafo.agregar_arista(instrucciones[j].get_informacion(), this->informacion);
            }
        }
      } else {
          if(this->es_salto() && this->instruccion_contiene_una_coma()){
              grafo.agregar_arista(this->informacion, siguienteInstruccion.get_informacion());
              std::cout << "soy salto con una coma" << ' ' << this->informacion << "\n";
          } else if (this->es_ret()){
              std::cout << " soy ret" << ' ' << this->informacion << "\n";
          } else {
            grafo.agregar_arista(this->informacion, siguienteInstruccion.get_informacion());
            std::cout << "soy clasica" << ' ' << this->informacion << "\n";
          }

      }
}
