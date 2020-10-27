#include "grafo.h"
#include <list>


Grafo::Grafo(){
    this->nodos =std::vector<std::list<std::string>>();
}
Grafo::~Grafo(){
    //delete(this->nodos);
}

void Grafo::agregarNodo(const std::string info){
      this->nodos.push_back(std::list<std::string>());
      this->nodos.back().push_back(info);
}
int encontrar_pos_nodo(std::vector<std::list<std::string>> nodos, const std::string info){
    int pos = -1;
    auto it = std::find(nodos.begin(), nodos.end(), info);

    // If element was found
    if (it != nodos.end()) {
        // calculating the index
        // of K
         pos = distance(nodos.begin(),
                             it);
        //cout << index << endl;
        return pos;
    }
    else {
        // If the element is not
        // present in the vector
        return pos;
    }
}
void Grafo::agregar_arista(const std::string info1, const std::string info2) {
      size_t pos = encontrar_pos_nodo(this->nodos, info1);
      this->nodos[pos].push_back(info2);

}
/*
void Grafo::agregarNodo(const std::string informacion){
    this->nodos.back().push_back(informacion);
}
string::iterator encontrar_nodo(const std::string info, bool& encontre){
   std::vector<std::string>::iterator iterador;
   //Nodo nodo(info);
   iterador = std::find( nodos.begin(), nodos.end(), info);
   if (iterador != nodo.end()){
        encontre = true;
        return iterador;
   } else {
       encontre = false;
       return nodos.end();
   }
}

void Grafo::agregoArista(const std::string nodo1Info, const std::string nodo2Info){
      bool encontre_nodo1= false;
      bool encontre_nodo2 = false;
      std::list<std::string>::iterator it1;
      it = encontrar_nodo(nodo1_info, encontre_nodo1);
      int pos_nodo1 = -1, pos_nodo2 = -1;
      if (!encontre_nodo1){
          nodos->agregarNodo(nodo1Info);
          pos_nodo1 = nodos.size() -1;
      } else {
          pos_nodo1 = it1 - nodos.begin();
      }
      std::list<std::string>::iterator it2;
      it = encontrar_nodo(nodo2_info, encontre_nodo2);
      if (!encontre_nodo2){
          nodos->agregarNodo(nodo2Info);
          pos_nodo2 = nodos.size() -1;
      } else {
          pos_nodo1 = it2 - nodos.begin();
      }
      agregar_arista_indices( pos_n1, pos_n2);
}
/*
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
}*/
/*
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
}*/
