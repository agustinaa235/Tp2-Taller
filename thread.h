#ifndef THREAD_H
#define THREAD_H
#include "contenedor_de_archivos.h"
#include "contenedor_de_resultados.h"
#include <thread>

class Thread {
      public:
              /*
                * creara al thread dejandolo valido para uso
              */
              Thread(Contenedor_Archivos* contenedor_archivos,
                      Contenedor_Resultados* contenedor_resultados);
              /*
                * se encargara de ir ejecutando el metodo run mientras se
                * tenga archivos para usar
              */
              void start();
              /*
                * Se encarga de ejecutar las correspondientes funciones para
                * verificar los programas bpf
              */
              void run();
              /*
                * Se encarga de liberar al thread con sus recursos
              */
              ~Thread();
              Thread(const Thread&) = delete;
              Thread(Thread&& otroThread);

      private:
              Contenedor_Archivos* contenedor_archivos;
              Contenedor_Resultados* contenedor_resultados;
              std::thread thread;
};

#endif
