#include "grafo.h"
#include <list>

Grafo::Grafo(){
    this->nodos = new vector<Nodo>;
    this->cantidad_nodos = 0;
}

void Grafo::agregarNodo(const Nodo& nodo){
      this->nodos.insert(nodo);
}
void Grafo::addEdgeIndices ( int pos1, int pos2 ) {
      nodos[pos1].push_back(pos2);

}
Nodos::iterator Grafo::encontrar_nodo(string info, bool& encontre){
   std::vector<Nodo>::iterator iterador;
   Nodo nodo(info);
   iterador = std::find( nodos.begin(), nodos.end(), nodo);
   if (iterador != nodo.end()){
        encontre = true;
        return iterador;
   } else {
       encontre = false;
       return nodo.end();
   }
}

void Grafo::agregoArista(const string nodo1Info, const string nodo2Info){
      bool encontro_n1 = false;
      bool encontro_n2 = false;
      ool foundNet1 = false, foundNet2 = false;
      Nodo::iterator vit1 = encontrar_nodo( nodo1Info, encontro_n1);
      int pos_n1 = -1, pos_n2 = -1;
      if ( !encontro_n1) {
          //Vertex v1( n1 );
          Nodo nodo1(nodo1Info);
      //vertices.push_back( v1 );
          nodos.push_back(nodo1);
          pos_n1 = nodos.size() - 1;
      } else {
          pos_n1 = vit1 - vertices.begin();
      }
      Nodo::iterator vit2 = encontrar_nodo( nodo2Info, encontro_n2);
      if ( !encontro_n2) {
          //Vertex v2( n2 );
          Nodo nodo2(nodo2Info);
          //vertices.push_back( v2 );
          nodos.push_back(nodo2);
          //node2Index = vertices.size() - 1;
          pos_n2 = nodos.size() -1;
      } else {
          pos_n2 = vit2 - nodos.begin();
      }

   //assert( ( node1Index > -1 ) && ( node1Index <  vertices.size()));
   //assert( ( node2Index > -1 ) && ( node2Index <  vertices.size()));
   agregar_arista_indices( pos_n1, pos_n2);
}
void Grafo::dfs_aux(int s, vector<bool> &visited){
    // stack for DFS
    stack<int> pila;
   // current source node inside stack
    pila.push(s);

    while (!pila.empty()) {
        // Pop a vertex
        s = dfsstack.top();
        dfsstack.pop();

        // display the item or node only if its not visited
        if (!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }

        // explore all adjacent vertices of popped vertex.
        //Push the vertex to the stack if still not visited
        for(vector<nodo>::iterator i = this->nodo[s].begin(); i != this->adjList[s].end(); ++i){
              if (!visited[*i]){
                  dfsstack.push(*i);
              }
        }
    }
}
void Grafo::imprimir() {
  for (int i = 0; i < nodos.size(); i++) {
      cout << "\n Vertex "
       << d.informacion << ":";
    for (auto x : nodo[i])
      cout << "-> " << x.informacion;
    printf("\n");
  }
}
void Grafo::dfs() {
    // initially all vertices are not visited
    vector<bool> visitados(nodos.size());
    for(int i=0; i<nodos.size(); i++){
        visitados[i] = false;
    }

    for (int i = 0; i < nodos.size(); i++){
        if (!visited[i]){
            dfs_aux(i, visited);
        }
}
