#include "outputthread.h"
#include <QDebug>
#include <QMutex>

outputThread::outputThread() {
}

void outputThread::run() {
	QMutex mutex;
	for (int i(0); i < 100; i++) {
		mutex.lock();
		qDebug() << "thread write " << i;
		mutex.unlock();
	}
}
