#include "cola_protegida.h"
#include "lock.h"

ColaProtegida::ColaProtegida(){
    this->cola_de_archivos = std::queue<std::string>();
}
ColaProtegida::~ColaProtegida(){}

ColaProtegida::ColaProtegida(const ColaProtegida& otraCola){
    this->cola_de_archivos = otraCola.cola_de_archivos;
}

void ColaProtegida::cargar_nombre_archivo(std::string nombre_archivo){
    this->cola_de_archivos.push(nombre_archivo);
}
bool ColaProtegida::esta_vacia(){
    return this->cola_de_archivos.empty();
}
std::string ColaProtegida::dar_archivo_si_cola_no_esta_vacia(){
    Lock lock(this->mutex);
    std::string nombre("");
    if (!this->cola_de_archivos.empty()){
        nombre =  cola_de_archivos.front();
        cola_de_archivos.pop();
        return nombre;
    }
    return nombre;
}
