#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

TicTacToe::TicTacToe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    layout = new QVBoxLayout(this);
    row1 = new QHBoxLayout(this);
    row2 = new QHBoxLayout(this);
    row3 = new QHBoxLayout(this);

    button11 = new QPushButton(this);
    button12 = new QPushButton(this);
    button13 = new QPushButton(this);
    button21 = new QPushButton(this);
    button22 = new QPushButton(this);
    button23 = new QPushButton(this);
    button31 = new QPushButton(this);
    button32 = new QPushButton(this);
    button33 = new QPushButton(this);

    connect(button11,SIGNAL(clicked()),this,SLOT(pickButton11()));
    connect(button12,SIGNAL(clicked()),this,SLOT(pickButton12()));
    connect(button13,SIGNAL(clicked()),this,SLOT(pickButton13()));
    connect(button21,SIGNAL(clicked()),this,SLOT(pickButton21()));
    connect(button22,SIGNAL(clicked()),this,SLOT(pickButton22()));
    connect(button23,SIGNAL(clicked()),this,SLOT(pickButton23()));
    connect(button31,SIGNAL(clicked()),this,SLOT(pickButton31()));
    connect(button32,SIGNAL(clicked()),this,SLOT(pickButton32()));
    connect(button33,SIGNAL(clicked()),this,SLOT(pickButton33()));


    row1->addWidget(button11);
    row1->addWidget(button12);
    row1->addWidget(button13);
    row2->addWidget(button21);
    row2->addWidget(button22);
    row2->addWidget(button23);
    row3->addWidget(button31);
    row3->addWidget(button32);
    row3->addWidget(button33);


    layout->addLayout(row1);
    layout->addLayout(row2);
    layout->addLayout(row3);

    setLayout(layout);

    whatNext = true;

    kindaButton11 = 2;
    kindaButton12 = 2;
    kindaButton13 = 2;
    kindaButton21 = 2;
    kindaButton22 = 2;
    kindaButton23 = 2;
    kindaButton31 = 2;
    kindaButton32 = 2;
    kindaButton33 = 2;

}

void TicTacToe::pickButton11()
{
    if (kindaButton11 == 2){
    if (whatNext)
    {
        button11->setText("X");
        kindaButton11 = 1;
        whatNext = 0;
    }
    else
    {
        button11->setText("O");
        kindaButton11 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton12()
{
    if (kindaButton12 == 2){
    if (whatNext)
    {
        button12->setText("X");
        kindaButton12 = 1;
        whatNext = 0;
    }
    else
    {
        button12->setText("O");
        kindaButton12 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton13()
{
    if (kindaButton13 == 2){
    if (whatNext)
    {
        button13->setText("X");
        kindaButton13 = 1;
        whatNext = 0;
    }
    else
    {
        button13->setText("O");
        kindaButton13 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton21()
{
    if (kindaButton21 == 2){
    if (whatNext)
    {
        button21->setText("X");
        kindaButton21 = 1;
        whatNext = 0;
    }
    else
    {
        button21->setText("O");
        kindaButton21 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton22()
{
    if (kindaButton22 == 2){
    if (whatNext)
    {
        button22->setText("X");
        kindaButton22 = 1;
        whatNext = 0;
    }
    else
    {
        button22->setText("O");
        kindaButton22 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton23()
{
    if (kindaButton23 == 2){
    if (whatNext)
    {
        button23->setText("X");
        kindaButton23 = 1;
        whatNext = 0;
    }
    else
    {
        button23->setText("O");
        kindaButton23 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton31()
{
    if (kindaButton31 == 2){
    if (whatNext)
    {
        button31->setText("X");
        kindaButton31 = 1;
        whatNext = 0;
    }
    else
    {
        button31->setText("O");
        kindaButton31 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton32()
{
    if (kindaButton32 == 2){
    if (whatNext)
    {
        button32->setText("X");
        kindaButton32 = 1;
        whatNext = 0;
    }
    else
    {
        button32->setText("O");
        kindaButton32 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::pickButton33()
{
    if (kindaButton33 == 2){
    if (whatNext)
    {
        button33->setText("X");
        kindaButton33 = 1;
        whatNext = 0;
    }
    else
    {
        button33->setText("O");
        kindaButton33 = 0;
        whatNext = 1;
    }
    TicTacToe::winner();
    }
}

void TicTacToe::winner()
{
    if (kindaButton11 == 1 && kindaButton12 == 1 && kindaButton13 == 1)
    {
        button11->setText("1");
        button12->setText("1");
        button13->setText("1");
        qApp->quit();
    }
    if (kindaButton21 == 1 && kindaButton22 == 1 && kindaButton23 == 1)
    {
        button21->setText("1");
        button22->setText("1");
        button23->setText("1");
        qApp->quit();
    }
    if (kindaButton31 == 1 && kindaButton32 == 1 && kindaButton33 == 1)
    {
        button11->setText("1");
        button12->setText("1");
        button13->setText("1");
        qApp->quit();
    }
    if (kindaButton31 == 1 && kindaButton22 == 1 && kindaButton13 == 1)
    {
        button11->setText("1");
        button12->setText("1");
        button13->setText("1");
        qApp->quit();
    }
    if (kindaButton31 == 1 && kindaButton21 == 1 && kindaButton11 == 1)
    {
        button11->setText("1");
        button12->setText("1");
        button13->setText("1");
        qApp->quit();
    }
    if (kindaButton12 == 1 && kindaButton32 == 1 && kindaButton22 == 1)
    {
        button11->setText("1");
        button12->setText("1");
        button13->setText("1");
        qApp->quit();
    }
    if (kindaButton13 == 1 && kindaButton23 == 1 && kindaButton33 == 1)
    {
        button11->setText("1");
        button12->setText("1");
        button13->setText("1");
        qApp->quit();
    }





    if (kindaButton11 == 0 && kindaButton12 == 0 && kindaButton13 == 0)
    {
        button11->setText("2");
        button12->setText("2");
        button13->setText("2");
        qApp->quit();
    }
    if (kindaButton21 == 0 && kindaButton22 == 0 && kindaButton23 == 0)
    {
        button21->setText("2");
        button22->setText("2");
        button23->setText("2");
        qApp->quit();
    }
    if (kindaButton31 ==0 && kindaButton32 == 0 && kindaButton33 == 0)
    {
        button11->setText("2");
        button12->setText("2");
        button13->setText("2");
        qApp->quit();
    }
    if (kindaButton31 == 0 && kindaButton22 == 0 && kindaButton13 == 0)
    {
        button11->setText("2");
        button12->setText("2");
        button13->setText("2");
        qApp->quit();
    }
    if (kindaButton31 == 0 && kindaButton21 == 0 && kindaButton11 == 0)
    {
        button11->setText("2");
        button12->setText("2");
        button13->setText("2");
        qApp->quit();
    }
    if (kindaButton12 == 0 && kindaButton32 == 0 && kindaButton22 == 0)
    {
        button11->setText("2");
        button12->setText("2");
        button13->setText("2");
        qApp->quit();
    }
    if (kindaButton13 == 0 && kindaButton23 == 0 && kindaButton33 == 0)
    {
        button11->setText("2");
        button12->setText("2");
        button13->setText("2");
        qApp->quit();
    }


}

TicTacToe::~TicTacToe()
{
    delete ui;
}
