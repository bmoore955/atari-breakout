#pragma once

#include <QObject>
#include <QDebug>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 600

class BlockGenerator : public QObject
{
    Q_OBJECT
private:
    explicit BlockGenerator(QObject *parent = nullptr);
    static BlockGenerator* m_instance;

public:
    static BlockGenerator* getInstance();

    void doSomething() {
        qDebug() << "hello";
    }
};
