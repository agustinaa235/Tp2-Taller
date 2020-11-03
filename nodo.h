#ifndef NODO_H
#define NODO_H

#include <vector>
#include <string>

class Nodo{
      public: /*
                * inicializa el nodo, dejandolo valido para uso
              */
              Nodo(const std::string& informacion, const int& orden);
              /*
                * liberara al nodo con sus recursos
              */
              ~Nodo();
              /*
                * agregara el nodo valido a su vector de vecinos
              */
              void agregar_vecino(Nodo& nodoVecino);
              /*
                * devuelve por referencia su vector de vecinos
              */
              std::vector<Nodo*>& get_vecinos();
              /*
                * devuelve el estado del nodo, true si fue visitado
                * o en caso contrario false
              */
              bool fue_visitado();
              /*
                * modificara el estado del nodo pasando a ser visitado como
                * true
              */
              void visitar();
              /*
                * devuelve el numero en el cual fue agregado el nodo
              */
              int orden_de_agregado();
      private:
              std::string informacion;
              std::vector<Nodo*> vecinos;
              bool visitado;
              int orden_agregado;
};

#endif
