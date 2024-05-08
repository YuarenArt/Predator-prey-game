#include "PositionTest.h"
#include "../../../../position/Position.h"

#include <QVector>

void PositionTest::testConstructor() {
    Position position(5, 6);
    QCOMPARE(position.getPosition().getRow(), 5);
    QCOMPARE(position.getPosition().getColumn(), 6);
}

void PositionTest::testGetPosition() {
    Position position(5, 6);
    QCOMPARE(position.getPosition().getRow(), 5);
    QCOMPARE(position.getPosition().getColumn(), 6);
}

void PositionTest::testSetPosition() {
    Position position;
    position.setPosition(5, 6);
    QCOMPARE(position.getPosition().getRow(), 5);
    QCOMPARE(position.getPosition().getColumn(), 6);
}

void PositionTest::testGenerateRandomPosition() {
    // This test is non-deterministic due to the random nature of the function
    // We can only check that the generated values are within the bounds
    Position position = Position::generateRandomPosition(10, 10);
    QVERIFY(position.getPosition().getRow() >= 0 && position.getPosition().getRow() < 10);
    QVERIFY(position.getPosition().getColumn() >= 0 && position.getPosition().getColumn() < 10);
}

void PositionTest::testEqualityOperator() {
    Position position1(5, 6);
    Position position2(5, 6);
    Position position3(7, 6);
    QVERIFY(position1 == position2);
    QVERIFY(!(position1 == position3));
}

void PositionTest::testInequalityOperator() {
    Position position1(5, 6);
    Position position2(5, 6);
    Position position3(7, 6);
    QVERIFY(!(position1 != position2));
    QVERIFY(position1 != position3);
}

void PositionTest::testSubtractionOperator() {
    Position position1(5, 6);
    Position position2(7, 8);
    Position result = position1 - position2;
    QCOMPARE(result.getPosition().getRow(), 0);
    QCOMPARE(result.getPosition().getColumn(), 0);
}

void PositionTest::testMoveFunctions() {
    Position position(5, 6);
    position.moveUp();
    QCOMPARE(position.getPosition().getRow(), 4);
    QCOMPARE(position.getPosition().getColumn(), 6);

    position.moveDown();
    QCOMPARE(position.getPosition().getRow(), 5);
    QCOMPARE(position.getPosition().getColumn(), 6);

    position.moveLeft();
    QCOMPARE(position.getPosition().getRow(), 5);
    QCOMPARE(position.getPosition().getColumn(), 5);

    position.moveRight();
    QCOMPARE(position.getPosition().getRow(), 5);
    QCOMPARE(position.getPosition().getColumn(), 6);

    position.moveUpLeft();
    QCOMPARE(position.getPosition().getRow(), 4);
    QCOMPARE(position.getPosition().getColumn(), 5);

    position.moveUpRight();
    QCOMPARE(position.getPosition().getRow(), 3);
    QCOMPARE(position.getPosition().getColumn(), 6);

    position.moveDownLeft();
    QCOMPARE(position.getPosition().getRow(), 3);
    QCOMPARE(position.getPosition().getColumn(), 5);

    position.moveDownRight();
    QCOMPARE(position.getPosition().getRow(), 4);
    QCOMPARE(position.getPosition().getColumn(), 6);
}