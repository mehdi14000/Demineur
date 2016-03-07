#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <iostream>
#include "../main/include/gridwidget.h"
#include "../main/include/mediator.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

public slots:

    void action_Triggerred(QAction*);
    void call_setSize();

private:

    QMenuBar* _barMenu;
    QSpinBox* _row;
    QSpinBox* _column;
    QSpinBox* _mine;
    QWidget*  _simpleWidget;
    GridWidget* _grid;
    Mediator* _mediator;

};

#endif // MAINWINDOW_H
