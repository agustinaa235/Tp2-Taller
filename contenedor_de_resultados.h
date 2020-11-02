#ifndef CONTENEDOR_RESULTADOS_H
#define CONTENEDOR_RESULTADOS_H

#include <string>
#include <vector>
#include <mutex>


class Contenedor_Resultados{
      public:
            Contenedor_Resultados();
            ~Contenedor_Resultados();
            void cargar_resultados(const std::string& nombre,
                                   const int& resultado);
            void imprimir_resultados();
      private:
              std::vector<std::string> resultados;
              std::mutex mutex;
};

#endif
