#include "thread.h"


Thread () {}

void start() {
    thread = std::thread(&Thread::run, this);
}

void join() {
    thread.join();
}

virtual void run() = 0;
virtual ~Thread() {}

Thread(Thread&& other) {
    this->thread = std::move(other.thread);
}

Thread& operator=(Thread&& other) {
    this->thread = std::move(other.thread);
    return *this;
}
