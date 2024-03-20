#pragma once

#include <QObject>
#include <QTimer>
#include "Blocks.hpp"

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(Blocks *blocks, QObject *parent = nullptr);

    // Call all test functions.
    void updateTests();

    // TEST FUNCTIONS
    // Regenerate all blocks to make sure layouts always look good
    void testBlockGeneration();

private:
    Blocks *m_blocks;
    QTimer *m_updateTimer;

    // Test function time counters
    int m_blockGenTestCounter;
};
