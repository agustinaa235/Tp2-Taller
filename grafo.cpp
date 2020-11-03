#include "grafo.h"
#include <stack>



Grafo::Grafo(){
    this->nodos =std::vector<Nodo>();
}
Grafo::~Grafo(){}

void Grafo::agregar_nodo(const std::string& informacion){
      int orden = this->nodos.size();
      Nodo nodo(informacion, orden);
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
