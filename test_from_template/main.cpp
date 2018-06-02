#include <QApplication>
#include "mainwindow.h"
#include <QFile>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	QFile File(":/StyleSheet/style.qss");
	File.open(QFile::ReadOnly);
	QString StyleSheet = QLatin1String(File.readAll());
	w.setStyleSheet(StyleSheet);
	w.show();
	return a.exec();
}
