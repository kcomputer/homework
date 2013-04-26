#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

#include <QWidget>
#include <QStack>

#include <QLCDNumber>
#include <QPushButton>
#include <QSignalMapper>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
    QPushButton* createButton(const QString& str);
    void calculate();
public slots:
    void slotButtonClicked(const QString &str);
    
private:
    Ui::Calculator *ui;
    QSignalMapper *signalMapper;
    QLCDNumber*     m_plcd;
    QStack<QString> m_stk;
    QString         m_strDisplay;
};

#endif // CALCULATOR_H
