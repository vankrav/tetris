/*!
\file
\brief Заголовочный файл с описанием поля игры
*/
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
/*!
    \brief  Класс реализующий визуализацию окна игры


*/
class TetrisBox : public QWidget {
  Q_OBJECT

public:
    explicit TetrisBox(QWidget *parent = nullptr);
    void updateTetris(Tetris tetris); ///< обновить состояние игры
    void paintEvent(QPaintEvent *event); ///< нарисовать поле

signals:

public slots:

private:
    Block block;
    int box[MAXX][MAXY];
};

#endif // TETRISBOX_H
