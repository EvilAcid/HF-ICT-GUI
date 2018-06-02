#include <QCoreApplication>
#include <outputthread.h>
#include <QThread>
int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
	outputThread T1;
	outputThread T2;
	T1.start();
	T2.start();
	return a.exec();
}
