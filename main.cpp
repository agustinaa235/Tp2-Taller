#include <iostream>
#include <fstream>
#include <vector>
#include "parceador.h"

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
  /*int cantidad_de_archivos = argc;
  int posicion_argumento = 1;
  std::ifstream archivo;
  std::string instruccion;
  std::string etiqueta;
  std::vector<std::string> saltos = {"jmp", "ja", "jeq", "jneq", "jlt", "jge", "jgt",
                                "jle", "jne", "jset"};

  /*while (cantidad_de_archivos != 0){
      if (abrir_archivo(archivo, argv[posicion_argumento]) == EXITO){
          archivo_leer(archivo, etiqueta, instruccion);
      }

      cantidad_de_archivos -=1;
      posicion_argumento +=1;
  }*/
  /*archivo.open(argv[1]);
  std::string formatoDosPuntos(":");
  std::string ret = "ret";
  while (getline(archivo ,etiqueta, '\n')){
        size_t pos = etiqueta.find(formatoDosPuntos);
        if (pos > -1){ // soy una etiqueta y sigo
            std::cout << "soy etiqueta" << ' ' << etiqueta << ' ' << instruccion << "\n";
        } else {
            instruccion = etiqueta; // no encontre ningun :, soy una intrucccion;
            if(etiqueta.find(ret) != -1){
                std::cout << "soy intruccio de return " << ' ' << etiqueta << "\n";
            } else{
                std::cout << "soy otra intruccion" << ' ' << etiqueta << "\n";
            }
        }
  }
  archivo.close();
*/
  Parceador parcer(argv[1]);
  parcer.parcear_archivo();

  return 0;
}
