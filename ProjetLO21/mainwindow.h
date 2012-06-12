#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pile.h"

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

    void typeChanged();

    void numPLUSPressed();
    void numMINUSPressed();
    void numMULTPressed();
    void numDIVPressed();

    void enterPressed();

    void dropPressed();
    void dupPressed();
    void sumPressed();
    void swapPressed();
    void clearPressed();
};

#endif // MAINWINDOW_H
