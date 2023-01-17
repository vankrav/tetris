#include "tetris.h"

Tetris::Tetris() {

    srand(unsigned(time(NULL))); // инициализация генератора случайных чисел
    score = 0;

    //заполняем поле нулями
    for(int i = 0; i < MAXX; i++) {
        for(int j = 0; j < MAXY; j++) {
            box[i][j] = 0;
        }
    }

    //заполняем текущий блок -1
    for(int i = 0; i < COUNT; i++) {
        block.x[i] = -1;
        block.y[i] = -1;
    }

    block.centerX = -1;
    block.centerY = -1;
    block.ID = 0;

    createNextBlock(); //  создать следующий блок

}


void Tetris::createBlock() {

    //копируем nextBlock в block
    for(int i = 0; i < COUNT; i++) {
        block.x[i] = nextBlock.x[i];
        block.y[i] = nextBlock.y[i];
    }

    block.centerX = nextBlock.centerX;
    block.centerY = nextBlock.centerY;
    block.ID = nextBlock.ID;

    createNextBlock(); // создаем следующий блок
}


Block Tetris::getNextBlock() {
    return nextBlock;
}

Block Tetris::getBlock() {
    return block;
}

int Tetris::getScore() {
    return score;
}

int Tetris::getBox(int x, int y) {
    return box[x][y];
}

bool Tetris::rotate() {
    if(isRotatable()) {
        return true;
    }
    else {
        return false;
    }
}

bool Tetris::moveToLeft() {
    if(move(-1,0)) {
        return true;
    }
    else {
        return false;
    }
}

bool Tetris::moveToRight() {
    if(move(1,0)) {
        return true;
    }
    else {
        return false;
    }
}

bool Tetris::moveToBottom() {
    if(!move(0,1)) {
        // если столкнулись с другими блоками
        blockToBox(); // копировать блок в обычное поле
        killLines(); // пробуем удалить строки, если они есть
        //проверим, не закончилась ли игра
        if(isEnd()) {
            return false;
        }
        // создадим новый блок, если еще не закончили игру
        else {
            createBlock();
        }
    }
    return true; // успешно опустились

}

bool Tetris::isEnd() {
    // если в верхней строке есть 1, то игра заканчивается
    for(int i = 0; i < MAXX; i++){
        if(box[i][0]) {
            return true;
        }
    }
    return false;
}

void Tetris::killLines(){
    int count = 0; // количество удаленных строк
    int fullLine = 0; // полная строка, над которой проводится операция
    while((fullLine = getFirstFullLine()) != -1) {
        for(int j = fullLine; j > 0; j--) {
            for(int i = 0; i < MAXX; i++) {
                //копируем в текущую строку верхнюю строчку
                box[i][j] = box[i][j - 1];
            }
        }
        count++;
    }

    score += count * count * 10;
}

void Tetris::clear(){

    srand(unsigned(time(NULL))); // инициализация генератора случайных чисел
    score = 0;

    //заполняем поле нулями
    for(int i = 0; i < MAXX; i++) {
        for(int j = 0; j < MAXY; j++) {
            box[i][j] = 0;
        }
    }

    //заполняем текущий блок -1
    for(int i = 0; i < COUNT; i++) {
        block.x[i] = -1;
        block.y[i] = -1;
    }

    block.centerX = -1;
    block.centerY = -1;
    block.ID = 0;

    createNextBlock(); //  создать следующий блок
}

int Tetris::getWidth() {
    return MAXX * WIDTH + (MAXX - 1) * INTERVAL;
}

int Tetris::getHeight() {
    return MAXY * HEIGHT + (MAXY - 1) * INTERVAL;
}

int Tetris::getNextWidth() {
     return NEXTMAXX * WIDTH + (NEXTMAXX - 1) * INTERVAL;
}

int Tetris::getNextHeight() {
    return NEXTMAXY * HEIGHT + (NEXTMAXY - 1) * INTERVAL;
}


void Tetris::createNextBlock() {
    int centerX = (MAXX - 1) / 2; // координата центра х
    int ID = rand() % 7; // генерация id случайной фигуры

    //создание блоков по id
    switch (ID) {
    case 0:
        //##
        //##
        nextBlock.x[0] = centerX;
        nextBlock.x[1] = centerX;
        nextBlock.x[2] = centerX + 1;
        nextBlock.x[3] = centerX + 1;
        nextBlock.y[0] = -2;
        nextBlock.y[1] = -1;
        nextBlock.y[2] = -2;
        nextBlock.y[3] = -1;
        nextBlock.centerX = 0;
        nextBlock.centerY = 0;
        nextBlock.ID = 0;
        break;
    case 1:
        //####
        nextBlock.x[0] = centerX - 1;
        nextBlock.x[1] = centerX;
        nextBlock.x[2] = centerX + 1;
        nextBlock.x[3] = centerX + 2;
        nextBlock.y[0] = -1;
        nextBlock.y[1] = -1;
        nextBlock.y[2] = -1;
        nextBlock.y[3] = -1;
        nextBlock.centerX = centerX;
        nextBlock.centerY = 0;
        nextBlock.ID = 1;
        break;
    case 2:
        //##
        // ##
        nextBlock.x[0] = centerX - 1;
        nextBlock.x[1] = centerX;
        nextBlock.x[2] = centerX;
        nextBlock.x[3] = centerX + 1;
        nextBlock.y[0] = -2;
        nextBlock.y[1] = -2;
        nextBlock.y[2] = -1;
        nextBlock.y[3] = -1;
        nextBlock.centerX = centerX;
        nextBlock.centerY = -2;
        nextBlock.ID = 2;
        break;
    case 3:
        // ##
        //##
        nextBlock.x[0] = centerX;
        nextBlock.x[1] = centerX + 1;
        nextBlock.x[2] = centerX - 1;
        nextBlock.x[3] = centerX;
        nextBlock.y[0] = -2;
        nextBlock.y[1] = -2;
        nextBlock.y[2] = -1;
        nextBlock.y[3] = -1;
        nextBlock.centerX = centerX;
        nextBlock.centerY = -2;
        nextBlock.ID = 3;
        break;
    case 4:
        //#
        //###
        nextBlock.x[0] = centerX - 1;
        nextBlock.x[1] = centerX - 1;
        nextBlock.x[2] = centerX;
        nextBlock.x[3] = centerX + 1;
        nextBlock.y[0] = -2;
        nextBlock.y[1] = -1;
        nextBlock.y[2] = -1;
        nextBlock.y[3] = -1;
        nextBlock.centerX = centerX;
        nextBlock.centerY = -1;
        nextBlock.ID = 4;
        break;
    case 5:
        //  #
        //###
        nextBlock.x[0] = centerX + 1;
        nextBlock.x[1] = centerX - 1;
        nextBlock.x[2] = centerX;
        nextBlock.x[3] = centerX + 1;
        nextBlock.y[0] = -2;
        nextBlock.y[1] = -1;
        nextBlock.y[2] = -1;
        nextBlock.y[3] = -1;
        nextBlock.centerX = centerX;
        nextBlock.centerY = -1;
        nextBlock.ID = 5;
        break;
    case 6:
        // #
        //###
        nextBlock.x[0] = centerX;
        nextBlock.x[1] = centerX - 1;
        nextBlock.x[2] = centerX;
        nextBlock.x[3] = centerX + 1;
        nextBlock.y[0] = -2;
        nextBlock.y[1] = -1;
        nextBlock.y[2] = -1;
        nextBlock.y[3] = -1;
        nextBlock.centerX = centerX;
        nextBlock.centerY = -1;
        nextBlock.ID = 6;
        break;
    default:
        break;

    }
}

bool Tetris::move(int dx, int dy) {

    int newX[COUNT], newY[COUNT];

    for (int i = 0; i < COUNT; i++) {
        newX[i] = block.x[i] + dx;
        newY[i] = block.y[i] + dy;

        //проверим новые координаты

        if(newX[i] < 0 || newX[i] >= MAXX) {
            return false;
        }

        if(newY[i] >= 0 && newY[i] < MAXY) {
            if(box[newX[i]][newY[i]] == 1) {
                return false;
            }
        }
        else if(newY[i] >= MAXY) {
            return false;
        }
    }
        //назначаем новые координаты

        for (int i = 0; i < COUNT; i++) {
            block.x[i] = newX[i];
            block.y[i] = newY[i];
        }

        block.centerX += dx;
        block.centerY += dy;

    return true;
}

void Tetris::blockToBox() {
    for (int i = 0; i < COUNT; i++) {
       if(block.y[i] >= 0) {
           box[block.x[i]][block.y[i]] = 1; // копируем данные из блока в поле
       }
    }
}

bool Tetris::isRotatable() {
    int newX[COUNT], newY[COUNT];

    for (int i = 0; i < COUNT; i++) {
        int nx = block.x[i] - block.centerX;
        int ny = block.y[i] - block.centerY;

        newX[i] = nx * 0 + ny * (-1) + block.centerX;
        newY[i] = nx * 1 + ny * 0 + block.centerY;

        //проверим новые координаты

        if(newX[i] < 0 || newX[i] >= MAXX) {
            return false;
        }

        if(newY[i] >= 0 && newY[i] < MAXY) {
            if(box[newX[i]][newY[i]] == 1) {
                return false;
            }
        }
        else if(newY[i] >= MAXY) {
            return false;
        }
    }
    //назначаем новые координаты

        for (int i = 0; i < COUNT; i++) {
            block.x[i] = newX[i];
            block.y[i] = newY[i];
        }



    return true;
}

int Tetris::getFirstFullLine() {
    for (int j = 0; j < MAXY; j++) {
        bool f = true;
        for (int i = 0; i < MAXX; i++) {
            if(box[i][j] == 0) {
                f = false;
                break;
            }
        }
        if(f){
            return j;
        }
    }
    return -1;
}





























