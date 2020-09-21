#include <unistd.h>	// sleep() function

#include <iostream>

#include "thread.h"

using namespace std;

class SimpleThread : public Thread {
  private:
    string name;
    void run() {
      int x = 5;
      while(--x) {
        cout << name << " is running" << endl;
        sleep(1);
      }
      cout << name << " finished." << endl;
    }
  public:
    SimpleThread(string name) : name(name) {};
};

int main()
{
  SimpleThread simple_thread_obj1("Thread 1");
  SimpleThread simple_thread_obj2("Thread 2");

  simple_thread_obj1.start();
  simple_thread_obj2.start();

  simple_thread_obj1.join();
  simple_thread_obj2.join();

  return 0;
}
