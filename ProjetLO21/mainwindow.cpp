#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include "calculexception.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), stack(new Pile), fact(new Factory), memundo(new Memento), memredo(new Memento)

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
    QObject::connect(ui->numIMA,SIGNAL(clicked()),this,SLOT(numIMAPressed()));
    QObject::connect(ui->numQUOTE,SIGNAL(clicked()),this,SLOT(numQUOTEPressed()));
    QObject::connect(ui->numSPACE,SIGNAL(clicked()),this,SLOT(numSPACEPressed()));

    QObject::connect(ui->numTYPE,SIGNAL(activated(QString)),this,SLOT(typeChanged()));
    QObject::connect(ui->numComplexe,SIGNAL(clicked()),this,SLOT(complexeChanged()));
    QObject::connect(ui->numDegre,SIGNAL(clicked()),this,SLOT(degreClicked()));
    QObject::connect(ui->numRadian,SIGNAL(clicked()),this,SLOT(radianClicked()));

    // Operateur Binaires
    QObject::connect(ui->numPLUS,SIGNAL(clicked()),this,SLOT(numPLUSPressed()));
    QObject::connect(ui->numMINUS,SIGNAL(clicked()),this,SLOT(numMINUSPressed()));
    QObject::connect(ui->numMULT,SIGNAL(clicked()),this,SLOT(numMULTPressed()));
    QObject::connect(ui->numDIV,SIGNAL(clicked()),this,SLOT(numDIVPressed()));
    QObject::connect(ui->numMOD,SIGNAL(clicked()),this,SLOT(numMODPressed()));
    QObject::connect(ui->numPOW,SIGNAL(clicked()),this,SLOT(numPOWPressed()));

    //Operateur Unaires
    QObject::connect(ui->numSIN,SIGNAL(clicked()),this,SLOT(numSinusPressed()));
    QObject::connect(ui->numCOS,SIGNAL(clicked()),this,SLOT(numCosinusPressed()));
    QObject::connect(ui->numTAN,SIGNAL(clicked()),this,SLOT(numTangPressed()));
    QObject::connect(ui->numCOSH,SIGNAL(clicked()),this,SLOT(numCosinusHPressed()));
    QObject::connect(ui->numSINH,SIGNAL(clicked()),this,SLOT(numSinusHPressed()));
    QObject::connect(ui->numTANH,SIGNAL(clicked()),this,SLOT(numTangHPressed()));

    QObject::connect(ui->numSQR,SIGNAL(clicked()),this,SLOT(numSQRPressed()));
    QObject::connect(ui->numSQRT,SIGNAL(clicked()),this,SLOT(numSQRTPressed()));
    QObject::connect(ui->numCUBE,SIGNAL(clicked()),this,SLOT(numCUBEPressed()));

    QObject::connect(ui->numLN,SIGNAL(clicked()),this,SLOT(numLNPressed()));
    QObject::connect(ui->numLOG,SIGNAL(clicked()),this,SLOT(numLOGPressed()));
    QObject::connect(ui->numFACT,SIGNAL(clicked()),this,SLOT(numFACTPressed()));
    QObject::connect(ui->numINV,SIGNAL(clicked()),this,SLOT(numINVPressed()));
    QObject::connect(ui->numSIGN,SIGNAL(clicked()),this,SLOT(numSIGNPressed()));





    // Operations sur la pile
    QObject::connect(ui->numPUSH,SIGNAL(clicked()),this,SLOT(enterPressed()));
    QObject::connect(ui->numEVAL,SIGNAL(clicked()),this,SLOT(evalPressed()));
    QObject::connect(ui->pileDROP,SIGNAL(clicked()),this,SLOT(dropPressed()));
    QObject::connect(ui->pileDUP,SIGNAL(clicked()),this,SLOT(dupPressed()));
    QObject::connect(ui->pileSUM,SIGNAL(clicked()),this,SLOT(sumPressed()));
    QObject::connect(ui->pileSWAP,SIGNAL(clicked()),this,SLOT(swapPressed()));
    QObject::connect(ui->pileCLEAR,SIGNAL(clicked()),this,SLOT(clearPressed()));

    QObject::connect(ui->actionAnnuler,SIGNAL(triggered()),this,SLOT(annuler()));
    QObject::connect(ui->actionRetablir,SIGNAL(triggered()),this,SLOT(retablir()));

    setWindowTitle("Rotaluklak");
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
void MainWindow::numIMAPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "$");}
void MainWindow::numQUOTEPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "'");}
void MainWindow::numSPACEPressed() { ui->lineEdit->setText(ui->lineEdit->text() + " ");}

void MainWindow::numPLUSPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "+");}
void MainWindow::numMINUSPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "-");}
void MainWindow::numMULTPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "*");}
void MainWindow::numDIVPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "/");}
void MainWindow::numMODPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "MOD");}
void MainWindow::numPOWPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "^");}

void MainWindow::numSinusPressed()  { ui->lineEdit->setText(ui->lineEdit->text() + "SIN");}
void MainWindow::numCosinusPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "COS");}
void MainWindow::numTangPressed()   { ui->lineEdit->setText(ui->lineEdit->text() + "TAN");}
void MainWindow::numSinusHPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "SINH");}
void MainWindow::numCosinusHPressed() { ui->lineEdit->setText(ui->lineEdit->text() + "COSH");}
void MainWindow::numTangHPressed()  { ui->lineEdit->setText(ui->lineEdit->text() + "TANH");}
void MainWindow::numSQRPressed()    { ui->lineEdit->setText(ui->lineEdit->text() + "SQR");}
void MainWindow::numSQRTPressed()   { ui->lineEdit->setText(ui->lineEdit->text() + "SQRT");}
void MainWindow::numCUBEPressed()   { ui->lineEdit->setText(ui->lineEdit->text() + "CUBE");}
void MainWindow::numLNPressed()     { ui->lineEdit->setText(ui->lineEdit->text() + "LN");}
void MainWindow::numLOGPressed()    { ui->lineEdit->setText(ui->lineEdit->text() + "LOG");}
void MainWindow::numFACTPressed()   { ui->lineEdit->setText(ui->lineEdit->text() + "!");}
void MainWindow::numINVPressed()    { ui->lineEdit->setText(ui->lineEdit->text() + "INV");}
void MainWindow::numSIGNPressed()   { ui->lineEdit->setText(ui->lineEdit->text() + "SIGN");}


void MainWindow::typeChanged(){
    std::string type = ui->numTYPE->currentText().toStdString();
    if(type=="Entier")
    {
        ui->numMOD->setEnabled(true);
        ui->numFACT->setEnabled(true);
    }else //Rationnel ou Reel
          {
              ui->numMOD->setEnabled(false);
              ui->numFACT->setEnabled(false);
          }
    Donnee::setTypeDonnees(type);
}

void MainWindow::complexeChanged(){
    bool active = (ui->numComplexe->isChecked());
    Donnee::setTypeComplexe(active);
    ui->numIMA->setEnabled(active);
    ui->numPOW->setEnabled(!active);
    ui->numMOD->setEnabled(!active);
    ui->numSIN->setEnabled(!active);
    ui->numCOS->setEnabled(!active);
    ui->numTAN->setEnabled(!active);
    ui->numSINH->setEnabled(!active);
    ui->numCOSH->setEnabled(!active);
    ui->numTANH->setEnabled(!active);
    ui->numLN->setEnabled(!active);
    ui->numLOG->setEnabled(!active);
    ui->numINV->setEnabled(!active);
    ui->numSQRT->setEnabled(!active);
    ui->numFACT->setEnabled(!active);
}

void MainWindow::degreClicked(){ Donnee::setTypeAngle(degre);}
void MainWindow::radianClicked(){ Donnee::setTypeAngle(radian);}

void MainWindow::enterPressed(){
    std::stringstream affichage;
    std::string saisie = ui->lineEdit->text().toStdString();
    if(saisie[0])   //Permet de ne pas saisir un chaine vide
    {
        try
        {
            memundo->save(stack);
            memredo->reset();
            stack->empiler(fact->make(saisie));
        }
        catch(CalculException exc)
        {
            exc.afficher();
        }
        stack->afficher(affichage);
        ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
        ui->lineEdit->clear();
    }
}

void MainWindow::evalPressed()
{
    std::stringstream affichage;
    Donnee* data = 0;
    try
    {
        data = stack->depiler();
    }
    catch(CalculException exc)
    {
        exc.afficher();
    }
    Expression* exp = dynamic_cast<Expression*>(data);
    if(exp && exp->valide())     //Il s'agit d'une expression valide
    {
        try
        {
            while(exp->longueur()>0)
                stack->empiler(exp->defiler());
        }
        catch(CalculException exc)
        {
            exc.afficher();
        }
        stack->afficher(affichage);
        ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
        ui->lineEdit->clear();
    }
    else if(data)
    {
        stack->empiler(data);
        try
        {
            if(exp)
                throw(CalculException("Erreur de syntaxe."));
            else
                throw(CalculException("Expression non reconnue."));
        }
        catch(CalculException exc)
        {
            exc.afficher();
        }
    }
}

void MainWindow::dropPressed(){

    std::stringstream affichage;

    if(stack->longueur()>0)
    {
    memundo->save(stack);
    memredo->reset();
    stack->drop();
    stack->afficher(affichage);
    ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
    }
}

void MainWindow::dupPressed(){

    std::stringstream affichage;

    try
    {
        memundo->save(stack);
        memredo->reset();
        stack->dup();
    }
    catch (CalculException exc)
    {
        exc.afficher();
    }

    stack->afficher(affichage);
    ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
}

void MainWindow::sumPressed(){

    std::stringstream affichage;

    memundo->save(stack);
    memredo->reset();
    stack->sum();
    stack->afficher(affichage);
    ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
}

void MainWindow::swapPressed(){

    std::stringstream affichage;

    try
    {
        memundo->save(stack);
        memredo->reset();
        stack->swap();
    }
    catch(CalculException exc)
    {
        exc.afficher();
    }

    stack->afficher(affichage);
    ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
}

void MainWindow::clearPressed(){

    std::stringstream affichage;

    if(stack->longueur()>0)
    {
        memundo->save(stack);
        memredo->reset();
        stack->clear();
        stack->afficher(affichage);
        ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
    }
}

void MainWindow::annuler()
{
    try
    {
        std::stringstream affichage;

        if(memundo->longueur()>0)
        {
            memredo->save(stack);
            stack->~Pile();
            stack = memundo->restore();
            stack->afficher(affichage);
            ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
        }
        else throw(CalculException("Impossible d'annuler."));
    }
    catch(CalculException exc)
    {
        exc.afficher();
    }
}

void MainWindow::retablir()
{
    try
    {
        std::stringstream affichage;

        if(memredo->longueur()>0)
        {
            memundo->save(stack);
            stack->~Pile();
            stack = memredo->restore();
            stack->afficher(affichage);
            ui->PileAffichage->setPlainText(QString::fromStdString(affichage.str()));
        }
        else throw(CalculException("Impossible de retablir."));
    }
    catch(CalculException exc)
    {
        exc.afficher();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
