#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>


class Nodo{

  public:
        Nodo(const std::string informacion);
        ~Nodo();
        void agregar_vecino(Nodo& nodoVecino);
        int es_igual_a(const std::string informacion) const;
        std::string get_informacion();
        std::vector<Nodo*> get_vecinos();
        bool fue_visitado();
        void visitar();
  private:
        std::string informacion;
        std::vector<Nodo*> vecinos;
        bool visitado;
};

class Grafo{
    public:
          Grafo();
          ~Grafo();
          void agregar_nodo(std::string informacion);
          int buscar_nodo(const std::string informacion) const;
          void agregar_arista(std::string info1, std::string info2);
          int dfs();
    private:
          std::vector<Nodo> nodos;

};

#endif
