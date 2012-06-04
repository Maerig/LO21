#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->chiffre0,SIGNAL(clicked()),this,SLOT(num0Pressed()));
    QObject::connect(ui->chiffre1,SIGNAL(clicked()),this,SLOT(num1Pressed()));
    QObject::connect(ui->chiffre2,SIGNAL(clicked()),this,SLOT(num2Pressed()));
    QObject::connect(ui->chiffre3,SIGNAL(clicked()),this,SLOT(num3Pressed()));
    QObject::connect(ui->chiffre4,SIGNAL(clicked()),this,SLOT(num4Pressed()));
    QObject::connect(ui->chiffre5,SIGNAL(clicked()),this,SLOT(num5Pressed()));
    QObject::connect(ui->chiffre6,SIGNAL(clicked()),this,SLOT(num6Pressed()));
    QObject::connect(ui->chiffre7,SIGNAL(clicked()),this,SLOT(num7Pressed()));
    QObject::connect(ui->chiffre8,SIGNAL(clicked()),this,SLOT(num8Pressed()));
    QObject::connect(ui->chiffre9,SIGNAL(clicked()),this,SLOT(num9Pressed()));

    QObject::connect(ui->ButtonPush,SIGNAL(clicked()),this,SLOT(enterPressed()));

}


void MainWindow::num0Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "0");}
void MainWindow::num1Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "1");}
void MainWindow::num2Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "2");}
void MainWindow::num3Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "3");}
void MainWindow::num4Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "4");}
void MainWindow::num5Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "5");}
void MainWindow::num6Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "6");}
void MainWindow::num7Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "7");}
void MainWindow::num8Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "8");}
void MainWindow::num9Pressed() { ui->lineEdit->setText(ui->lineEdit->text() + "9");}

void MainWindow::enterPressed(){

}

MainWindow::~MainWindow()
{
    delete ui;
}
