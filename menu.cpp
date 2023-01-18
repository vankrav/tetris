#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent) {

    //this->resize(1000,600);

    //menuLayout = new QGridLayout;
//    menuLayout->setHorizontalSpacing(20);
//    menuLayout->setVerticalSpacing(20);
//    menuLayout->setAlignment(Qt::AlignCenter);

    gameNameLabel = new QLabel("Типовой панельный Тетрис");
    missionLabel = new QLabel("Цель игры: построить девятиэтажку без дырок, \nпотому что в доме с дырами, гуляют сквозняки)");
    controlLabel = new QLabel("Управление: \nw - поворот фигуры\na - влево\ns - вниз\nd - вправо\nпробел - пауза");

    difficultLabel = new QLabel("Выберите уровень сложности, для того, чтобы начать");
    easyLevelButton = new QPushButton("просто");
    middleLevelButton = new QPushButton("нормально");
    hardLevelButton = new QPushButton("сложно");
    scoreLabel = new QLabel("Ваш лучший результат: ");
//    menuLayout->addWidget(gameNameLabel,0,0);
//    menuLayout->addWidget(missionLabel,1,0);
//    menuLayout->addWidget(controlLabel,2,0);
//    menuLayout->addWidget(difficultLabel,3,0);
//    menuLayout->addWidget(scoreLabel,4,0);
//    menuLayout->addWidget(easyLevelButton,3,1);
//    menuLayout->addWidget(middleLevelButton,3,2);
//    menuLayout->addWidget(hardLevelButton,3,3);




}


