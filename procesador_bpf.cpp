#include "procesador_bpf.h"

#include "parceador.h"
#include "grafo.h"
#include "verificador.h"
#include <string>
#include <iostream>

Procesador_Bpf::Procesador_Bpf(Contenedor_Archivos& archivos,
                                Contenedor_Resultados& resultados) :
          contenedor_archivos(archivos),
          contenedor_resultados(resultados){}

Procesador_Bpf::~Procesador_Bpf(){}

void Procesador_Bpf::run(){
    while (!contenedor_archivos.esta_vacio()){
        std::string archivo("");
        archivo = this->contenedor_archivos.dar_archivo();
        int resultado = -1;
        if (archivo != ""){
            Parceador parcer(archivo);
            Grafo grafo = Grafo();
            parcer.parcear_archivo(grafo);
            Verificador verificador = Verificador(grafo);
            resultado = verificador.verificar_bpf();
        }
        this->contenedor_resultados.cargar_resultados(archivo, resultado);
    }
}
