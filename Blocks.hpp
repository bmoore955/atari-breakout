#pragma once

#include <QObject>
#include <QList>
#include "BlockGenerator.hpp"

class Blocks : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<int> row1 READ row1 WRITE setRow1 NOTIFY row1Changed FINAL)
    Q_PROPERTY(QList<int> row2 READ row2 WRITE setRow2 NOTIFY row2Changed FINAL)
    Q_PROPERTY(QList<int> row3 READ row3 WRITE setRow3 NOTIFY row3Changed FINAL)
    Q_PROPERTY(QList<int> row4 READ row4 WRITE setRow4 NOTIFY row4Changed FINAL)
public:
    explicit Blocks(QObject *parent = nullptr);

    // Get new randomized values for all 4 rows
    void getNewRows();

    // Get/Set the saved lengths for each row
    QList<int> row1() const;
    void setRow1(const QList<int> newRow1);

    QList<int> row2() const;
    void setRow2(const QList<int> newRow2);

    QList<int> row3() const;
    void setRow3(const QList<int> newRow3);

    QList<int> row4() const;
    void setRow4(const QList<int> newRow4);

signals:
    void row1Changed();
    void row2Changed();
    void row3Changed();
    void row4Changed();

private:
    QList<int> m_row1;
    QList<int> m_row2;
    QList<int> m_row3;
    QList<int> m_row4;
};
