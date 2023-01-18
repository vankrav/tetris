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
#include "menu.h"


#define STATUS_ON 0 // игра идет
#define STATUS_PAUSE 1 //пауза
#define STATUS_OFF 2 // игра не начата
#define STATUS_END 3 // игра кончилась


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void changeEvent(QKeyEvent *event);
    void updateScore();
    void updateStatusLabel(int state);

public slots:
    void onTimer();
    void onClick();

private:

    int status;
    Tetris tetris;

    QTimer *timer;
    TetrisBox *tetrisBox;
    NextTetrisBox *nextTetrisBox;
    Menu * menu;
    QGridLayout *mainLayout;
    QLabel *scoreLabel;
    QLabel *statusLabel;




};
#endif // MAINWINDOW_H






















