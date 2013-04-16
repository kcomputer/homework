#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QWidget
{
    Q_OBJECT
    
public:
    explicit TicTacToe(QWidget *parent = 0);
    ~TicTacToe();
    bool whatNext;
    int kindaButton11;
    int kindaButton12;
    int kindaButton13;
    int kindaButton21;
    int kindaButton22;
    int kindaButton23;
    int kindaButton31;
    int kindaButton32;
    int kindaButton33;



private slots:
    void pickButton11();
    void pickButton12();
    void pickButton13();
    void pickButton21();
    void pickButton22();
    void pickButton23();
    void pickButton31();
    void pickButton32();
    void pickButton33();
    void winner();
    
private:
    Ui::TicTacToe *ui;
    QVBoxLayout *layout;
    QHBoxLayout *row1;
    QHBoxLayout *row2;
    QHBoxLayout *row3;
    QPushButton *button11;
    QPushButton *button12;
    QPushButton *button13;
    QPushButton *button21;
    QPushButton *button22;
    QPushButton *button23;
    QPushButton *button31;
    QPushButton *button32;
    QPushButton *button33;
};

#endif // TICTACTOE_H
