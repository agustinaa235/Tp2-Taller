#include <iostream>
#include <fstream>
#include <vector>
#include "parceador.h"
#include "grafo.h"

#define EXITO 0
#define ERROR 1
#define TAMANIO_MAX 50

int main(int argc, char** argv){

  Parceador parcer(argv[1]);
  Grafo grafo = Grafo();
  parcer.parcear_archivo(grafo);

  if (grafo.dfs()){
      std::cout << "FAIL" << "\n";
  } else {
      std::cout <<"GOOD" << "\n";
  }
  std::vector<Thread*> threads;

  for (int i = 0; i < N; ++i) {
        threads.push_back();
  }
  for (int i = 0; i < N; ++i) {
        threads[i]->start();
  }

  for (int i = 0; i < N; ++i) {
        threads[i]->join();
        delete threads[i];
    }

  return 0;
}
