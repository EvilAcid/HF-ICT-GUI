#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include "paintarea.h"

#include <QMainWindow>

class MainWindow : public QMainWindow {
	Q_OBJECT
  private:
	QPushButton *btn_reset;
	QPushButton *btn_paint;
	PaintArea *paintarea;

  public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

};

#endif // MAINWINDOW_H
