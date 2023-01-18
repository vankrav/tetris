/*!
\file
\brief главное окно
*/
#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    tetrisBox = new TetrisBox;
    nextTetrisBox = new NextTetrisBox;
    mainLayout = new QGridLayout;
    scoreLabel = new QLabel("Счет: ");
    nextLabel = new QLabel("следующая фигура");
    aboutLabel = new QLabel("Цель игры: построить девятиэтажку без дырок, \nпотому что в доме с дырами, гуляют сквозняки)");
    controlLabel = new QLabel("Управление: \nw - поворот фигуры\na - влево\ns - вниз\nd - вправо\nj - пауза\nh - запуск\nk - очистить поле\n\n");
    mainLayout->setHorizontalSpacing(20);
    mainLayout->setVerticalSpacing(20);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(tetrisBox, 0, 0, 6, 3);
    mainLayout->addWidget(nextTetrisBox, 1, 4, 1, 1);
    mainLayout->addWidget(scoreLabel,2, 4);
    mainLayout->addWidget(nextLabel,0, 4);
    mainLayout->addWidget(aboutLabel,7, 0);
    mainLayout->addWidget(controlLabel,3, 4);

    //mainLayout->addWidget(imageLabel,16, 1);
    QWidget *widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

    setPalette(QColor(194, 240, 238));
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int width = (screenGeometry.width() - this->width()) / 2;
    move(width, 5);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));

    QMessageBox startMesssageBox;
    startMesssageBox.setText("Типовой панельный тетрис");
    startMesssageBox.setInformativeText("Цель игры: построить девятиэтажку без дырок, \nпотому что в доме с дырами, гуляют сквозняки)\n\nУправление: \nw - поворот фигуры\na - влево\ns - вниз\nd - вправо\nj - пауза\nh - запуск\nk - очистить поле\n\n для старта нажмите OK");
    startMesssageBox.setStandardButtons(QMessageBox::Ok);

    if (startMesssageBox.exec() == QMessageBox::Ok) {
        tetris.createBlock();
        tetrisBox->updateTetris(tetris);
        nextTetrisBox->updateNextTetris(tetris);
        updateScore();
        status = STATUS_ON;

        setWindowTitle("Типовой панельный тетрис - [игра идет]");
        timer->start(tetris.getSpeed());
    }
}

MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent(QKeyEvent *event){
if(status != STATUS_OFF) {
    if(event->key() == Qt::Key_W) {

        //поворот фигуры на w
        if(tetris.rotate()) {
            if(status == STATUS_ON) {
                tetrisBox->updateTetris(tetris);
                nextTetrisBox->updateNextTetris(tetris);
                updateScore();

            }
        }
    }
    if(event->key() == Qt::Key_A) {
        //двинуть влево на A
        if(tetris.moveToLeft()) {
            if(status == STATUS_ON) {
                tetrisBox->updateTetris(tetris);
                nextTetrisBox->updateNextTetris(tetris);
                updateScore();
            }
        }
    }
    if(event->key() == Qt::Key_S) {
        //двинуть вниз на S
        if(tetris.moveToBottom()) {
            if(status == STATUS_ON) {
                tetrisBox->updateTetris(tetris);
                nextTetrisBox->updateNextTetris(tetris);

                updateScore();
            }
            else {
                timer->stop();
                status = STATUS_END;
            }
        }
    }
    if(event->key() == Qt::Key_D) {
        //двинуть вправо D
        if(tetris.moveToRight()) {
            if(status == STATUS_ON) {
                tetrisBox->updateTetris(tetris);
                nextTetrisBox->updateNextTetris(tetris);
                updateScore();
            }
        }
    }
}
    if(event->key() == Qt::Key_H) {
        //start

        if(status == STATUS_PAUSE) {
            timer->start(tetris.getSpeed());
            status = STATUS_ON;

            setWindowTitle("Типовой панельный тетрис - [игра идет]");
        }
        else if(status == STATUS_OFF){
            tetris.createBlock();
            tetrisBox->updateTetris(tetris);
            nextTetrisBox->updateNextTetris(tetris);
            updateScore();
            status = STATUS_ON;

            setWindowTitle("Типовой панельный тетрис - [игра идет]");
            timer->start(tetris.getSpeed());
        }
    }



    if(event->key() == Qt::Key_J) {
        //pause
        if(status == STATUS_ON) {

            timer->stop();
            status = STATUS_PAUSE;

            setWindowTitle("Типовой панельный тетрис - [игра на паузе]");
        }


    }
    if(event->key() == Qt::Key_K) {
        //restart
        if(status == STATUS_ON) {

            timer->stop();
            tetris.clear();
            tetrisBox->updateTetris(tetris);
            nextTetrisBox->updateNextTetris(tetris);
            updateScore();
            status = STATUS_OFF;

            setWindowTitle("Типовой панельный тетрис - [игру еще не начали]");
        }

    }
}

void MainWindow::updateScore() {
    scoreLabel->setText("Cчет: " + QString::number(tetris.getScore())+"\nРекорд: "
                         + QString::number(tetris.bestScore()) + "%");
}



void MainWindow::changeEvent(QKeyEvent *event){
    if(event->type() != QEvent::WindowStateChange) {
        return;
    }
    if(windowState() == Qt::WindowMinimized) {
        timer ->stop();
    }
}

void MainWindow::onTimer() {
    if(tetris.moveToBottom()) {

        tetrisBox->updateTetris(tetris);
        nextTetrisBox->updateNextTetris(tetris);
        updateScore();

    }
    else {
        timer->stop();
        QMessageBox endMesssageBox;
        endMesssageBox.setWindowTitle("Игра закончилась");

        endMesssageBox.setInformativeText("Вы построили дом на " + QString::number(tetris.getScore()) +
                                          "%\nВаш рекорд:" + QString::number(tetris.bestScore())+"%");

        endMesssageBox.setStandardButtons(QMessageBox::Ok);

        if (endMesssageBox.exec() == QMessageBox::Ok) {
                timer->stop();
                tetris.clear();
                tetrisBox->updateTetris(tetris);
                nextTetrisBox->updateNextTetris(tetris);
                updateScore();
                status = STATUS_OFF;

                setWindowTitle("Типовой панельный тетрис - [игру еще не начали]");
        }


    }

}
