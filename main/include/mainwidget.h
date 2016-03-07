#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QMenuBar>

class MainWidget : public QMainWindow
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);

public slots:

private:

    QMenuBar* _barMenu;
    QMenu*    _fileMenu;
    QMenu*    _levelMenu;
    QMenu*    _helpMenu;
    QWidget*  _simpleWidget;

};

#endif // MAINWIDGET_H
