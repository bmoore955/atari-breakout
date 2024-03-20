#include "Tester.hpp"

Tester::Tester(Blocks *blocks, QObject *parent)
    : QObject{parent}
    , m_blocks(blocks)
    , m_blockGenTestCounter(0)
{
    m_updateTimer = new QTimer(this);
    connect(m_updateTimer, &QTimer::timeout, this, &Tester::updateTests);
    m_updateTimer->start(1000);
}

void Tester::updateTests()
{
    testBlockGeneration();
}

void Tester::testBlockGeneration()
{
    m_blockGenTestCounter++;
    if (m_blockGenTestCounter == 3) {
        m_blocks->getNewRows();
        m_blockGenTestCounter = 0;
    }
}
