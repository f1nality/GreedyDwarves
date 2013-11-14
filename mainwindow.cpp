#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(640, 240);

    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    InitializeGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeGame()
{
    GameLogic *gameLogic = new GameLogic();

    gameCanvas = new GameCanvas();
    gameCanvas->setGameLogic(gameLogic);

    QObject::connect(gameLogic, SIGNAL(GameUpdated()), gameCanvas, SLOT(onGameUpdated()));

    this->setCentralWidget(gameCanvas);
}
