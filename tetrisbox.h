#ifndef TETRISBOX_H
#define TETRISBOX_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPalette>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QLabel>

#include "tetris.h"

class TetrisBox : public QWidget {
  Q_OBJECT

public:
    explicit TetrisBox(QWidget *parent = nullptr);
    void updateTetris(Tetris tetris); // обновить
    void paintEvent(QPaintEvent *event); // нарисовать

signals:

public slots:

private:
    Block block;
    int box[MAXX][MAXY];
};

#endif // TETRISBOX_H
