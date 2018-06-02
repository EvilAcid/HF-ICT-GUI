#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	// Horizontal layout mit 3 buttons
	//--------------------------------------------------
	QHBoxLayout *hLayout = new QHBoxLayout;
	QPushButton *b1 = new QPushButton("A");
	QPushButton *b2 = new QPushButton("B");
	QPushButton *b3 = new QPushButton("C");
	//-------------------------------------------------
	//
	// Buttons dem Horizontal Layout hinzufügen
	//--------------------------------------------------
	hLayout->addWidget(b1);
	hLayout->addWidget(b2);
	hLayout->addWidget(b3);
	//--------------------------------------------------
	// Vertical layout mit 3 buttons
	//--------------------------------------------------
	QVBoxLayout *vLayout = new QVBoxLayout;
	QPushButton *b4 = new QPushButton("D");
	// Icon für den Button b4 (D) hinzufügen
	b4->setIcon(QIcon(":/images/icons/006-cpp-file-format-symbol-1.png"));
	QPushButton *b5 = new QPushButton("E");
	b5->setIcon(QIcon(":/images/icons/008-social-rss.png"));
	QPushButton *b6 = new QPushButton("F");
	//--------------------------------------------------
	//Signal fürs schliessen an den Button b6 "binden"
	//--------------------------------------------------
	QObject::connect(b6, SIGNAL (clicked()), &app, SLOT (quit()));
	//--------------------------------------------------
	// Buttons dem Vertikal Layout hinzufügen
	//--------------------------------------------------
	vLayout->addWidget(b4);
	vLayout->addWidget(b5);
	vLayout->addWidget(b6);
	//--------------------------------------------------
	// äuserer Layer
	//--------------------------------------------------
	QVBoxLayout *mainLayout = new QVBoxLayout;
	//--------------------------------------------------
	// hinzufügen der 2 layouts
	//--------------------------------------------------
	mainLayout->addLayout(hLayout);
	mainLayout->addLayout(vLayout);
	//--------------------------------------------------
	// Widget erstellen
	//--------------------------------------------------
	QWidget *widget = new QWidget();
	//--------------------------------------------------
	// Setzen des äusseren Layouts als Haupt/Main Layout
	//--------------------------------------------------
	widget->setLayout(mainLayout);
	//--------------------------------------------------
	// Titel
	//--------------------------------------------------
	widget->setWindowTitle("layouts");
	//--------------------------------------------------
	// Anzeigen
	//--------------------------------------------------
	widget->show();
	//--------------------------------------------------
	return app.exec();
}
