#include "mainwindow.h"
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent) {
	//--------------------------------------------------
	QFormLayout *frmLayout = new QFormLayout(this);
	//--------------------------------------------------
	QLabel *lblTitel = new QLabel();
	lblTitel->setText(tr("<h2>Sortiersoftware</h2>"));
	//--------------------------------------------------
	ledInput = new QLineEdit();
	ledInput->setInputMask("ddddddd");
	//--------------------------------------------------
	btnAdd->setText(tr("Add"));
	btnClear->setText(tr("Clear"));
	//--------------------------------------------------
	frmLayout->addWidget(lblTitel);
	frmLayout->addWidget(ledInput);
	frmLayout->addRow(btnAdd, btnClear);
	//--------------------------------------------------
	QWidget *widget = new QWidget();
	widget->setLayout(frmLayout);
	setCentralWidget(widget);
}

MainWindow::~MainWindow() {
}
