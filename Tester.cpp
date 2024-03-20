#include "Tester.hpp"

Tester::Tester(Blocks *blocks, QObject *parent)
    : QObject{parent}
    , m_blocks(blocks)
{
    m_update = new QTimer(this);
    connect(m_update, &QTimer::timeout, this, &Tester::updateTests);
    m_update->start(1000);
}

void Tester::updateTests()
{
    testBlockGeneration();
}

void Tester::testBlockGeneration()
{
    m_blocks->getNewRows();
}
