#include "./include/mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(336,336);
    setWindowTitle("Démineur");

    _simpleWidget=new QWidget(this);
    _barMenu=new QMenuBar(_simpleWidget);
    _mediator=new Mediator(this);

    QMenu* fileMenu=new QMenu("File",this);
    QMenu* levelMenu=new QMenu("Level",this);
    QMenu* helpMenu=new QMenu("Help",this);

    QActionGroup* level=new QActionGroup(this);

    QAction* level1=new QAction("8x8 grid,10 mines",this);
    QAction* level2=new QAction("16x16 grid,25 mines",this);
    QAction* level3=new QAction("32x32 grid,100 mines",this);
    QAction* game=new QAction("New Game",this);
    QAction* quit=new QAction("Quit",this);
    QAction* help=new QAction("Hint",this);
    QAction* aboutDem=new QAction("About Demineur",this);

    level1->setData("grid8");
    level2->setData("grid16");
    level3->setData("grid32");
    game->setData("game");
    help->setData("hint");
    quit->setData("quit");
    aboutDem->setData("about");

    level->setExclusive(true);
    level1->setCheckable(true);
    level2->setCheckable(true);
    level3->setCheckable(true);

    levelMenu->addAction(level1);
    levelMenu->addAction(level2);
    levelMenu->addAction(level3);
    fileMenu->addAction(game);
    fileMenu->addAction(quit);
    helpMenu->addAction(help);
    helpMenu->addAction(aboutDem);

    level->addAction(level1);
    level->addAction(level2);
    level->addAction(level3);
    level->addAction(game);
    level->addAction(quit);
    level->addAction(help);
    level->addAction(aboutDem);

    _barMenu->addMenu(fileMenu);
    _barMenu->addMenu(levelMenu);
    _barMenu->addMenu(helpMenu);
    setMenuBar(_barMenu);

    _row=new QSpinBox(_simpleWidget);
    _column=new QSpinBox(_simpleWidget);
    _mine=new QSpinBox(_simpleWidget);
    _row->setRange(4,32);
    _column->setRange(4,32);
    _mine->setRange(0,100);

    QHBoxLayout* h_layout=new QHBoxLayout();

    QLabel* rows=new QLabel("Rows");
    QLabel* columns=new QLabel("Columns");
    QLabel* mines=new QLabel("Mines");
    QPushButton* button=new QPushButton;
    button->setIcon(QIcon("../main/img/happy.png"));
    button->setIconSize(QSize(30,30));


    h_layout->addWidget(rows);
    h_layout->addWidget(_row);
    h_layout->addWidget(columns);
    h_layout->addWidget(_column);
    h_layout->addWidget(mines);
    h_layout->addWidget(_mine);
    h_layout->addWidget(button);

    QHBoxLayout* h_layout2=new QHBoxLayout();

    QLabel* timeText=new QLabel("Time :");
    QLineEdit*chrono=new QLineEdit("00:00:00",this);
    chrono->setReadOnly(true);
    chrono->setMaximumSize(300,25);

    h_layout2->addWidget(timeText);
    h_layout2->addWidget(chrono);

    QVBoxLayout* v_layout=new QVBoxLayout();

    _grid=new GridWidget(this,4,4);

    v_layout->addLayout(h_layout);
    v_layout->addWidget(_grid);
    v_layout->addLayout(h_layout2);

    _simpleWidget->setLayout(v_layout);
    _simpleWidget->setLayout(h_layout);
    _simpleWidget->setLayout(h_layout2);

    connect(level,SIGNAL(triggered(QAction*)),this,SLOT(action_Triggerred(QAction*)));
    connect(button,SIGNAL(clicked()),this,SLOT(call_setSize()));

    setMenuBar(_barMenu);
    setCentralWidget(_simpleWidget);
}

void MainWindow::action_Triggerred(QAction* action){

    QVariant data=action->data();
    if(data=="grid8"){
        _row->setValue(8);
        _column->setValue(8);
        _mine->setValue(10);
    }
    if(data=="grid16"){
        _row->setValue(16);
        _column->setValue(16);
        _mine->setValue(32);
    }
    if(data=="grid32"){
        _row->setValue(32);
        _column->setValue(32);
        _mine->setValue(100);
    }
    if(data=="about"){
        QMessageBox* message=new QMessageBox(this);
        message->setText("Minesweeper++ Réalisé en 2016 par Mehdi Crozes et Sara Mourad");
        message->show();
    }
    if(data=="game"){

    }
    if(data=="hint"){

    }
    if(data=="quit"){
        close();
    }
}

void MainWindow::call_setSize(){

    _grid->setSize(_row->value(),_column->value());

}
