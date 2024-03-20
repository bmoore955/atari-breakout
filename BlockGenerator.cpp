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
    // Configuration for the row
    // TODO: allow these values to be passed in for increased customization
    int averageLength = 60;
    int variance = 35;
    int spacing = 2;

    QList<int> lengths;
    int total = 0;

    // Creates random blocks for the whole row except the last block
    while (total + averageLength < SCREEN_WIDTH)
    {
        // The range of values is [averageLength - variance, averageLength + variance]
        int next = averageLength + QRandomGenerator::global()->bounded(-variance, variance + 1);
        lengths.append(next);
        total += (next + spacing); // Track how much of the screen width has been filled
    }

    // If the space left in the row is at least as big as the minimum block length,
    // then make the space left into one block to complete the row
    if (SCREEN_WIDTH - total >= averageLength - variance) {
        lengths.append(SCREEN_WIDTH - total);
    }
    // If there isn't enough space for the minimum length,
    // replace the smallest block with a bigger one to fill the space
    else {
        int fill = smallest(lengths);
        lengths.replace(fill, lengths.at(fill) + SCREEN_WIDTH - total);
    }

    return lengths;
}

int BlockGenerator::smallest(QList<int> row)
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
