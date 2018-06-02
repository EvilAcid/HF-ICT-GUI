#include "eventhandler.h"
#include "mainwidget.h"

#include <QDebug>

EventHandler::EventHandler(MainWidget *parent) :
	parent(parent) {
}


void EventHandler::onCheckButtonClicked() {
	qDebug() << "Checkbutten cklicked";
}


