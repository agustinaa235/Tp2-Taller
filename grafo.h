#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>


class Nodo{
  public:
        Nodo(const std::string& informacion, const int& orden);
        ~Nodo();
        void agregar_vecino(Nodo& nodoVecino);
        std::string get_informacion();
        std::vector<Nodo*>& get_vecinos();
        bool fue_visitado();
        void visitar();
        int estado_nodo();
        void visitar_parcialmente();
        void visitar_finalmente();
        int orden_de_agregado();
  private:
        std::string informacion;
        std::vector<Nodo*> vecinos;
        bool visitado;
        int orden_agregado;
};

class Grafo{
    public:
          Grafo();
          ~Grafo();
          void agregar_nodo(const std::string& informacion);
          void agregar_arista(const int& pos1,const int& pos2);
          bool dfs();
          bool nodos_sin_visitar();
    private:
          std::vector<Nodo> nodos;
};

#endif
