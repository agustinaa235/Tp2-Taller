#ifndef PARCEADOR_H
#define PARCEADOR_H


#include <fstream>
#include <string>

class Parceador{

    public:
          Parceador(const std::string nombre_archivo);
          ~Parceador();
          int parcear_archivo();
    private:
          std::ifstream archivo;
};

#endif
