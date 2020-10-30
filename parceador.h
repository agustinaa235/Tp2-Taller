#ifndef PARCEADOR_H
#define PARCEADOR_H


#include <fstream>
#include <string>
#include <vector>
#include "grafo.h"
#include "instruccion.h"

class Parceador{

    public:
          Parceador(const std::string nombre_archivo);
          ~Parceador();
          int parcear_archivo(Grafo& grafo);
          void inicializar_grafo(Grafo& grafo);
    private:
          std::ifstream archivo;
          std::vector<Instruccion> instrucciones;
};

#endif
