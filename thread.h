#ifndef THREAD_H
#define THREAD_H
#include "contenedor_de_archivos.h"
#include "contenedor_de_resultados.h"
#include <thread>

class Thread {
    public:
        Thread(Contenedor_Archivos* contenedor_archivos,
                Contenedor_Resultados* contenedor_resultados);
        void start();
        void join();
        void run();
        ~Thread();
        Thread(const Thread&) = delete;
        Thread(Thread&& otroThread);

    private:
          Contenedor_Archivos* contenedor_archivos;
          Contenedor_Resultados* contenedor_resultados;
          std::thread thread;
};

#endif
