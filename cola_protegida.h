#ifndef COLA_PROTEGIDA_H
#define COLA_PROTEGIDA_H

class Lock {
    private:
        std::mutex &m;

    public:
        Lock(std::mutex &m) : m(m) {
            m.lock();
        }

        ~Lock() {
            m.unlock();
        }

    private:
        Lock(const Lock&) = delete;
        Lock& operator=(const Lock&) = delete;
        Lock(Lock&&) = delete;
        Lock& operator=(Lock&&) = delete;

};


class ColaProtegida{
      private:
          std::mutex m;
          std::queque<std::string> archivos;

      public:
          ColaProtegida();
          dar_archivo_si_cola_no_esta_vacia();
          cargar_nombre_archivo(std::string nombre_archivo);

};
