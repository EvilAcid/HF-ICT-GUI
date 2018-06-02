#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QComboBox;
class QLineEdit;
class QPushButton;

class MainWidget : public QWidget {

  public:
	MainWidget();
	QString getBlock1();
	QString getBlock2();
	QString getBlock3();
	QString getBlock4();
	void enableCheckButton();

  private:

	QComboBox *monthBox;
	QComboBox *yearBox;

	QLineEdit *block1Input;
	QLineEdit *block2Input;
	QLineEdit *block3Input;
	QLineEdit *block4Input;

	QPushButton *checkButton;
};

#endif // MAINWIDGET_H
