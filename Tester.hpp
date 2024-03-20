#pragma once

#include <QObject>
#include <QTimer>

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(QObject *parent = nullptr);

    void updateTests();
    void testBlockGeneration();

private:
    QTimer *m_update;
};
