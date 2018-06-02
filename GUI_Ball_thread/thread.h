#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Widget;

class Thread : public QThread {
	Q_OBJECT
  public:
	Thread();
	void run();
  signals:
	void ThreadRun();
};

#endif // THREAD_H
