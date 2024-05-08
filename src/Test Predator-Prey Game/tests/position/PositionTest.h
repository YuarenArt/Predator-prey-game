#pragma once

#include <QTest>

class PositionTest : public QObject
{
    Q_OBJECT

public:
    PositionTest() {};

private slots:
    void testConstructor();
    void testGetPosition();
    void testSetPosition();
    void testGenerateRandomPosition();
    void testEqualityOperator();
    void testInequalityOperator();
    void testSubtractionOperator();
    void testMoveFunctions();
};