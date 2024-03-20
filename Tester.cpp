#include "Tester.hpp"

Tester::Tester(QObject *parent)
    : QObject{parent}
{
    m_update = new QTimer(this);
    connect(m_update, &QTimer::timeout, this, &Tester::updateTests);
}

void Tester::updateTests() {}
