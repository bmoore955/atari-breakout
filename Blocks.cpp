#include "Blocks.hpp"

Blocks::Blocks(QObject *parent)
    : QObject{parent}
{
    m_row1.clear();
    m_row2.clear();
    m_row3.clear();
    m_row4.clear();

    getNewRows();
}

void Blocks::getNewRows()
{
    setRow1(BlockGenerator::getInstance()->generateRow());
    setRow2(BlockGenerator::getInstance()->generateRow());
    setRow3(BlockGenerator::getInstance()->generateRow());
    setRow4(BlockGenerator::getInstance()->generateRow());
}

QList<int> Blocks::row1() const
{
    return m_row1;
}

void Blocks::setRow1(const QList<int> newRow1)
{
    if (m_row1 == newRow1)
        return;
    m_row1 = newRow1;
    emit row1Changed();
}

QList<int> Blocks::row2() const
{
    return m_row2;
}

void Blocks::setRow2(const QList<int> newRow2)
{
    if (m_row2 == newRow2)
        return;
    m_row2 = newRow2;
    emit row2Changed();
}

QList<int> Blocks::row3() const
{
    return m_row3;
}

void Blocks::setRow3(const QList<int> newRow3)
{
    if (m_row3 == newRow3)
        return;
    m_row3 = newRow3;
    emit row3Changed();
}

QList<int> Blocks::row4() const
{
    return m_row4;
}

void Blocks::setRow4(const QList<int> newRow4)
{
    if (m_row4 == newRow4)
        return;
    m_row4 = newRow4;
    emit row4Changed();
}
