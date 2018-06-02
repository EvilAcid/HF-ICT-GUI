#include "mainwindow.h"
#include "paintarea.h"
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow( QWidget *parent)
	: QMainWindow(parent) {
	paintarea = new PaintArea;
	setMinimumSize(500, 500);
	//--------------------------------------------------
	// Wdgets
	//--------------------------------------------------
	QLabel *lbl_titel = new QLabel;
	lbl_titel->setText(tr("<h1>Polygon Plotter</h1>"));
	//-------------
	btn_reset = new QPushButton;
	btn_reset->setText(tr("Reset"));
	//-------------
	btn_paint = new QPushButton;
	btn_paint->setText(tr("Paint"));
	//-------------
	//--------------------------------------------------
	QHBoxLayout *hbLayout = new QHBoxLayout;
	hbLayout->addWidget(btn_reset);
	hbLayout->addWidget(btn_paint);
	//-------------
	QVBoxLayout *vbLayoutArea = new QVBoxLayout;
	vbLayoutArea->addWidget(paintarea);
	//-------------
	QFormLayout *frmLayout = new QFormLayout;
	frmLayout->addRow(lbl_titel);
	frmLayout->addItem(hbLayout);
	frmLayout->addItem(vbLayoutArea);
	//-------------
	QWidget *widget = new QWidget();
	widget->setLayout(frmLayout);
	setCentralWidget(widget);
	//--------------------------------------------------
	//Connects nach QT5
	//--------------------------------------------------
	QObject::connect(btn_reset, &QPushButton::clicked, paintarea,
					 &PaintArea::reset);
	QObject::connect(btn_paint, &QPushButton::clicked, paintarea,
					 &PaintArea::paint);
}

MainWindow::~MainWindow() {
}
