#include <iostream>

#include "thread.h"

Thread::~Thread()
{
  delete threadObject;
}

Thread::Thread()
{
}

void Thread::start()
{
  threadObject = new std::thread(&Thread::run, this);
}

void Thread::join()
{
  threadObject->join();
}

