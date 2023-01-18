#ifndef MENU_H
#define MENU_H

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
#include <QPushButton>
#include "tetris.h"






class Menu : public QWidget {
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    QPushButton *middleLevelButton;
    QPushButton *hardLevelButton;
    QPushButton *easyLevelButton;
    QGridLayout *menuLayout;
signals:

public slots:


private:
    QLabel *gameNameLabel;
    QLabel *missionLabel;
    QLabel *controlLabel;
    QLabel *scoreLabel;
    QLabel *difficultLabel;






};

#endif // MENU_H
