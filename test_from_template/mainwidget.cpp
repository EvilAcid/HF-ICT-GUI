#include "mainwidget.h"
#include <QPainter>
#include <QStyleOption>

mainwidget::mainwidget(QWidget *parent) : QWidget(parent)
{
}

void mainwidget::paintEvent(QPaintEvent *event)
{
	QPainter paint(this);
	// Draw StyleSheet of this Widget - begin()
	QStyleOption opt;
	opt.init(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &paint, this);
	QWidget::paintEvent(event);
	// Draw StyleSheet of this Widget - end()

	// Draw events
	paint.drawLine(0,0,width(),height());

}
