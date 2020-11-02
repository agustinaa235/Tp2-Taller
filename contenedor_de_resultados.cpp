#include "contenedor_de_resultados.h"
#include "lock.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define HAY_CICLO 1
#define INSTRUCCIONES_SIN_USAR 2
#define GOOD 3

Contenedor_Resultados::Contenedor_Resultados(){
      this->resultados = std::vector<std::string>();
}
Contenedor_Resultados::~Contenedor_Resultados(){}

bool comparacion(const std::string& variable1, const std::string& variable2){
      return (variable1 < variable2);
}
std::string verificar_resultado(const int& resultado){
    std::string respuesta;
    if (resultado == HAY_CICLO){
        respuesta = "FAIL: cycle detected";
    } else if (resultado == INSTRUCCIONES_SIN_USAR){
        respuesta = "FAIL: unused instructions detected";
    } else {
        respuesta = "GOOD";
    }
    return respuesta;
}

void Contenedor_Resultados::cargar_resultados(const std::string& nombre,
                                                const int& resultado){
    Lock lock(this->mutex);
    if (nombre != "" && (resultado == HAY_CICLO || resultado == GOOD
        || resultado == INSTRUCCIONES_SIN_USAR)){
        std::string resultados =  nombre + ' ' +
                                  verificar_resultado(resultado);
        this->resultados.push_back(resultados);
        std::sort(this->resultados.begin(), this->resultados.end(),comparacion);
    }
}

void Contenedor_Resultados::imprimir_resultados(){
      int cant_resultados = this->resultados.size();
      for (int i = 0 ; i<cant_resultados; i++){
            std::cout << this->resultados[i] << "\n";
      }
}
