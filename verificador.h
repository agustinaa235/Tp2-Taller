#ifndef VERIFICADOR_H
#define VERIFICADOR_H
#include "grafo.h"

class Verificador{
      public:
            /*
              * inicializara al verificador dejandolo valido
            */
            explicit Verificador(Grafo* grafo);
            /*
              * liberara al verificador junto a sus recursos
            */
            ~Verificador();
            /*
              * devuelve true si pudo decetetar un ciclo sino false
            */
            bool verificar_ciclo();
            /*
              * devuelve true si detecta instrucciones sin usar sino false
            */
            bool verificar_instrucciones_sin_usar();
            /*
              * devuelve 1 si se detecto un ciclo, 2 si hay instrucciones
              * sin usar o 3 si el programa esta bien
            */
            int verificar_bpf();
      private:
            Grafo* grafo;
};

#endif
