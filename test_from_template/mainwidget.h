#ifndef mainwidget_H
#define mainwidget_H
#include <QObject>
#include <QWidget>


class mainwidget : public QWidget
{
		Q_OBJECT
	public:
		explicit mainwidget(QWidget *parent = nullptr);
	private:
		void paintEvent(QPaintEvent *event);
	signals:

	public slots:
};

#endif // mainwidget_H
