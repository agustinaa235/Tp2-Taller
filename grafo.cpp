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
Grafo::~Grafo(){
    //delete(this->nodos);
}

Nodo::Nodo(const std::string informacion, int orden){
    this->informacion = informacion;
    this->vecinos = std::vector<Nodo*>();
    this->visitado = false;
    this->orden_agregado = orden;
}
Nodo::~Nodo(){

}
std::string Nodo::get_informacion(){
    return (this->informacion);
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
    std::cout << "\n";
}
int Nodo::es_igual_a(const std::string informacion) const{
    if(this->informacion == informacion || this->informacion.find(informacion) >-1){
        return 0;
    }
    return -1;
}
void Grafo::agregar_nodo(const std::string info){
      Nodo nodo(info, this->nodos.size());
      this->nodos.push_back(nodo);
}

int Grafo::buscar_nodo(const std::string informacion) const{
    int pos_nodo = -1;
    for (std::size_t i = 0; i < this->nodos.size(); i++){
        if(nodos[i].es_igual_a(informacion) == 0){
              pos_nodo = i;
        }
    }
    return pos_nodo;
}

void Grafo::agregar_arista(int pos1, int pos2){

    Nodo& nodo_apuntador = this->nodos[pos1];
    Nodo& nodo_apuntado = this->nodos[pos2];
    nodo_apuntador.agregar_vecino(nodo_apuntado);
}
bool Grafo::dfs(){
    bool hay_ciclo = false;
    Nodo* inicio = &(this->nodos[0]);
    std:: stack<Nodo*> dfsPila;
    dfsPila.push(inicio);
    while (!dfsPila.empty()){
        Nodo* nodo = dfsPila.top();
        dfsPila.pop();
        if(!nodo->fue_visitado()){
            nodo->visitar();
        }
        std::vector<Nodo*>& vecinos = nodo->get_vecinos();
        for (int i =0 ;i<vecinos.size(); i++){
            Nodo* nodo_vecino = vecinos[i];
            if (nodo->orden_de_agregado() > nodo_vecino->orden_de_agregado() && nodo_vecino->fue_visitado()){
                hay_ciclo = true;
            }
            if (!nodo_vecino->fue_visitado()){
                dfsPila.push(nodo_vecino);
            }
        }
    }
    return hay_ciclo;
}
