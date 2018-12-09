#include <iostream>

#include <unistd.h>	// sleep() function

#include "thread.h"

class SimpleThread : public Thread {
	private:
		std::string name;
		void run() {
			int x = 5;
			while(--x) {
				std::cout << name << " is running" << std::endl;
				sleep(1);
			}
			std::cout << name << " finished." << std::endl;
		}
	public:
		SimpleThread(std::string name) : name(name){};
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
