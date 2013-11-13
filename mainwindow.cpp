#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(640, 240);

    gameCanvas = new GameCanvas();

    this->setCentralWidget(gameCanvas);

    QTimer *timer = new QTimer();

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    timer->setInterval(50);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout()
{
    gameCanvas->repaint();
}
