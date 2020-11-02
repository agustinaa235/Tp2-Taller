#ifndef VERIFICADOR_H
#define VERIFICADOR_H
#include "grafo.h"

class Verificador{
      public:
            explicit Verificador(Grafo* grafo);
            ~Verificador();
            bool verificar_ciclo();
            bool verificar_instrucciones_sin_usar();
            int verificar_bpf();
      private:
            Grafo* grafo;
};

#endif
