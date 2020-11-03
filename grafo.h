#ifndef GRAFO_H
#define GRAFO_H

#include "nodo.h"
#include <vector>
#include <string>


class Grafo{
      public:
              /*
                * creara al grafo dejandolo valido
              */
              Grafo();
              /*
                * destruira al grafo con todos sus recursos
              */
              ~Grafo();
              /*
                * creara un nodo y lo agregara al grafo con su correspondiente
                * orden de agregado
              */
              void agregar_nodo(const std::string& informacion);
              /*
                * se buscara en el vector los nodos que corresponden a las
                * posiciones que llegan por parametro y se realiza la conexion
                * se toma como que los nodos ya se encuentran en el grafo
              */
              void agregar_arista(const int& pos1,const int& pos2);
              /*
                * se realizara el algoritmos de dfs devolviendo true si hay
                * ciclos o false si no
              */
              bool dfs();
              /*
                * devolvera true si hay nodos sin visitar sino devolvera false
                * en caso de no llamar primero a la funcion de dfs devolvera
                * que hay nodos sin visitar.
              */
              bool nodos_sin_visitar();
              
      private:
            std::vector<Nodo> nodos;
};

#endif
