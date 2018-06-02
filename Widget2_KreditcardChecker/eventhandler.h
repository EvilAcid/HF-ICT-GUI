#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class MainWidget;

class EventHandler : public QObject {
	Q_OBJECT

  private:
	MainWidget *parent;


  public:
	EventHandler(MainWidget *parent);


  public slots:
	void onCheckButtonClicked();

};

#endif // EVENTHANDLER_H
