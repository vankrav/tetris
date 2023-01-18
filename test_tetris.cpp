#include <QtTest>
#

// add necessary includes here

class Test_Tetris : public QObject
{
    Q_OBJECT

public:
    Test_Tetris();
    ~Test_Tetris();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

Test_Tetris::Test_Tetris()
{

}

Test_Tetris::~Test_Tetris()
{

}

void Test_Tetris::initTestCase()
{

}

void Test_Tetris::cleanupTestCase()
{

}

void Test_Tetris::test_case1()
{

}

QTEST_MAIN(Test_Tetris)

#include "tst_test_tetris.moc"
