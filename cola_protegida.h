#ifndef COLA_PROTEGIDA_H
#define COLA_PROTEGIDA_H

#include <mutex>
#include <queue>
#include <string>


class ColaProtegida {
      public:
           ColaProtegida();
          ~ColaProtegida();
          ColaProtegida(const ColaProtegida& otraCola);
          std::string dar_archivo_si_cola_no_esta_vacia();
          void cargar_nombre_archivo(std::string nombre_archivo);
          bool esta_vacia();
      private:
          std::mutex mutex;
          std::queue<std::string> cola_de_archivos;
};

#endif
