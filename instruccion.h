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
          void agregarse_al_grafo(Grafo &grafo, int pos_instruccion, std::vector<Instruccion> instrucciones);
          bool es_ret();
          bool contiene_etiqueta(const std::string instruccion,
                                             const std::string etiqueta);
          bool etiqueta_con_salto(std::string instruccion, std::string etiqueta);
          bool instruccion_contiene_una_coma();
          bool es_salto();
          bool es_comun();
          std::string get_informacion();
          void relacionar_instrucciones_con_etiqueta(Grafo& grafo, std::vector<Instruccion> instrucciones, int pos_instruccion);
    private:
          std::string informacion;
          bool etiqueta;

};

#endif
