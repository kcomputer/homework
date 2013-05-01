#include "calculator.h"
#include "ui_calculator.h"
#include <QGridLayout>

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    m_plcd = new QLCDNumber(12);
    m_plcd->setSegmentStyle(QLCDNumber::Flat);
    m_plcd->setMinimumSize(150, 50);

    QChar aButtons[4][4] = {{'7', '8', '9', '/'},
                            {'4', '5', '6', '*'},
                            {'1', '2', '3', '-'},
                            {'0', '.', '=', '+'}
                           };

    signalMapper = new QSignalMapper(this);
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(m_plcd, 0, 0, 1, 4);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
           ptopLayout->addWidget(createButton(aButtons[i][j]), i + 2, j);
        }
    }
    connect(signalMapper, SIGNAL(mapped(const QString &)),
            this, SLOT(slotButtonClicked(const QString &)));
    setLayout(ptopLayout);
}


QPushButton* Calculator::createButton(const QString& str)
{
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40, 40);
    connect(pcmd, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(pcmd, str);
    return pcmd;
}



void Calculator::slotButtonClicked(const QString& str)
{
    if (str.contains(QRegExp("[0-9]"))) {

        m_strDisplay += str;
        m_plcd->display(m_strDisplay.toDouble());
    }
    else if (str == ".") {
        m_strDisplay += str;
        m_plcd->display(m_strDisplay);
    }
    else {
        if (m_stk.count() == 2)
        {
            double dOperand2 = m_plcd->value();
            QString strOperation = m_stk.pop();
            double  dOperand1    = m_stk.pop().toDouble();
            m_plcd->display(calculate(dOperand1, strOperation, dOperand2));
            m_stk.clear();
            m_stk.push(QString().setNum(m_plcd->value()));
            if (str != "=")
            {
                m_stk.push(str);
            }
            m_strDisplay.clear();
        }
        else
        {
            m_stk.push(QString().setNum(m_plcd->value()));
            m_stk.push(str);

            m_strDisplay.clear();
        }
    }
}



Calculator::~Calculator()
{
    delete ui;
}
