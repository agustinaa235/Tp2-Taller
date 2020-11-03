#ifndef CONTENEDOR_ARCHIVOS_H
#define CONTENEDOR_ARCHIVOS_H
#include <string>
#include <queue>
#include "cola_protegida.h"

class Contenedor_Archivos{
      public:
              /*
                * inicializara al contenedor de archivos dejandolo valido
              */
              Contenedor_Archivos(ColaProtegida* cola, char** &argv, int &argc);
              /*
                * liberara al contenedor de archivos con sus recursos
              */
              ~Contenedor_Archivos();
              /*
                * agregara los archivos que llegan con terminar
              */
              void agregar_archivos();
              /*
                * devuelve true si el contendor esta vacio, sino false
              */
              bool esta_vacio();
              /*
                * devuelve un archivo que se encuentra en la cola de archivos
              */
              std::string dar_archivo();

      private:
            ColaProtegida* cola_protegida;
            char** argv;
            int argc;
};

#endif
