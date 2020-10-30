#include "grafo.h"
#include <iostream>


int main(){

    Grafo grafo = Grafo();
    grafo.agregar_nodo("hola");
    grafo.agregar_nodo("como");
    grafo.agregar_nodo("agustina");
    grafo.agregar_nodo("estas");
    grafo.agregar_nodo("me");
    grafo.agregar_nodo("llamo");
    grafo.agregar_arista("hola", "como");
    grafo.agregar_arista("hola", "estas");
    grafo.agregar_arista("estas", "me");
    grafo.agregar_arista("me", "llamo");
    grafo.agregar_arista("llamo", "agustina");
    grafo.dfs();

    return 0;
}
