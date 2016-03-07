#include "./include/gridwidget.h"

GridWidget::GridWidget(QWidget *parent,int nbligne,int nbcolonne):
    QWidget(parent)
{
    _grille=new QGridLayout(this);
     setNbRow(nbligne);
     setNbColumns(nbcolonne);
     setNbButton();
    _buttons=new QToolButton[_nbbutton];
    _buttons->Si
    int k=0;
    for(int i=0;i<_nbrow;i++){
        for(int j=0;j<_nbcolumn;j++){
            _grille->addWidget(&_buttons[k],i,j);
            k++;
        }
    }
}

GridWidget::GridWidget(const GridWidget & gridWidget){

    _nbcolumn=gridWidget._nbcolumn;
    _nbrow=gridWidget._nbrow;
    _nbbutton=_nbrow*_nbcolumn;
    _buttons=new QToolButton[_nbcolumn*_nbrow];
    memcpy(_buttons,gridWidget._buttons,_nbcolumn*_nbrow*sizeof(QToolButton));

}


QGridLayout* GridWidget::getGrille(){

    return _grille;
}

int GridWidget::getColumn(){

    return _nbcolumn;
}

int GridWidget::getRow(){

    return _nbrow;
}

void GridWidget::setNbColumns(int colonne){

    _nbcolumn=colonne;
}

void GridWidget::setNbRow(int row){

    _nbrow=row;
}

void GridWidget::setNbButton(){

    _nbbutton=_nbcolumn*_nbrow;
}

QWidget* GridWidget::posButton(int nbligne,int nbcolonne){

    QLayoutItem* button=_grille->itemAtPosition(nbligne,nbcolonne);
    return button->widget();
}

void GridWidget:: saveCurrentSize(){

    _nbcolumn=_grille->columnCount();
    _nbrow=_grille->rowCount();
}

void GridWidget::setSize(int nbligne,int nbcolonne){

     delete[] _buttons;

     setNbColumns(nbcolonne);
     setNbRow(nbligne);
     setNbButton();
     int cpt=0;
     _buttons=new QToolButton[_nbbutton];
     for(int i=0;i<_nbrow;i++){
        for(int j=0;j<_nbcolumn;j++){
            _grille->addWidget(&_buttons[cpt],i,j);
            cpt++;
        }
    }
}


