#ifndef CONTENEDOR_RESULTADOS_H
#define CONTENEDOR_RESULTADOS_H

#include "vector_protegido.h"
#include <string>
#include <vector>

class Contenedor_Resultados{
      public:
            /*
              * Creara al contendor de resultados dejandolo valido
            */
            Contenedor_Resultados();
            /*
              * se encargara de destruir el objeto contendor de resultados
              * liberando los correspondientes recursos
            */
            ~Contenedor_Resultados();
            /*
              * se encargara de ir cargando los distintos resultados
            */
            void cargar_resultados(const std::string& nombre,
                                   const int& resultado);
            /*
              * imprimira los distintos resultados
            */
            void imprimir_resultados();
      private:
              Vector_Protegido vector_de_resultados;
};

#endif
