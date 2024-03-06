#pragma once

#include <QObject>
#include <QList>

class BlockGenerator : public QObject
{
    Q_OBJECT
public:
    static BlockGenerator* getInstance();

signals:

private:
    explicit BlockGenerator(QObject *parent = nullptr);

    QList<int> generateRow();

    BlockGenerator* m_instance;
};
