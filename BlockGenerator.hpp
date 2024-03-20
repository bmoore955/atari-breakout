#pragma once

#include <QObject>
#include <QList>
#include <QRandomGenerator>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 600

class BlockGenerator : public QObject
{
    Q_OBJECT    
public:
    static BlockGenerator* getInstance();

    // Generates a randomized list of lengths for blocks
    QList<int> generateRow();
    // Finds the smallest value in a list of lengths
    int smallest(QList<int> row);

private:
    explicit BlockGenerator(QObject *parent = nullptr);
    static BlockGenerator* m_instance;
};
