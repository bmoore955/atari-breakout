#include "BlockGenerator.hpp"

BlockGenerator* BlockGenerator::m_instance = nullptr;

BlockGenerator::BlockGenerator(QObject *parent)
    : QObject{parent}
{}

BlockGenerator* BlockGenerator::getInstance() {
    if (m_instance == nullptr)
    {
        m_instance = new BlockGenerator();
    }
    return m_instance;
}
