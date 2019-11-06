#ifndef _THREAD_H
#define _THREAD_H

#include <thread>

class Thread{

	protected:
		virtual void run() = 0;
		std::thread *threadObject = nullptr;

	public:
		void start();
		Thread();
		virtual ~Thread();
		void join();
};

#endif
