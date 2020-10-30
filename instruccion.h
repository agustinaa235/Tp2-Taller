#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include "grafo.h"
#include <string>
#include <vector>

class Instruccion{
    public:
          Instruccion(const std::string data,const bool etiqueta);
          Instruccion(const Instruccion& instruccion);
          ~Instruccion();
          void agregarse_al_grafo(Grafo &grafo, Instruccion sigueinteInstruccion, std::vector<Instruccion> instrucciones);
          bool es_ret();
          bool instruccion_contiene_etiqueta(const std::string instruccion,
                                             const std::string etiqueta);
          bool instruccion_contiene_una_coma();
          bool es_salto();
          std::string get_informacion();
    private:
          std::string informacion;
          bool etiqueta;

};

#endif
