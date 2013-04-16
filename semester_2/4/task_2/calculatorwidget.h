#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H
#include "calculator.h"

#include <QMainWindow>

namespace Ui {
class CalculatorWidget;
}

class CalculatorWidget : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CalculatorWidget(QWidget *parent = 0);
    ~CalculatorWidget();
signals:
    void value(QString);

public slots:
    void left(int);
    void oper(const QString&);
    void right(int);
    void sender();



private:
    Ui::CalculatorWidget *ui;
    int m_left;
    char m_oper;
    int m_right;

};

#endif // CALCULATORWIDGET_H
