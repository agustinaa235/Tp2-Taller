#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include<string>

class Grafo{
    public:
          Grafo();
          ~Grafo();
          void agregar_arista(const std::string info1, const std::string info2);
          void agregarNodo(const std::string informacion);
          //void agregar_arista_indices(int pos1, int pos2);
          //void dfs(Nodo nodo);
    private:
          std::vector<std::list<std::string>> nodos;
};

#endif
