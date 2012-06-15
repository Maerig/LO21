#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "factory.h"
#include "memento.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    Pile* getPile(){return stack;}

    
private:
    Ui::MainWindow *ui;
    Pile* stack;
    Factory* fact;
    Memento* memundo;
    Memento* memredo;

private slots:



    void num0Pressed();
    void num1Pressed();
    void num2Pressed();
    void num3Pressed();
    void num4Pressed();
    void num5Pressed();
    void num6Pressed();
    void num7Pressed();
    void num8Pressed();
    void num9Pressed();
    void numPOINTPressed();
    void numQUOTEPressed();
    void numSPACEPressed();

    void typeChanged();

    void numPLUSPressed();
    void numMINUSPressed();
    void numMULTPressed();
    void numDIVPressed();
    void numMODPressed();
    void numPOWPressed();

    void numSinusPressed();
    void numCosinusPressed();
    void numTangPressed();
    void numSinusHPressed();
    void numCosinusHPressed();
    void numTangHPressed();

    void numSQRTPressed();
    void numSQRPressed();
    void numCUBEPressed();
    void numLNPressed();
    void numLOGPressed();
    void numFACTPressed();
    void numINVPressed();
    void numSIGNPressed();



    void enterPressed();
    void evalPressed();

    void dropPressed();
    void dupPressed();
    void sumPressed();
    void swapPressed();
    void clearPressed();

    void annuler();
    void retablir();
};

#endif // MAINWINDOW_H
