#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QTime>
#include <QTimer>
#include "../include/gridwidget.h"

class Mediator : public QObject
{
    Q_OBJECT
public:

    explicit Mediator(QObject *parent = 0);
    void registerGridWidget(GridWidget*);
    void registerSmileyButton(QPushButton*);
    void registerTimeDisplay(QLineEdit*);
    void setTimeText();
    QTimer* getTimer();

signals:

public slots:

private:

    QPushButton* _smileyButton;
    QLineEdit* _timeDisplay;
    QTime* _time;
    QTimer* _timer;
    GridWidget* _gridWidget;

};

#endif // MEDIATOR_H
