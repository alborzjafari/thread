#include <iostream>

#include "thread.h"

using namespace std;

Thread::~Thread()
{
  delete thread_object;
}

Thread::Thread() : is_running(true)
{
}

Thread::Thread(Thread&& src) noexcept : thread_object(move(src.thread_object))
{
  src.thread_object = nullptr;
}

Thread& Thread::operator=(Thread&& rhs) noexcept
{
  if (&rhs == this)
    return *this;

  thread_object = rhs.thread_object;
  rhs.thread_object = nullptr;

  return *this;
}

void Thread::start()
{
  thread_object = new std::thread(&Thread::entry_point, this);
}

void Thread::join()
{
  thread_object->join();
  is_running.store(false);
}

bool Thread::running() const noexcept
{
  return is_running.load();
}

void Thread::entry_point()
{
  run();
  is_running.store(false);
}
