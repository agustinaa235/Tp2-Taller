#ifndef THREAD_H
#define THREAD_H

class Thread{


    public:
        Thread ();
        void start();
        void join();
        virtual void run();
        virtual ~Thread();
        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;
        Thread(Thread&& other);
        Thread& operator=(Thread&& other);
    private:
          std::thread thread;
};

#endif
