#include "thread.h"

Thread::Thread(){}

void Thread::start() {
    this->thread = std::thread(&Thread::run, this);
}
void Thread::join() {
    this->thread.join();
}

Thread& Thread::operator=(Thread&& otroThread) {
    this->thread = std::move(otroThread.thread);
    return *this;
}

Thread::Thread(Thread&& otroThread) {
    this->thread = std::move(otroThread.thread);
}
