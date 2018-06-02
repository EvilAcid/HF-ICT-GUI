#include "paintarea.h"
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>

PaintArea::PaintArea(QWidget *parent) : QWidget(parent), drawlines(false) {
	setMinimumWidth(500);
	setMinimumHeight(450);
	setMouseTracking(true);
}

void PaintArea::mousePressEvent(QMouseEvent *event) {
	qDebug() << "Mous Presset" << "x-> " << event->x() << " , " << "y-> " <<
			 event->y();
	PointsX.push_back(event->x());
	PointsY.push_back(event->y());
	update();
}

void PaintArea::reset() {
	qDebug() << "ResetButten clicked...";
	PointsX.clear();
	PointsY.clear();
	drawlines = false;
	update();
}

void PaintArea::paint() {
	qDebug() << "PaintButten clicked..." << "Pints = " <<
			 PointsX.count();
	drawlines = true;
	update();
}

void PaintArea::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	painter.setPen(Qt::white);
	for (int i(0); i < PointsX.length(); i++) {
		painter.drawPoint(PointsX.at(i), PointsY.at(i));
	}
	if (drawlines) {
		for (int i(0); i < PointsX.length() - 1; i++) {
			painter.drawLine(PointsX.at(i), PointsY.at(i), PointsX.at(i + 1),
							 PointsY.at(i + 1));
		}
		painter.drawLine(PointsX.at(PointsX.size() - 1),
						 PointsY.at(PointsY.size() - 1),
						 PointsX.at(0), PointsY.at(0));
		drawlines = false;
	}
}
