#include "BlockGenerator.hpp"

BlockGenerator* BlockGenerator::m_instance = nullptr;

BlockGenerator* BlockGenerator::getInstance() {
    if (m_instance == nullptr)
        m_instance = new BlockGenerator();
    return m_instance;
}

BlockGenerator::BlockGenerator(QObject *parent)
    : QObject{parent}
{}

QList<int> BlockGenerator::generateRow()
{
    QList<int> lengths;
    int averageLength = 60;
    int variance = 35;
    int spacing = 2;
    int total = 0;

    while (total + averageLength < SCREEN_WIDTH)
    {
        int next = averageLength + QRandomGenerator::global()->bounded(-variance, variance + 1);
        lengths.append(next);
        total += (next + spacing);
    }

    if (SCREEN_WIDTH - total >= averageLength - variance)
    lengths.append(SCREEN_WIDTH - total);
    else {
        int fill = smallestBlock(lengths);
        lengths.replace(fill, lengths.at(fill) + SCREEN_WIDTH - total);
    }

    return lengths;
}

int BlockGenerator::smallestBlock(QList<int> row)
{
    int smallest = row.at(0);
    int smallestIndex = 0;
    for (int i = 0; i < row.size(); i++) {
        if (row.at(i) < smallest) {
            smallest = row.at(i);
            smallestIndex = i;
        }
    }
    return smallestIndex;
}
