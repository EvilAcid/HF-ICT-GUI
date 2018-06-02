#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class EventHandler : public QObject {
	Q_OBJECT

  public:
	EventHandler();
  public slots:
	void onButtonClicked();
  signals:
	void samplesignal();
	void cardNumberValid();
	void cardNumberNotValid();
};

#endif // EVENTHANDLER_H
