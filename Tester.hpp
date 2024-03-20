#pragma once

#include <QObject>
#include <QTimer>
#include "Blocks.hpp"

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(Blocks *blocks, QObject *parent = nullptr);

    void updateTests();
    void testBlockGeneration();

private:
    Blocks *m_blocks;
    QTimer *m_update;
};
