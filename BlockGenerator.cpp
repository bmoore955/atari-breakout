#include "BlockGenerator.hpp"

BlockGenerator::BlockGenerator(QObject *parent)
    : QObject{parent}
{}

BlockGenerator* BlockGenerator::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new BlockGenerator();
    }
    return m_instance;
}

QList<int> BlockGenerator::generateRow()
{
    return {};
}
