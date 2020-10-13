#ifndef _THREAD_H
#define _THREAD_H

#include <thread>
#include <atomic>

class Thread{
  public:
    virtual ~Thread();
    Thread();
    Thread(const Thread& src) = delete;   // copy constructor
    Thread(Thread&& src) noexcept;    // move constructor
    Thread& operator=(Thread&& rhs) noexcept;    // move assignment
    Thread& operator=(const Thread& rhs) = delete;    // copy assignment

    void start();
    void join();
    bool running() const noexcept;

  protected:
    virtual void run() = 0;

  private:
    void entry_point();
    std::thread *thread_object = nullptr;
    std::atomic<bool> is_running;
};

#endif
