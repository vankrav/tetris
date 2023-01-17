#include "tetrisbox.h"

TetrisBox::TetrisBox(QWidget *parent) : QWidget(parent) {

    //инициализируем блок

    for (int i = 0; i < COUNT; i++) {
        block.x[i] = -1;
        block.y[i] = -1;
    }
    block.centerX = -1;
    block.centerY = -1;
    block.ID = -1;

    //инициализируем поле
    for (int i = 0; i < MAXX; i++) {
       for(int j = 0; j < MAXY; j++) {
           box[i][j] = 0;
       }
    }

    //размеры игрового окна
    int w = Tetris::getWidth();
    int h = Tetris::getHeight();
    setFixedSize(w, h);
    setPalette(QPalette(Qt::black));
    setAutoFillBackground(true);
}


void TetrisBox::updateTetris(Tetris tetris) {
    block = tetris.getBlock(); // обновить блок
    for (int i = 0; i < MAXX; i++) {
       for(int j = 0; j < MAXY; j++) {
           box[i][j] = tetris.getBox(i,j);// обновить бокс
       }
    }
    repaint();
}

void TetrisBox::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    QPen pen;
    QBrush brush;

    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(255, 255, 255));

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(255, 255, 255));

    painter.setBrush(brush);
    painter.setPen(pen);

    // Рисуем содержимое поля
    for (int i = 0; i < MAXX; i++) {
       for(int j = 0; j < MAXY; j++) {
           if(box[i][j] == 1) {
               int x = i * WIDTH + i * INTERVAL;
               int y = j * HEIGHT + j * INTERVAL;
              // painter.drawRect(x, y, WIDTH, HEIGHT);

              painter.drawImage(QRect(x, y, WIDTH, HEIGHT), QImage(PATH_TO_WALL_IMG));
           }
       }
    }

    // Рисует содержимое в блоке
    for(int i = 0; i < COUNT; i++) {
        int x = block.x[i];
        int y = block.y[i];
        int x1 = x * (WIDTH + INTERVAL);
        int y1 = y * (HEIGHT + INTERVAL);
        //painter.drawRect(x1, y1, WIDTH, HEIGHT);
        painter.drawImage(QRect(x1, y1, WIDTH, HEIGHT), QImage(PATH_TO_WALL_IMG));
    }

}
























