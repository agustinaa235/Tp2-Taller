#ifndef PROCESADOR_BPF
#define PROCESADOR_BPF

#include "thread.h"
#include "contenedor_de_archivos.h"
#include "contenedor_de_resultados.h"

class Procesador_Bpf : public Thread {
    public:
          /*
            * creara al procesador dejandolo valido para uso
          */
          Procesador_Bpf(Contenedor_Archivos& archivos,
                          Contenedor_Resultados& resultados);
          /*
            * liberara al procesador con sus recursos
          */
          ~Procesador_Bpf();
          /*
            * correra el progarama para determinar como se encuentra un
            * programa bpf
          */  
          void run() override;

    private:
          Contenedor_Archivos& contenedor_archivos;
          Contenedor_Resultados& contenedor_resultados;
};

#endif
