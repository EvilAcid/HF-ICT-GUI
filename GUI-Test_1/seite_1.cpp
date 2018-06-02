#include "seite_1.h"

#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpacerItem>

seite_1::seite_1(QWidget *parent) : QWidget(parent) {
	QVBoxLayout *mainLayout = new QVBoxLayout;
	//--------------------------------------------------
	//TitelLayout
	//--------------------------------------------------
	QHBoxLayout *titelLayout = new QHBoxLayout;
	QLabel *titelLabel = new QLabel("Titel");
	QSpacerItem *hSpace = new QSpacerItem(20, 40, QSizePolicy::Minimum,
										  QSizePolicy::Expanding);
	QLabel *titelLogo = new QLabel;
	QPixmap pm("your-image.jpg");
	titelLogo->setPixmap(pm);
	//-----
	titelLayout->addWidget(titelLabel);
	titelLayout->addSpacerItem(hSpace);
	titelLayout->addWidget(titelLogo);
	//--------------------------------------------------
	//-----
	//--------------------------------------------------
	//-----
	//--------------------------------------------------
	//-----
	//--------------------------------------------------
	//-----
	setLayout(mainLayout);
}
