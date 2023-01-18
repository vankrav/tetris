/*!
\file
\brief Тесты для логики игры
*/

#include <QtTest>
#include "../tetris.h"
// add necessary includes here

class Test_Tetris : public QObject
{
    Q_OBJECT

public:
    Test_Tetris();
    Tetris t;

private slots:
    void bestScore();
    void move();



};

Test_Tetris::Test_Tetris()
{

}


void Test_Tetris::bestScore()
{
    Tetris t;

    QCOMPARE(t.bestScore(10), 10);
    QCOMPARE(t.bestScore(11), 11);
    QCOMPARE(t.bestScore(9), 11);
    QCOMPARE(t.bestScore(6), 11);

}

void Test_Tetris::move()
{

    Tetris t;
    int x = t.getBlock().centerX;
    int y = t.getBlock().centerY;

    t.moveToBottom();





}

QTEST_APPLESS_MAIN(Test_Tetris)

#include "tst_test_tetris.moc"
