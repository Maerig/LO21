#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), stack(new Pile), fact(new Factory)

{
    ui->setupUi(this);
    QObject::connect(ui->num0,SIGNAL(clicked()),this,SLOT(num0Pressed()));
    QObject::connect(ui->num1,SIGNAL(clicked()),this,SLOT(num1Pressed()));
    QObject::connect(ui->num2,SIGNAL(clicked()),this,SLOT(num2Pressed()));
    QObject::connect(ui->num3,SIGNAL(clicked()),this,SLOT(num3Pressed()));
    QObject::connect(ui->num4,SIGNAL(clicked()),this,SLOT(num4Pressed()));
    QObject::connect(ui->num5,SIGNAL(clicked()),this,SLOT(num5Pressed()));
    QObject::connect(ui->num6,SIGNAL(clicked()),this,SLOT(num6Pressed()));
    QObject::connect(ui->num7,SIGNAL(clicked()),this,SLOT(num7Pressed()));
    QObject::connect(ui->num8,SIGNAL(clicked()),this,SLOT(num8Pressed()));
    QObject::connect(ui->num9,SIGNAL(clicked()),this,SLOT(num9Pressed()));
    QObject::connect(ui->numPOINT,SIGNAL(clicked()),this,SLOT(numPOINTPressed()));

    QObject::connect(ui->numTYPE,SIGNAL(activated(QString)),this,SLOT(typeChanged()));

    QObject::connect(ui->numPLUS,SIGNAL(clicked()),this,SLOT(numPLUSPressed()));
    QObject::connect(ui->numMINUS,SIGNAL(clicked()),this,SLOT(numMINUSPressed()));
    QObject::connect(ui->numMULT,SIGNAL(clicked()),this,SLOT(numMULTPressed()));
    QObject::connect(ui->numDIV,SIGNAL(clicked()),this,SLOT(numDIVPressed()));

    QObject::connect(ui->numPUSH,SIGNAL(clicked()),this,SLOT(enterPressed()));
    QObject::connect(ui->pileDROP,SIGNAL(clicked()),this,SLOT(dropPressed()));

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
void MainWindow::numPOINTPressed() { ui->lineEdit->setText(ui->lineEdit->text() + ".");}

void MainWindow::numPLUSPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "+");}
void MainWindow::numMINUSPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "-");}
void MainWindow::numMULTPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "*");}
void MainWindow::numDIVPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "/");}

void MainWindow::typeChanged(){ Donnee::setTypeDonnees(ui->numTYPE->currentText().toStdString());}

void MainWindow::enterPressed(){

    std::stringstream affichage;
    std::string saisie = ui->lineEdit->text().toStdString();
    stack->empiler(fact->make(saisie));
    stack->afficher(affichage);
    ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
    ui->lineEdit->clear();
}

void MainWindow::dropPressed(){

    std::stringstream affichage;

    stack->drop();
    stack->afficher(affichage);
    ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
