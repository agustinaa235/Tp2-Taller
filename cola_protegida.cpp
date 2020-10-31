#include "cola_protegida.h"


ColaProtegida::(){

    this->cola = std::queque<string>();

}

void ColaProtegida::cargar_nombre_archivo(std::string nombre_archivo){
    this->cola.push(nombre_archivo);
}
void dar_archivo_si_cola_no_esta_vacia(){
    Lock(this->m);
    if(!this->cola.is_empty()){
        std::string nombre =  archivos.front());
        archivos.pop();
        return nombre;
    }
}
