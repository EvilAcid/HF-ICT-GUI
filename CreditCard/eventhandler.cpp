#include "eventhandler.h"

#include <QDebug>

EventHandler::EventHandler() {
}

void EventHandler::onButtonClicked() {
	qDebug() << "Check Button gedrückt";
	emit samplesignal();
}
