#ifndef CONTENEDOR_ARCHIVOS_H
#define CONTENEDOR_ARCHIVOS_H
#include <string>
#include <queque>

class Contenedor_Archivos{
    public:
          Contenedor_Archivos();
          ~Contenedor_Archivos();
          void agregarArchivos();
          std::string dar_archivo();
    private:
          std::queque<std::string>> archivos;

};

#endif
