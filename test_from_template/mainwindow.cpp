#include <QGridLayout>
#include <QWidget>
#include <QCheckBox>
#include <QDebug>

#include "mainwidget.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent) {
	QGridLayout *grid = new QGridLayout();
	grid->setContentsMargins(0, 0, 0, 0);
	QWidget *window = new QWidget();
	window->setStyleSheet("border: 1px solid black;");
	mainwidget *ex1 = new mainwidget(this);
	QCheckBox *tcb = new QCheckBox;
	grid->addWidget(ex1, 0, 0);
	grid->addWidget(tcb, 1, 1);
	window->setLayout(grid);
	this->setCentralWidget(window);
	qDebug() << "Alles init";
}

MainWindow::~MainWindow() {
}
