#include <iostream>
#include <fstream>
#include <vector>
#include "parceador.h"
#include "grafo.h"

#define EXITO 0
#define ERROR 1
#define TAMANIO_MAX 50
/*
int abrir_archivo(ifstream& archivo, String nombre_archivo){
     archivo.open(nombre_archivo);
     if (!archivo.is_open()){
        std::cout << "No se pudo abrir el archivo \n";
        return ERROR;
     }
     return EXITO;
}

int archivo_leer(ifstream& archivo, String& etiqueta, String& instruccion){
    std::string formatoDosPuntos(":");
    while (!archivo.eof()){
          archivo >> etiqueta;
          size_t pos = etiqueta.find(formatoDosPuntos);
          if (pos > -1){ // soy una etiqueta y sigo
              archivo >> instruccion;
              stdd::cout << "soy etiqueta" << ' ' << etiqueta << ' ' << intruccion << "\n";
          } else {
              instruccion = etiqueta; // no encontre ningun :, soy una intrucccion;
              std::cout << "soy intruccion" << ' ' << etiqueta << "\n";
          }
    }
    return EXITO;
}*/

int main(int argc, char** argv){

  Parceador parcer(argv[1]);
  //Grafo grafo();
  Grafo grafo = Grafo();
  parcer.parcear_archivo(grafo);
  grafo.dfs();

  return 0;
}
