#include "BlockGenerator.hpp"

BlockGenerator::BlockGenerator(QObject *parent)
    : QObject{parent}
{}

BlockGenerator* BlockGenerator::getInstance() {
    static BlockGenerator* instance = new BlockGenerator();
    return instance;
}

QList<int> BlockGenerator::generateRow()
{
    QList<int> lengths;
    int averageLength = 75;
    int spacing = 2;
    int total = 0;

    while (total + averageLength < SCREEN_WIDTH)
    {
        int next = averageLength + QRandomGenerator::global()->bounded(-25, 26);
        lengths.append(next);
        total += (next + spacing);
    }

    return lengths;
}
