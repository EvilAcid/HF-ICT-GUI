#include "thread.h"

Thread::Thread() {
}

/*!
 * \brief Thread::run
 *
 * QThread, wird hier als Taktgeber benutzt.
 */
void Thread::run() {
	//Endlosschleife im Thread
	while (true) {
		emit ThreadRun(); //Signal "ThreadRun()" auslösen
		msleep(20); //20 Millisec warten (nur in diesem Thread)
	}
}
