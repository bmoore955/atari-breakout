#pragma once

#include <QObject>
#include <QDebug>
#include <QList>
#include <QTimer>
#include "BlockGenerator.hpp"

class Blocks : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<int> row1 READ row1 WRITE setRow1 NOTIFY row1Changed)
public:
    explicit Blocks(QObject *parent = nullptr);

    Q_INVOKABLE QList<int> getRow();

    QList<int> row1() const;
    void setRow1(const QList<int> newRow1);

signals:
    void row1Changed();
private:
    QList<int> m_row1;
};
