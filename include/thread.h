#ifndef _THREAD_H
#define _THREAD_H

#include <thread>

class Thread{
  public:
    virtual ~Thread();
    Thread();
    Thread(const Thread& src) = delete;   // copy constructor
    Thread(Thread&& src) noexcept;    // move constructor
    Thread& operator=(Thread&& rhs);    // move assignment
    Thread& operator=(const Thread& rhs) = delete;    // copy assignment

    void start();
    void join();

  protected:
    virtual void run() = 0;

  private:
    std::thread *thread_object = nullptr;
};

#endif
