#include "verificador.h"
#define HAY_CICLO 1
#define INSTRUCCIONES_SIN_USAR 2
#define GOOD 3

Verificador::Verificador(Grafo* grafo){
    this->grafo = grafo;
}
Verificador::~Verificador(){}

bool Verificador::verificar_ciclo(){
    return this->grafo->dfs();
}
bool Verificador::verificar_instrucciones_sin_usar(){
    return this->grafo->nodos_sin_visitar();
}

int Verificador::verificar_bpf(){
    if (verificar_ciclo()){
        return HAY_CICLO;
    } else if (verificar_instrucciones_sin_usar()){
        return INSTRUCCIONES_SIN_USAR;
    } else {
        return GOOD;
    }
}
