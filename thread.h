#ifndef THREAD_H
#define THREAD_H
#include <thread>
#include <utility>
class Thread {
      public:
              /*
                * creara al thread dejandolo valido para uso
              */
              Thread();
              /*
                * se encargara de arrancar el hilo
              */
              void start();
              /*
                * Se encarga de correr el hilo
              */
              virtual void run() = 0;
              /*
                * Se encarga de liberar al thread con sus recursos
              */
              virtual ~Thread() {}
              /*
                * se encarga de hacer join del thread
              */
              void join();
              Thread(const Thread&) = delete;
              Thread(Thread&& otroThread);
              Thread& operator=(Thread&& otroThread);
              Thread& operator=(const Thread&) = delete;

      private:
              std::thread thread;
};

#endif
