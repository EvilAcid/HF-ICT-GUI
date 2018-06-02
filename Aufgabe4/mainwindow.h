#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>

class MainWindow : public QMainWindow {
	Q_OBJECT

  public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	QLineEdit *ledInput;
	QPushButton *btnAdd;
	QPushButton *btnClear;
	QPushButton *btnSort;
	QListWidget *listWidget;
};

#endif // MAINWINDOW_H
