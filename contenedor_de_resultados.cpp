#include "contenedor_de_resultados.h"
#include "lock.h"
#define HAY_CICLO 1
#define INSTRUCCIONES_SIN_USAR 2
#define GOOD 3

Contenedor_Resultados::Contenedor_Resultados() :
      vector_de_resultados(){}

Contenedor_Resultados::~Contenedor_Resultados(){}

static std::string verificar_resultado(const int& resultado){
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
    if (nombre != "" && (resultado == HAY_CICLO || resultado == GOOD
        || resultado == INSTRUCCIONES_SIN_USAR)){
        std::string resultados =  nombre + ' ' +
                                  verificar_resultado(resultado);
        this->vector_de_resultados.cargar_resultados_si_son_validos(
                                                                    resultados);
    }
}

void Contenedor_Resultados::imprimir_resultados(){
      return this->vector_de_resultados.imprimir_resultados();
}
