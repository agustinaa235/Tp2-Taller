#ifndef CONTENEDOR_ARCHIVOS_H
#define CONTENEDOR_ARCHIVOS_H
#include <string>
#include <queue>
#include "cola_protegida.h"

class Contenedor_Archivos{
    public:
          Contenedor_Archivos(ColaProtegida* cola, char** &argv, int &argc);
          ~Contenedor_Archivos();
          void agregar_archivos();
          bool esta_vacio();
          std::string dar_archivo();
    private:
          ColaProtegida* cola_protegida;
          char** argv;
          int argc;
};

#endif
