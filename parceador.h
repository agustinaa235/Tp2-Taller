#ifndef PARCEADOR_H
#define PARCEADOR_H


#include <fstream>
#include <string>
#include <vector>
#include "grafo.h"
#include "instruccion.h"

class Parceador{
      public: /*
                * inicializara al parceador dejandolo valido para uso
              */
              explicit Parceador(const std::string& nombre_archivo);
              /*
                * liberara al parceador junto a sus recursos
              */
              ~Parceador();
              /*
                * se encargara de leer el archivo creando una instruccion y
                * agregando al grafo su informacion
              */
              int parcear_archivo(Grafo& grafo);
              /*
                * relacionara cada instruccion con su correspondiente arista
              */
              void relacionar_instrucciones_con_grafo(Grafo& grafo);
      private:
              std::ifstream archivo;
              std::vector<Instruccion> instrucciones;
};

#endif
