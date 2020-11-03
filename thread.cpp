#include "thread.h"
#include "parceador.h"
#include "grafo.h"
#include "verificador.h"
#include <string>
#include <utility>
#include <iostream>



Thread::Thread(Contenedor_Archivos* archivos,
               Contenedor_Resultados* resultados) {
    this->contenedor_archivos = archivos;
    this->contenedor_resultados = resultados;

}

void Thread::run(){
    std::string archivo("");
    archivo = this->contenedor_archivos->dar_archivo();
    int resultado = -1;
    if (archivo != ""){
        Parceador parcer(archivo);
        Grafo grafo = Grafo();
        parcer.parcear_archivo(grafo);
        Verificador verificador = Verificador(&grafo);
        resultado = verificador.verificar_bpf();
    }
    this->contenedor_resultados->cargar_resultados(archivo, resultado);
}

void Thread::start() {
  while (!contenedor_archivos->esta_vacio()){
        this->run();
  }
}
Thread::~Thread() {}

Thread::Thread(Thread&& otroThread) {
    this->thread = std::move(otroThread.thread);
    this->contenedor_archivos = otroThread.contenedor_archivos;
    this->contenedor_resultados = otroThread.contenedor_resultados;
    otroThread.contenedor_archivos = 0;
    otroThread.contenedor_resultados = 0;
}
