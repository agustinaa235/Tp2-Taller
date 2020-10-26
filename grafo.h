#ifdef GRAFO_H
#define GRAFO_H

#include <vector>
typedef std::vector< Nodo > Nodos;

struct Nodo {
private:
    string informacion;
    vector<string> vecinos;

public:
    Nodo(String informacion);
    void agregar_vecino(String vecino);
};
class Grafo{

    private:
            Nodos nodos;
            int cantidad_nodos;

    public:
          Grafo();
          void agreagar_arista(string nodo1Info, string nodo2Info);
          void dfs(Nodo nodo);

};

#endif
