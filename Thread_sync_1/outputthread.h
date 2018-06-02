#ifndef OUTPUTTHREAD_H
#define OUTPUTTHREAD_H
#include <QThread>


class outputThread : public QThread {
  public:
	outputThread();
	void run();

};

#endif // OUTPUTTHREAD_H
