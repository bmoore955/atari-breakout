#include "Blocks.hpp"

Blocks::Blocks(QObject *parent)
    : QObject{parent}
{
    m_row1.clear();

    QTimer::singleShot(1000, [=]() {
        setRow1(getRow());
    });
}

QList<int> Blocks::getRow()
{
    return BlockGenerator::getInstance()->generateRow();
}

QList<int> Blocks::row1() const
{
    return m_row1;
}

void Blocks::setRow1(const QList<int> newRow1)
{
    if (m_row1 == newRow1)
        return;
    qDebug() << newRow1;
    m_row1 = newRow1;
    emit row1Changed();
}
