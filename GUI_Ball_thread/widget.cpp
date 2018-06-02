#include "widget.h"
#include <QPaintEvent>
#include <QPainter>

#include "thread.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent), x(100), y(100), xSpeed(6), ySpeed(6), RADIUS(40),
	  collision(0) {
	//--------------------------------------------------
	//Thread t erstellen
	Thread *t = new Thread();
	//Thread t starten
	t->start();
	//--------------------------------------------------
	QObject::connect(t, SIGNAL(ThreadRun()), this, SLOT(move()));
	QObject::connect(t, SIGNAL(ThreadRun()), this, SLOT(update()));
}

Widget::~Widget() {
}

/*!
 * \brief Widget::move
 * \details Slot move
 *
 * Hier ist die Logick von dem Ball, wie er sich bewegen soll.
 */
void Widget::move() {
	x += xSpeed;
	y += ySpeed;
	if (x + RADIUS > width() || x < 0) {
		xSpeed *= -1;
		collision += 1;
	}
	if (y + RADIUS > height() || y < 0) {
		ySpeed *= -1;
		collision += 1;
	}
}

/*!
 * \brief Widget::paintEvent
 * \param event
 *
 * Zeichnet den Ball
 */
void Widget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	painter.drawEllipse(x, y, RADIUS, RADIUS);
	painter.drawText(5, 20, "Collision = " + QString::number(collision));
}
