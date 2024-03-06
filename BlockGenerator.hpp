#pragma once

#include <QObject>
#include <QList>
#include <QRandomGenerator>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 600

class BlockGenerator : public QObject
{
    Q_OBJECT

private:
    explicit BlockGenerator(QObject *parent = nullptr);

public:
    static BlockGenerator* getInstance();

    QList<int> generateRow();

private:
    static BlockGenerator* m_instance;
};
