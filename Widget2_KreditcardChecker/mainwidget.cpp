#include "mainwidget.h"
#include "eventhandler.h"

#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QDebug>


MainWidget::MainWidget() {
	QLabel *titleLabel = new QLabel("<H1>Kreditkarten Checker</H1>");
	block1Input = new QLineEdit();
	block2Input = new QLineEdit();
	block3Input = new QLineEdit();
	block4Input = new QLineEdit();
	//--------------------------------------------------
	block1Input->setPlaceholderText("1234");
	block2Input->setPlaceholderText("1234");
	block3Input->setPlaceholderText("1234");
	block4Input->setPlaceholderText("1234");
	//--------------------------------------------------
	block1Input->setInputMask("d d d d;_");
	block2Input->setInputMask("d d d d;_");
	block3Input->setInputMask("d d d d;_");
	block4Input->setInputMask("d d d d;_");
	//--------------------------------------------------
	monthBox = new QComboBox();
	monthBox->addItem("Jan");
	monthBox->addItem("Feb");
	monthBox->addItem("Mär");
	monthBox->addItem("Apr");
	monthBox->addItem("Mai");
	monthBox->addItem("Jun");
	monthBox->addItem("Jul");
	monthBox->addItem("Aug");
	monthBox->addItem("Sep");
	monthBox->addItem("Okt");
	monthBox->addItem("Nov");
	monthBox->addItem("Dec");
	//--------------------------------------------------
	yearBox = new QComboBox();
	yearBox->addItem("2014");
	yearBox->addItem("2015");
	yearBox->addItem("2016");
	yearBox->addItem("2017");
	yearBox->addItem("2018");
	yearBox->addItem("2019");
	yearBox->addItem("2020");
	yearBox->addItem("2021");
	yearBox->addItem("2022");
	yearBox->addItem("2023");
	yearBox->addItem("2024");
	yearBox->addItem("2025");
	checkButton = new QPushButton("Check");
//	checkButton->setEnabled(true);
	checkButton->setToolTip("Überprüft die Kartennummer");
	//--------------------------------------------------
	// create layout
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(titleLabel, 0, 0, 1, 4);
	layout->addWidget(block1Input, 1, 0);
	layout->addWidget(block2Input, 1, 1);
	layout->addWidget(block3Input, 1, 2);
	layout->addWidget(block4Input, 1, 3);
	layout->addWidget(new QLabel("Month"), 2, 0);
	layout->addWidget(monthBox, 2, 1);
	layout->addWidget(new QLabel("Year"), 2, 2);
	layout->addWidget(yearBox, 2, 3);
	layout->addWidget(checkButton, 3, 0, 1, 4);
	//--------------------------------------------------
	this->setLayout(layout);
	//--------------------------------------------------
	// event handling
	//--------------------------------------------------
	// Eventhandling Objekt
	EventHandler *handler = new EventHandler(this);
	//--------------------------------------------------
	//--------------------------------------------------
	// Connects
	QObject::connect(
		checkButton, SIGNAL(clicked()),
		handler, SLOT(onCheckButtonClicked())
	);
}

QString MainWidget::getBlock1() {
	return block1Input->text();
}

QString MainWidget::getBlock2() {
	return block2Input->text();
}

QString MainWidget::getBlock3() {
	return block3Input->text();
}

QString MainWidget::getBlock4() {
	return block4Input->text();
}


