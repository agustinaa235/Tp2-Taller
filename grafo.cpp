#include "grafo.h"
#include <vector>
#include <iostream>
//#include <string>
#include <stack>
#define BLANCO 0
#define GRIS 1
#define NEGRO 2
#define HAY_CICLO 1
#define NO_HAY_CICLO 0

Grafo::Grafo(){
    this->nodos =std::vector<Nodo>();
}
Grafo::~Grafo(){}

Nodo::Nodo(const std::string& informacion, const int& orden){
    this->informacion = informacion;
    this->vecinos = std::vector<Nodo*>();
    this->visitado = false;
    this->orden_agregado = orden;
}
Nodo::~Nodo(){}

std::string Nodo::get_informacion(){
    return this->informacion;
}
int Nodo::orden_de_agregado(){
    return this->orden_agregado;
}
bool Nodo::fue_visitado(){
    return this->visitado;
}
std::vector<Nodo*>& Nodo::get_vecinos(){
    return this->vecinos;
}

void Nodo::visitar(){
    this->visitado = true;
}

void Nodo::agregar_vecino(Nodo& nodovecino){
    this->vecinos.push_back(&nodovecino);
}

void Grafo::agregar_nodo(const std::string& info){
      int orden = this->nodos.size();
      Nodo nodo(info, orden);
      this->nodos.push_back(nodo);
}
void Grafo::agregar_arista(const int& pos1,const int& pos2){
    Nodo& nodo_apuntador = this->nodos[pos1];
    Nodo& nodo_apuntado = this->nodos[pos2];
    nodo_apuntador.agregar_vecino(nodo_apuntado);
}
bool Grafo::nodos_sin_visitar(){
    int cant_nodos = this->nodos.size();
    bool hay_nodos_sin_visitar = false;
    for (int i = 0; i< cant_nodos; i++){
        if (!nodos[i].fue_visitado()){
            hay_nodos_sin_visitar = true;
        }
    }
    return hay_nodos_sin_visitar;
}

bool Grafo::dfs(){
    bool hay_ciclo = false;
    Nodo* inicio = &(this->nodos[0]);
    std:: stack<Nodo*> dfsPila;
    dfsPila.push(inicio);
    int i=0;
    while (!dfsPila.empty()){
        Nodo* nodo = dfsPila.top();
        dfsPila.pop();
        if (!nodo->fue_visitado()){
            nodo->visitar();
        }
        std::vector<Nodo*>& vecinos = nodo->get_vecinos();
        int cant_vecinos = vecinos.size();
        for (int i =0 ; i<cant_vecinos; i++){
            if (nodo->orden_de_agregado() > vecinos[i]->orden_de_agregado()
                && vecinos[i]->fue_visitado()){
                hay_ciclo = true;
            }
            if (!vecinos[i]->fue_visitado()){
                dfsPila.push(vecinos[i]);
            }
        }
        i++;
    }
    return hay_ciclo;
}
