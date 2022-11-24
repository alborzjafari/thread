#include "thread.h"

using namespace std;

Thread::~Thread() {}

Thread::Thread() : is_running(true) {}

Thread::Thread(Thread&& src) noexcept
  : thread_object(move(src.thread_object)) {}

Thread& Thread::operator=(Thread&& rhs) noexcept {
  if (&rhs != this)
    thread_object = move(rhs.thread_object);

  return *this;
}

void Thread::start() {
  thread_object = make_unique<std::thread>(&Thread::entry_point, this);
}

void Thread::join() {
  thread_object->join();
  is_running.store(false);
}

bool Thread::running() const noexcept { return is_running.load(); }

void Thread::entry_point() {
  run();
  is_running.store(false);
}
