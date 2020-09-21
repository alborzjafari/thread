#include <iostream>

#include "thread.h"

using namespace std;

Thread::~Thread()
{
  delete thread_object;
}

Thread::Thread()
{
}

Thread::Thread(Thread&& src) noexcept : thread_object(move(src.thread_object))
{
  src.thread_object = nullptr;
}

Thread& Thread::operator=(Thread&& rhs)
{
  if (&rhs == this)
    return *this;

  thread_object = rhs.thread_object;
  rhs.thread_object = nullptr;

  return *this;
}

void Thread::start()
{
  thread_object = new std::thread(&Thread::run, this);
}

void Thread::join()
{
  thread_object->join();
}
