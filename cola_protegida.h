#ifndef COLA_PROTEGIDA_H
#define COLA_PROTEGIDA_H

#include <mutex>
#include <queue>
#include <string>


class ColaProtegida {
      public: /*
                * creara la cola protegida dejandola valida
              */
              ColaProtegida();
              /*
                * se encargara de liberar a la cola con sus recursos
              */
              ~ColaProtegida();
              ColaProtegida(const ColaProtegida& otraCola);
              /*
                * devolvera el nombre del archivo si la cola no esta vacia y
                * sino un string inicializado con ""
              */
              std::string dar_archivo_si_cola_no_esta_vacia();
              /*
                * agregara el nombre de un archivo a la cola
              */
              void cargar_nombre_archivo(std::string nombre_archivo);
              /*
                * devuelve si true si la cola esta vacia, sino false
              */  
              bool esta_vacia();
      private:
          std::mutex mutex;
          std::queue<std::string> cola_de_archivos;
};

#endif
