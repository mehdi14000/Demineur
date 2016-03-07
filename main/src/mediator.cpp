#include "../include/mediator.h"

Mediator::Mediator(QObject *parent) :
    QObject(parent)
{
    _time=new QTime(0,0,0,0);
    _timer=new QTimer(this);
    _timer->setInterval(1000);
    _timer->start();

}

QTimer* Mediator::getTimer(){

    return _timer;
}

void Mediator::registerGridWidget(GridWidget* gridWidget){

    _gridWidget=gridWidget;
}

void Mediator::registerSmileyButton(QPushButton* smileyButton){

    _smileyButton=smileyButton;

}

void Mediator::registerTimeDisplay(QLineEdit* timeDisplay){

    _timeDisplay=timeDisplay;

}

void Mediator::setTimeText(){

    _timeDisplay->setText((_time->addSecs(1)).toString());

}
