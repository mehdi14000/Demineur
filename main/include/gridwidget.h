#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QToolButton>
#include <QDebug>

class GridWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GridWidget(QWidget *parent = 0, int ligne=0, int colonne=0);
    explicit GridWidget(const GridWidget&);

    QGridLayout* getGrille();
    QWidget* posButton(int ,int);

    int getRow();
    int getColumn();
    void saveCurrentSize();
    void setNbRow(int);
    void setNbColumns(int);
    void setNbButton();
    void setSize(int,int);

public slots:

private:

    QGridLayout* _grille;
    QToolButton* _buttons;
    int _nbcolumn;
    int _nbrow;
    int _nbbutton;

};

#endif // GRIDWIDGET_H
