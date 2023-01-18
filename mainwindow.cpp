#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    menu = new Menu;
    QGridLayout *menuLayout = menu->menuLayout;
    tetrisBox = new TetrisBox;
    nextTetrisBox = new NextTetrisBox;
    mainLayout = new QGridLayout;
    scoreLabel = new QLabel("Счет: ");
    statusLabel = new QLabel("игра не начата ");
    mainLayout->setHorizontalSpacing(20);
    mainLayout->setVerticalSpacing(20);
    mainLayout->setAlignment(Qt::AlignCenter);
    //mainLayout->addWidget(menu,0,0,14,1);
    mainLayout->addLayout(menuLayout, 0,0);
//    mainLayout->addWidget(tetrisBox, 0, 0, 14, 1);
//    mainLayout->addWidget(nextTetrisBox, 1, 1, 14, 1);
//    mainLayout->addWidget(scoreLabel,15, 0);
//    mainLayout->addWidget(statusLabel,15, 1);

    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);
    widget->setLayout(mainLayout);

    setPalette(Qt::gray);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int width = (screenGeometry.width() - this->width()) / 2;
    move(width, 5);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    mainLayout->connect(menu->easyLevelButton,SIGNAL(clicked()), SLOT(onClick()));
    status = STATUS_OFF;
}

MainWindow::~MainWindow()
{

}

void MainWindow::onClick() {
    mainLayout->removeItem(menu->menuLayout);
}

void MainWindow::keyPressEvent(QKeyEvent *event){

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

    if(event->key() == Qt::Key_H) {
        //start

        if(status == STATUS_PAUSE) {
            timer->start(SPEED);
            status = STATUS_ON;
            updateStatusLabel(status);
            setWindowTitle("good");
        }
        else if(status == STATUS_OFF){
            tetris.createBlock();
            tetrisBox->updateTetris(tetris);
            nextTetrisBox->updateNextTetris(tetris);
            updateScore();
            status = STATUS_ON;
            updateStatusLabel(status);
            setWindowTitle("good");
            timer->start(SPEED);
        }
    }

    if(event->key() == Qt::Key_J) {
        //pause
        if(status == STATUS_ON) {

            timer->stop();
            status = STATUS_PAUSE;
            updateStatusLabel(status);
            setWindowTitle("pause");
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
            updateStatusLabel(status);
            setWindowTitle("игра не начата");
        }

    }
}

void MainWindow::updateScore() {
    QString str;
    str += QString("%1").arg(tetris.getScore());
    scoreLabel->setText("Cчет: " + str);
}


void MainWindow::updateStatusLabel(int state) {
    switch (state) {
    case 0:
        statusLabel->setText("игра идет");
        break;
    case 1:
        statusLabel->setText("игра на паузе");
        break;
    case 2:
        statusLabel->setText("игра еще не начата");
        break;
    default:
        break;
    }
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
    }

}
