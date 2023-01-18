
/*!
\file
\brief Заголовочный файл для главного окна
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QKeyEvent>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QScreen>
#include <QPixmap>
#include <QApplication>
#include "tetris.h"
#include "tetrisbox.h"
#include "nexttetrisbox.h"


#define STATUS_ON 0 // игра идет
#define STATUS_PAUSE 1 //пауза
#define STATUS_OFF 2 // игра не начата
#define STATUS_END 3 // игра кончилась

/*!
\brief Класс для главного окна

*/
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);///<обработчик нажатий клавиш на клавиатуре
    void changeEvent(QKeyEvent *event); ///<пауза при сворачивании окна
    void updateScore();///< обновить счет


public slots:
    void onTimer();
private:

    int status;
    Tetris tetris;
    QTimer *timer;
    TetrisBox *tetrisBox;
    NextTetrisBox *nextTetrisBox;
    QGridLayout *mainLayout;
    QLabel *scoreLabel;
    QLabel *aboutLabel;
    QLabel *nextLabel;
    QLabel *controlLabel;





};
#endif // MAINWINDOW_H






















