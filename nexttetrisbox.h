/*!
\file
\brief Заголовочный файл для поля следующей фигуры
*/
#ifndef NEXTTETRISBOX_H
#define NEXTTETRISBOX_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPalette>
#include <QPen>
#include <QBrush>
#include <QColor>

#include "tetris.h"

#define KX (MAXX-NEXTMAXX) / 2
#define KY 4


/*!
\brief Класс для окна следующей фигуры
*/
class NextTetrisBox : public QWidget {
    Q_OBJECT
public:
    explicit NextTetrisBox(QWidget *parent = nullptr);
    void updateNextTetris(Tetris tetris); ///< обновить окно
    void paintEvent(QPaintEvent *event); ///< нарисовать окно

signals:

public slots:

private:
    Block nextBlock;
};

#endif // NEXTTETRISBOX_H
