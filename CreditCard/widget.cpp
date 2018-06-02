#include "widget.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>

#include "eventhandler.h"


Widget::Widget(QWidget *parent)
	: QWidget(parent) {
	//--------------------------------------------------
	//Objekte
	//--------------------------------------------------
	QLabel *titellabel = new QLabel("<h1>CreditCard</h1>");
	//titellabel->heightForWidth(100);
	cardNumberLineEdit = new QLineEdit;
	cardNumberLineEdit->setInputMask("9999 9999 9999 9999;.");
	cardNumberLineEdit->setToolTip("Enter your Creditard number...");
	//--------------------------------------------------
	jahr_combobox = new QComboBox();
	jahr_combobox->addItem("2017");
	jahr_combobox->addItem("2018");
	jahr_combobox->addItem("2019");
	monat_combobox = new QComboBox();
	monat_combobox->addItem("Januar");
	monat_combobox->addItem("Februar");
	monat_combobox->addItem("März");
	monat_combobox->addItem("April");
	monat_combobox->addItem("Mai");
	monat_combobox->addItem("Juni");
	monat_combobox->addItem("Juli");
	monat_combobox->addItem("August");
	monat_combobox->addItem("September");
	monat_combobox->addItem("Oktober");
	monat_combobox->addItem("November");
	monat_combobox->addItem("Dezember");
	//--------------------------------------------------
	button = new QPushButton("Check");
	//--------------------------------------------------
	//Layout
	//--------------------------------------------------
	QGridLayout *layout = new QGridLayout();
	layout->setRowMinimumHeight(2, 25);
	layout->setRowMinimumHeight(3, 25);
	layout->setRowMinimumHeight(4, 30);
	layout->addWidget(titellabel, 1, 0, 1, 3);
	layout->addWidget(cardNumberLineEdit, 2, 0, 2, 4);
	layout->addWidget(monat_combobox, 3, 0, 3, 1);
	layout->addWidget(jahr_combobox, 3, 2, 3, 4);
	layout->addWidget(button, 4, 0, 4, 4);
	setLayout(layout);
	//--------------------------------------------------
	//Connects
	//--------------------------------------------------
	EventHandler *h = new EventHandler();
	QObject::connect(button, SIGNAL(clicked()), h, SLOT(onButtonClicked()));
	QObject::connect(cardNumberLineEdit, SIGNAL(returnPressed()), h,
					 SLOT(onButtonClicked()));
	QObject::connect(h, SIGNAL(samplesignal()), this, SLOT(mySampleSlot()));
	QObject::connect(h, SIGNAL(cardNumberValid()), this, SLOT(cardNumberValide()));
	QObject::connect(h, SIGNAL(cardNumberNotValid()), this,
					 SLOT(cardNumberNotValide()));
}

void Widget::mySampleSlot() {
	qDebug() << "InputWert: " << this->cardNumberLineEdit->text();
	QString cardnumber = cardNumberLineEdit->text();
	cardnumber.remove(QChar(' '), Qt::CaseInsensitive);
	qDebug() << "ChangeWert: " << cardnumber;
	std::vector<int> cardnumberVector;
	int counter(1), tmp(0), Sum(0);
	if (cardnumber == "") {
		emit cardNumberNotValide();
		return;
	} else {
		std::for_each(cardnumber.rbegin(),
		cardnumber.rend(), [&cardnumberVector, &counter, &tmp, &Sum](QChar temp) {
			if (counter % 2 == 0) {
				tmp = (2 * temp.digitValue());
				if (tmp >= 10) {
					while (tmp > 0) {
						Sum += tmp % 10;
						tmp /= 10;
					}
					cardnumberVector.push_back(Sum);
					Sum = 0;
				} else {
					cardnumberVector.push_back(tmp);
				}
			} else {
				cardnumberVector.push_back(temp.digitValue());
			}
			++counter;
		});
		counter = 0;
		for (auto &x : cardnumberVector) {
			qDebug() << x;
			Sum += x;
			qDebug() << "Summe: " << Sum;
		}
		if (Sum % 10 == 0) {
			emit cardNumberValide();
		} else {
			emit cardNumberNotValide();
		}
	}
}

void Widget::cardNumberValide() {
	QMessageBox *msg = new QMessageBox(this);
	msg->setText("Valide");
	msg->show();
}

void Widget::cardNumberNotValide() {
	QMessageBox *msg = new QMessageBox(this);
	msg->setText("NOT Valide");
	msg->show();
}


Widget::~Widget() {
}
