#include "vector_protegido.h"

#include "lock.h"
#include <algorithm>
#include <iostream>

Vector_Protegido::Vector_Protegido(){
      this->resultados = std::vector<std::string>();
}

Vector_Protegido::~Vector_Protegido(){}

Vector_Protegido::Vector_Protegido(const Vector_Protegido& otroVector){
    this->resultados = otroVector.resultados;
}
bool comparacion(const std::string& variable1, const std::string& variable2){
      return (variable1 < variable2);
}

void Vector_Protegido::cargar_resultados_si_son_validos(std::string& resultado){
    Lock lock(this->mutex);
    if(resultado != ""){
        this->resultados.push_back(resultado);
        std::sort(this->resultados.begin(), this->resultados.end(),comparacion);
    }
}

void Vector_Protegido::imprimir_resultados(){
    int cant_resultados = this->resultados.size();
    for (int i = 0 ; i<cant_resultados; i++){
          std::cout << this->resultados[i] << "\n";
    }
}
