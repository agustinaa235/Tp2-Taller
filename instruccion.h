#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include "grafo.h"
#include <string>
#include <vector>

class Instruccion{
      public:
              /*
                * inicializara a la instruccion dejandola valida para uso
              */
              Instruccion(const std::string& data,const bool& etiqueta);
              Instruccion(const Instruccion& instruccion);
              /*
                * liberara a la instruccion con sus recursos
              */
              ~Instruccion();
              /*
                * agregara las correspondientes aristas al grafo
              */
              void relacionarse_al_grafo(Grafo &grafo,
                                        const int& pos_instruccion,
                                      std::vector<Instruccion>& instrucciones);
              /*
                * devolvera la informacion de la instruccion
              */
              std::string get_informacion();
              /*
                * relacionara la instruccion etiqueta con las instrucciones
                * que corresponde agregandolas como aristas al grafo
              */
              void relacionar_instrucciones_con_etiqueta(Grafo& grafo,
                                                    std::vector<Instruccion>&
                                                    instrucciones,
                                                    const int& pos_instruccion);
                                                    
      private:
              std::string informacion;
              bool etiqueta;
              /*
                * devuelve true si la instruccion se trata de un ret sino false
              */
              bool es_ret();
              /*
                * devuelte true en caso de que la instruccion tenga a la
                * etiqueta sino devolvera false
              */
              bool contiene_etiqueta(const std::string& instruccion,
                                     const std::string& etiqueta);
              /*
                * devuelve true si la relacion es de una etiqueta con salto
                * especifico sino false
              */
              bool etiqueta_con_salto(std::string instruccion,
                                      std::string& etiqueta);
              /*
                * devuelve true si el salto se trata de un salto con coma
              */
              bool instruccion_contiene_una_coma();
              /*
                * devuelve true si se trata de un salto sino false
              */
              bool es_salto();
              /*
                * devuelve true si se trata de una instruccion comun sino false
              */
              bool es_comun();
};

#endif
