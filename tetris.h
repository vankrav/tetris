#ifndef TETRIS_H
#define TETRIS_H

#include <cstdlib> // для случайных чисел подключаем
#include <ctime>

#define MAXX 8 // количество блоков в ширину
#define MAXY 10 // количество блоков в длину
#define NEXTMAXX 6 // количество блоков в ширину в окне "далее"
#define NEXTMAXY 6 // количество блоков в длину в окне "далее"
#define WIDTH 55 // ширина ячейки
#define HEIGHT 55 // высота ячейки
#define INTERVAL 0 // интервал между яцейками
#define COUNT 4 // количество блоков формирующих сторону общего для всех фигур блока
#define PATH_TO_WALL_IMG ":/okno2.png"


// структура для общего блока, блок состоит из боксов (ячеек), в блоке находится фигура

struct Block {
    int x[COUNT]; // х координаты ячеек
    int y[COUNT]; // у координата ячеек
    int centerX; // х координата центра
    int centerY; // у координата центра
    int ID; // фигура
};

class Tetris {
public:
    Tetris(); // конструктор
    void createBlock(); // создать блок
    Block getNextBlock(); // получить следующий блок
    Block getBlock(); // получить блок
    int getScore(); // получить счет
    int getBox(int x, int y); // статус блока на этой позиции, есть или нет
    bool rotate(); // повернуть
    bool moveToLeft(); // двинуть влево
    bool moveToRight(); // двинуть вправо
    bool moveToBottom(); // двинуть вниз
    bool isEnd(); // конец игры, блок дошел до верха
    void killLines(); // удалить линии при заполнении
    void clear(); // все очистить

    static int getWidth(); // получить ширину окна
    static int getHeight(); // получить высоту окна
    static int getNextWidth(); // получить ширину окна "далее"
    static int getNextHeight(); // получить высоту окна "далее"

private:
    void createNextBlock(); // создать следующий блок
    bool move(int dx, int dy); // можно ли двинуть туда?
    void blockToBox(); // перенос данных из блока в бокс
    bool isRotatable(); // можно ли повернуть?
    int getFirstFullLine(); // получить первую целую строку

    int score; // счет
    Block block; // текущий блок
    Block nextBlock; // следующий блок
    int box[MAXX][MAXY]; // система координат сетки (1 - есть, 0 - нету)



};

#endif // TETRIS_H
























