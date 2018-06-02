#ifndef PAINTAREA_H
#define PAINTAREA_H
#include <QObject>
#include <QWidget>
#include <QVector>

class PaintArea : public QWidget {
	Q_OBJECT
  private:
	QVector<int> PointsX;
	QVector<int> PointsY;
	bool drawlines;

  public:
	explicit PaintArea(QWidget *parent = nullptr);
	void mousePressEvent(QMouseEvent *event);

  signals:

  public slots:
	void reset();
	void paint();
	void paintEvent(QPaintEvent *event);

};

#endif // PAINTAREA_H
