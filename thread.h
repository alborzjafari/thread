#ifndef _THREAD_H
#define _THREAD_H

#include <thread>

class Thread{

  protected:
    virtual void run() = 0;
    std::thread *threadObject = nullptr;

  public:
    virtual ~Thread();
    Thread();

    void start();
    void join();
};

#endif
