#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;
class QLineEdit;
class QComboBox;

class Widget : public QWidget {
	Q_OBJECT

  private:
	QPushButton *button;
	QLineEdit *cardNumberLineEdit;
	QComboBox *monat_combobox;
	QComboBox *jahr_combobox;
	QString test;
  public:
	Widget(QWidget *parent = 0);
	~Widget();


  public slots:
	void mySampleSlot();
	void cardNumberValide();
	void cardNumberNotValide();


};

#endif // WIDGET_H
