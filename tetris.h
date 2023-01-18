/*!
\file
\brief Заголовочный файл с описанием логики игры
*/

#ifndef TETRIS_H
#define TETRIS_H

#include <cstdlib> // для случайных чисел подключаем
#include <ctime>

#define MAXX 10 // количество блоков в ширину
#define MAXY 12 // количество блоков в длину
#define NEXTMAXX 6 // количество блоков в ширину в окне "далее"
#define NEXTMAXY 6 // количество блоков в длину в окне "далее"
#define WIDTH 50 // ширина ячейки
#define HEIGHT 50 // высота ячейки
#define NEXTWIDTH 30 // ширина ячейки
#define NEXTHEIGHT 30 // высота ячейки
#define INTERVAL 0 // интервал между яцейками
#define COUNT 4 // количество блоков формирующих сторону общего для всех фигур блока
#define PATH_TO_WALL ":/src/img/okno/okno"
#define PATH_TO_SKY_IMG ":/src/img/sky/sky.jpg"
#define PATH_TO_BOMB_IMG ":/src/img/bomb/bomb.png"
#define SPEED 500


// структура для общего блока, блок состоит из боксов (ячеек), в блоке находится фигура

/*!
    \brief  Структура для хранения фигуры

    Данная структура хранит в себе одну из 7 страндартных фигур или бомбу
*/
struct Block {
    int x[COUNT]; ///< х координаты ячеек
    int y[COUNT]; ///< у координата ячеек
    int centerX; ///< х координата центра
    int centerY; ///< у координата центра
    int ID; ///< фигура
    bool isBomb = false; ///< является ли фигура бомбой
};

/*!
    \brief  Класс с реализованной логикой тетриса.

    В данном классе реализованна логика игры.
*/

class Tetris {
public:
    Tetris(); ///< конструктор
    void createBlock(); ///< создать блок
    Block getNextBlock(); ///< получить следующий блок
    Block getBlock(); ///< получить блок
    int getScore(); ///< получить счет
    int getSpeed(); ///< получить врямя, за которое смеяются карды
    void setSpeed(int s); ///< получить счет
    int bestScore(int score = 0); ///< получить лучший результат
    int getBox(int x, int y); ///< статус блока на этой позиции поля, есть или нет
    bool rotate(); ///< повернуть фигуру
    bool moveToLeft(); ///< двинуть влево фигуру
    bool moveToRight(); ///< двинуть вправо фигуру
    bool moveToBottom(); ///< двинуть вниз фигуру
    bool isEnd(); ///< конец игры, фигура коснулась верхней границы поля
    void clear(); ///< очистить поле



    static int getWidth(); ///< получить ширину окна
    static int getHeight(); ///< получить высоту окна
    static int getNextWidth(); ///< получить ширину окна "далее"
    static int getNextHeight(); ///< получить высоту окна "далее"


private:
    void createNextBlock(); ///< создать следующий блок
    bool move(int dx, int dy); ///< можно ли двинуть туда?
    void blockToBox(); ///< перенос данных из блока в бокс
    bool isRotatable(); ///< можно ли повернуть?
    int getFirstFullLine(); ///< получить первую целую строку

    int speed;
    int score; // счет
    int best;
    bool blockIsBomb;
    Block block; // текущий блок
    Block nextBlock; // следующий блок
    int box[MAXX][MAXY]; // система координат сетки (1 - есть, 0 - нету)



};

#endif // TETRIS_H
























