#include "nodo.h"

Nodo::Nodo(const std::string& informacion, const int& orden){
    this->informacion = informacion;
    this->vecinos = std::vector<Nodo*>();
    this->visitado = false;
    this->orden_agregado = orden;
}
Nodo::~Nodo(){}

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
