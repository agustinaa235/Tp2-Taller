#ifndef VECTOR_PROTEGIDO
#define VECTOR_PROTEGIDO

#include <mutex>
#include <string>
#include <vector>
class Vector_Protegido{
      public: /*
                * Inicializara al vector portegido dejandolo valido para uso
              */
              Vector_Protegido();
              /*
                * liberara al vector protegido con sus recursos
              */
              ~Vector_Protegido();
              Vector_Protegido(const Vector_Protegido& otroVector);
              /*
                * se encarga de cargar el resultado que le llega por
                * parametro si este es valido
              */
              void cargar_resultados_si_son_validos(std::string& resultado);
              /*
                * se encarga de imprimir todos los resultados que tiene
                * en el vector
              */  
              void imprimir_resultados();
      private:
              std::vector<std::string> resultados;
              std::mutex mutex;
};

#endif
