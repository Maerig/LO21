/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 5. Jun 17:50:25 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit;
    QCheckBox *numExpression;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *numTYPE;
    QCheckBox *numComplexe;
    QRadioButton *numDegre;
    QRadioButton *numRadian;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *numEVAL;
    QPushButton *numPUSH;
    QGridLayout *gridLayout;
    QPushButton *numParGch;
    QPushButton *numParDrt;
    QPushButton *numFACT;
    QPushButton *numCOSH;
    QPushButton *numCOS;
    QPushButton *numPOW2;
    QPushButton *numSINH;
    QPushButton *numSIN;
    QPushButton *numPOW3;
    QPushButton *numTANH;
    QPushButton *numTAN;
    QPushButton *numRACINE;
    QPushButton *numLN;
    QPushButton *numLOG;
    QPushButton *numINV;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *numMOD;
    QPushButton *numPOW;
    QPushButton *numDIV;
    QGridLayout *gridLayout_2;
    QPushButton *numMINUS;
    QPushButton *numPLUS;
    QPushButton *numMULT;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num6;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *num0;
    QPushButton *numPOINT;
    QPushButton *numSIGN;
    QPlainTextEdit *PileAffichage;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pileDROP;
    QPushButton *pileDUP;
    QPushButton *pileMEAN;
    QPushButton *pileSUM;
    QPushButton *pileSWAP;
    QPushButton *pileCLEAR;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(734, 351);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 11, 719, 276));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setBaseSize(QSize(257, 27));
        lineEdit->setLayoutDirection(Qt::RightToLeft);
        lineEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit);

        numExpression = new QCheckBox(widget);
        numExpression->setObjectName(QString::fromUtf8("numExpression"));

        horizontalLayout_5->addWidget(numExpression);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        numTYPE = new QComboBox(widget);
        numTYPE->setObjectName(QString::fromUtf8("numTYPE"));

        horizontalLayout_4->addWidget(numTYPE);

        numComplexe = new QCheckBox(widget);
        numComplexe->setObjectName(QString::fromUtf8("numComplexe"));

        horizontalLayout_4->addWidget(numComplexe);

        numDegre = new QRadioButton(widget);
        numDegre->setObjectName(QString::fromUtf8("numDegre"));

        horizontalLayout_4->addWidget(numDegre);

        numRadian = new QRadioButton(widget);
        numRadian->setObjectName(QString::fromUtf8("numRadian"));

        horizontalLayout_4->addWidget(numRadian);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        numEVAL = new QPushButton(widget);
        numEVAL->setObjectName(QString::fromUtf8("numEVAL"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numEVAL->sizePolicy().hasHeightForWidth());
        numEVAL->setSizePolicy(sizePolicy);
        numEVAL->setMaximumSize(QSize(85, 27));
        numEVAL->setBaseSize(QSize(85, 27));

        horizontalLayout->addWidget(numEVAL);

        numPUSH = new QPushButton(widget);
        numPUSH->setObjectName(QString::fromUtf8("numPUSH"));
        sizePolicy.setHeightForWidth(numPUSH->sizePolicy().hasHeightForWidth());
        numPUSH->setSizePolicy(sizePolicy);
        numPUSH->setMaximumSize(QSize(16777215, 16777215));
        numPUSH->setBaseSize(QSize(0, 0));

        horizontalLayout->addWidget(numPUSH);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        numParGch = new QPushButton(widget);
        numParGch->setObjectName(QString::fromUtf8("numParGch"));
        sizePolicy.setHeightForWidth(numParGch->sizePolicy().hasHeightForWidth());
        numParGch->setSizePolicy(sizePolicy);
        numParGch->setMaximumSize(QSize(51, 27));
        numParGch->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numParGch, 0, 0, 1, 1);

        numParDrt = new QPushButton(widget);
        numParDrt->setObjectName(QString::fromUtf8("numParDrt"));
        sizePolicy.setHeightForWidth(numParDrt->sizePolicy().hasHeightForWidth());
        numParDrt->setSizePolicy(sizePolicy);
        numParDrt->setMaximumSize(QSize(51, 27));
        numParDrt->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numParDrt, 0, 1, 1, 1);

        numFACT = new QPushButton(widget);
        numFACT->setObjectName(QString::fromUtf8("numFACT"));
        sizePolicy.setHeightForWidth(numFACT->sizePolicy().hasHeightForWidth());
        numFACT->setSizePolicy(sizePolicy);
        numFACT->setMaximumSize(QSize(51, 27));
        numFACT->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numFACT, 0, 2, 1, 1);

        numCOSH = new QPushButton(widget);
        numCOSH->setObjectName(QString::fromUtf8("numCOSH"));
        sizePolicy.setHeightForWidth(numCOSH->sizePolicy().hasHeightForWidth());
        numCOSH->setSizePolicy(sizePolicy);
        numCOSH->setMaximumSize(QSize(51, 27));
        numCOSH->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numCOSH, 1, 0, 1, 1);

        numCOS = new QPushButton(widget);
        numCOS->setObjectName(QString::fromUtf8("numCOS"));
        sizePolicy.setHeightForWidth(numCOS->sizePolicy().hasHeightForWidth());
        numCOS->setSizePolicy(sizePolicy);
        numCOS->setMaximumSize(QSize(51, 27));
        numCOS->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numCOS, 1, 1, 1, 1);

        numPOW2 = new QPushButton(widget);
        numPOW2->setObjectName(QString::fromUtf8("numPOW2"));
        sizePolicy.setHeightForWidth(numPOW2->sizePolicy().hasHeightForWidth());
        numPOW2->setSizePolicy(sizePolicy);
        numPOW2->setMaximumSize(QSize(51, 27));
        numPOW2->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numPOW2, 1, 2, 1, 1);

        numSINH = new QPushButton(widget);
        numSINH->setObjectName(QString::fromUtf8("numSINH"));
        sizePolicy.setHeightForWidth(numSINH->sizePolicy().hasHeightForWidth());
        numSINH->setSizePolicy(sizePolicy);
        numSINH->setMaximumSize(QSize(51, 27));
        numSINH->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numSINH, 2, 0, 1, 1);

        numSIN = new QPushButton(widget);
        numSIN->setObjectName(QString::fromUtf8("numSIN"));
        sizePolicy.setHeightForWidth(numSIN->sizePolicy().hasHeightForWidth());
        numSIN->setSizePolicy(sizePolicy);
        numSIN->setMaximumSize(QSize(51, 27));
        numSIN->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numSIN, 2, 1, 1, 1);

        numPOW3 = new QPushButton(widget);
        numPOW3->setObjectName(QString::fromUtf8("numPOW3"));
        sizePolicy.setHeightForWidth(numPOW3->sizePolicy().hasHeightForWidth());
        numPOW3->setSizePolicy(sizePolicy);
        numPOW3->setMaximumSize(QSize(51, 27));
        numPOW3->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numPOW3, 2, 2, 1, 1);

        numTANH = new QPushButton(widget);
        numTANH->setObjectName(QString::fromUtf8("numTANH"));
        sizePolicy.setHeightForWidth(numTANH->sizePolicy().hasHeightForWidth());
        numTANH->setSizePolicy(sizePolicy);
        numTANH->setMaximumSize(QSize(51, 27));
        numTANH->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numTANH, 3, 0, 1, 1);

        numTAN = new QPushButton(widget);
        numTAN->setObjectName(QString::fromUtf8("numTAN"));
        sizePolicy.setHeightForWidth(numTAN->sizePolicy().hasHeightForWidth());
        numTAN->setSizePolicy(sizePolicy);
        numTAN->setMaximumSize(QSize(51, 27));
        numTAN->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numTAN, 3, 1, 1, 1);

        numRACINE = new QPushButton(widget);
        numRACINE->setObjectName(QString::fromUtf8("numRACINE"));
        sizePolicy.setHeightForWidth(numRACINE->sizePolicy().hasHeightForWidth());
        numRACINE->setSizePolicy(sizePolicy);
        numRACINE->setMaximumSize(QSize(51, 27));
        numRACINE->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numRACINE, 3, 2, 1, 1);

        numLN = new QPushButton(widget);
        numLN->setObjectName(QString::fromUtf8("numLN"));
        sizePolicy.setHeightForWidth(numLN->sizePolicy().hasHeightForWidth());
        numLN->setSizePolicy(sizePolicy);
        numLN->setMaximumSize(QSize(51, 27));
        numLN->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numLN, 4, 0, 1, 1);

        numLOG = new QPushButton(widget);
        numLOG->setObjectName(QString::fromUtf8("numLOG"));
        sizePolicy.setHeightForWidth(numLOG->sizePolicy().hasHeightForWidth());
        numLOG->setSizePolicy(sizePolicy);
        numLOG->setMaximumSize(QSize(51, 27));
        numLOG->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numLOG, 4, 1, 1, 1);

        numINV = new QPushButton(widget);
        numINV->setObjectName(QString::fromUtf8("numINV"));
        sizePolicy.setHeightForWidth(numINV->sizePolicy().hasHeightForWidth());
        numINV->setSizePolicy(sizePolicy);
        numINV->setMaximumSize(QSize(51, 27));
        numINV->setBaseSize(QSize(51, 27));

        gridLayout->addWidget(numINV, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 178, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        numMOD = new QPushButton(widget);
        numMOD->setObjectName(QString::fromUtf8("numMOD"));
        sizePolicy.setHeightForWidth(numMOD->sizePolicy().hasHeightForWidth());
        numMOD->setSizePolicy(sizePolicy);
        numMOD->setMaximumSize(QSize(51, 27));
        numMOD->setBaseSize(QSize(51, 27));

        horizontalLayout_2->addWidget(numMOD);

        numPOW = new QPushButton(widget);
        numPOW->setObjectName(QString::fromUtf8("numPOW"));
        sizePolicy.setHeightForWidth(numPOW->sizePolicy().hasHeightForWidth());
        numPOW->setSizePolicy(sizePolicy);
        numPOW->setMaximumSize(QSize(51, 27));
        numPOW->setBaseSize(QSize(51, 27));

        horizontalLayout_2->addWidget(numPOW);

        numDIV = new QPushButton(widget);
        numDIV->setObjectName(QString::fromUtf8("numDIV"));
        sizePolicy.setHeightForWidth(numDIV->sizePolicy().hasHeightForWidth());
        numDIV->setSizePolicy(sizePolicy);
        numDIV->setMaximumSize(QSize(51, 27));
        numDIV->setBaseSize(QSize(51, 27));

        horizontalLayout_2->addWidget(numDIV);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        numMINUS = new QPushButton(widget);
        numMINUS->setObjectName(QString::fromUtf8("numMINUS"));
        sizePolicy.setHeightForWidth(numMINUS->sizePolicy().hasHeightForWidth());
        numMINUS->setSizePolicy(sizePolicy);
        numMINUS->setMaximumSize(QSize(51, 27));
        numMINUS->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(numMINUS, 0, 0, 1, 1);

        numPLUS = new QPushButton(widget);
        numPLUS->setObjectName(QString::fromUtf8("numPLUS"));
        sizePolicy.setHeightForWidth(numPLUS->sizePolicy().hasHeightForWidth());
        numPLUS->setSizePolicy(sizePolicy);
        numPLUS->setMaximumSize(QSize(51, 27));
        numPLUS->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(numPLUS, 0, 1, 1, 1);

        numMULT = new QPushButton(widget);
        numMULT->setObjectName(QString::fromUtf8("numMULT"));
        sizePolicy.setHeightForWidth(numMULT->sizePolicy().hasHeightForWidth());
        numMULT->setSizePolicy(sizePolicy);
        numMULT->setMaximumSize(QSize(51, 27));
        numMULT->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(numMULT, 0, 2, 1, 1);

        num7 = new QPushButton(widget);
        num7->setObjectName(QString::fromUtf8("num7"));
        sizePolicy.setHeightForWidth(num7->sizePolicy().hasHeightForWidth());
        num7->setSizePolicy(sizePolicy);
        num7->setMaximumSize(QSize(51, 27));
        num7->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num7, 1, 0, 1, 1);

        num8 = new QPushButton(widget);
        num8->setObjectName(QString::fromUtf8("num8"));
        sizePolicy.setHeightForWidth(num8->sizePolicy().hasHeightForWidth());
        num8->setSizePolicy(sizePolicy);
        num8->setMaximumSize(QSize(51, 27));
        num8->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num8, 1, 1, 1, 1);

        num9 = new QPushButton(widget);
        num9->setObjectName(QString::fromUtf8("num9"));
        sizePolicy.setHeightForWidth(num9->sizePolicy().hasHeightForWidth());
        num9->setSizePolicy(sizePolicy);
        num9->setMaximumSize(QSize(51, 27));
        num9->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num9, 1, 2, 1, 1);

        num4 = new QPushButton(widget);
        num4->setObjectName(QString::fromUtf8("num4"));
        sizePolicy.setHeightForWidth(num4->sizePolicy().hasHeightForWidth());
        num4->setSizePolicy(sizePolicy);
        num4->setMaximumSize(QSize(51, 27));
        num4->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num4, 2, 0, 1, 1);

        num5 = new QPushButton(widget);
        num5->setObjectName(QString::fromUtf8("num5"));
        sizePolicy.setHeightForWidth(num5->sizePolicy().hasHeightForWidth());
        num5->setSizePolicy(sizePolicy);
        num5->setMaximumSize(QSize(51, 27));
        num5->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num5, 2, 1, 1, 1);

        num6 = new QPushButton(widget);
        num6->setObjectName(QString::fromUtf8("num6"));
        sizePolicy.setHeightForWidth(num6->sizePolicy().hasHeightForWidth());
        num6->setSizePolicy(sizePolicy);
        num6->setMaximumSize(QSize(51, 27));
        num6->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num6, 2, 2, 1, 1);

        num1 = new QPushButton(widget);
        num1->setObjectName(QString::fromUtf8("num1"));
        sizePolicy.setHeightForWidth(num1->sizePolicy().hasHeightForWidth());
        num1->setSizePolicy(sizePolicy);
        num1->setMaximumSize(QSize(51, 27));
        num1->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num1, 3, 0, 1, 1);

        num2 = new QPushButton(widget);
        num2->setObjectName(QString::fromUtf8("num2"));
        sizePolicy.setHeightForWidth(num2->sizePolicy().hasHeightForWidth());
        num2->setSizePolicy(sizePolicy);
        num2->setMaximumSize(QSize(51, 27));
        num2->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num2, 3, 1, 1, 1);

        num3 = new QPushButton(widget);
        num3->setObjectName(QString::fromUtf8("num3"));
        sizePolicy.setHeightForWidth(num3->sizePolicy().hasHeightForWidth());
        num3->setSizePolicy(sizePolicy);
        num3->setMaximumSize(QSize(51, 27));
        num3->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num3, 3, 2, 1, 1);

        num0 = new QPushButton(widget);
        num0->setObjectName(QString::fromUtf8("num0"));
        sizePolicy.setHeightForWidth(num0->sizePolicy().hasHeightForWidth());
        num0->setSizePolicy(sizePolicy);
        num0->setMaximumSize(QSize(51, 27));
        num0->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(num0, 4, 0, 1, 1);

        numPOINT = new QPushButton(widget);
        numPOINT->setObjectName(QString::fromUtf8("numPOINT"));
        sizePolicy.setHeightForWidth(numPOINT->sizePolicy().hasHeightForWidth());
        numPOINT->setSizePolicy(sizePolicy);
        numPOINT->setMaximumSize(QSize(51, 27));
        numPOINT->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(numPOINT, 4, 1, 1, 1);

        numSIGN = new QPushButton(widget);
        numSIGN->setObjectName(QString::fromUtf8("numSIGN"));
        sizePolicy.setHeightForWidth(numSIGN->sizePolicy().hasHeightForWidth());
        numSIGN->setSizePolicy(sizePolicy);
        numSIGN->setMaximumSize(QSize(51, 27));
        numSIGN->setBaseSize(QSize(51, 27));

        gridLayout_2->addWidget(numSIGN, 4, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_4);

        PileAffichage = new QPlainTextEdit(widget);
        PileAffichage->setObjectName(QString::fromUtf8("PileAffichage"));
        PileAffichage->setReadOnly(true);

        horizontalLayout_6->addWidget(PileAffichage);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pileDROP = new QPushButton(widget);
        pileDROP->setObjectName(QString::fromUtf8("pileDROP"));
        sizePolicy.setHeightForWidth(pileDROP->sizePolicy().hasHeightForWidth());
        pileDROP->setSizePolicy(sizePolicy);
        pileDROP->setMaximumSize(QSize(60, 27));
        pileDROP->setBaseSize(QSize(85, 27));

        verticalLayout_5->addWidget(pileDROP);

        pileDUP = new QPushButton(widget);
        pileDUP->setObjectName(QString::fromUtf8("pileDUP"));
        sizePolicy.setHeightForWidth(pileDUP->sizePolicy().hasHeightForWidth());
        pileDUP->setSizePolicy(sizePolicy);
        pileDUP->setMaximumSize(QSize(60, 27));
        pileDUP->setBaseSize(QSize(85, 27));

        verticalLayout_5->addWidget(pileDUP);

        pileMEAN = new QPushButton(widget);
        pileMEAN->setObjectName(QString::fromUtf8("pileMEAN"));
        sizePolicy.setHeightForWidth(pileMEAN->sizePolicy().hasHeightForWidth());
        pileMEAN->setSizePolicy(sizePolicy);
        pileMEAN->setMaximumSize(QSize(60, 27));
        pileMEAN->setBaseSize(QSize(85, 27));

        verticalLayout_5->addWidget(pileMEAN);

        pileSUM = new QPushButton(widget);
        pileSUM->setObjectName(QString::fromUtf8("pileSUM"));
        sizePolicy.setHeightForWidth(pileSUM->sizePolicy().hasHeightForWidth());
        pileSUM->setSizePolicy(sizePolicy);
        pileSUM->setMaximumSize(QSize(60, 27));
        pileSUM->setBaseSize(QSize(85, 27));

        verticalLayout_5->addWidget(pileSUM);

        pileSWAP = new QPushButton(widget);
        pileSWAP->setObjectName(QString::fromUtf8("pileSWAP"));
        sizePolicy.setHeightForWidth(pileSWAP->sizePolicy().hasHeightForWidth());
        pileSWAP->setSizePolicy(sizePolicy);
        pileSWAP->setMaximumSize(QSize(60, 27));
        pileSWAP->setBaseSize(QSize(85, 27));

        verticalLayout_5->addWidget(pileSWAP);

        pileCLEAR = new QPushButton(widget);
        pileCLEAR->setObjectName(QString::fromUtf8("pileCLEAR"));
        sizePolicy.setHeightForWidth(pileCLEAR->sizePolicy().hasHeightForWidth());
        pileCLEAR->setSizePolicy(sizePolicy);
        pileCLEAR->setMaximumSize(QSize(60, 27));
        pileCLEAR->setBaseSize(QSize(85, 27));

        verticalLayout_5->addWidget(pileCLEAR);


        horizontalLayout_6->addLayout(verticalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 734, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pileCLEAR, SIGNAL(pressed()), PileAffichage, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        numExpression->setText(QApplication::translate("MainWindow", "Expression", 0, QApplication::UnicodeUTF8));
        numTYPE->clear();
        numTYPE->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Reel", 0, QApplication::UnicodeUTF8)
        );
        numComplexe->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        numDegre->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        numRadian->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        numEVAL->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        numPUSH->setText(QApplication::translate("MainWindow", "PUSH", 0, QApplication::UnicodeUTF8));
        numPUSH->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        numParGch->setText(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        numParGch->setShortcut(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        numParDrt->setText(QApplication::translate("MainWindow", ")", 0, QApplication::UnicodeUTF8));
        numParDrt->setShortcut(QApplication::translate("MainWindow", ")", 0, QApplication::UnicodeUTF8));
        numFACT->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        numFACT->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        numCOSH->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        numCOS->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        numPOW2->setText(QApplication::translate("MainWindow", "x\302\262", 0, QApplication::UnicodeUTF8));
        numPOW2->setShortcut(QApplication::translate("MainWindow", "\302\262", 0, QApplication::UnicodeUTF8));
        numSINH->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        numSIN->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        numPOW3->setText(QApplication::translate("MainWindow", "x\302\263", 0, QApplication::UnicodeUTF8));
        numTANH->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        numTAN->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        numRACINE->setText(QApplication::translate("MainWindow", "\342\210\232x", 0, QApplication::UnicodeUTF8));
        numLN->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        numLOG->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        numINV->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        numMOD->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        numPOW->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        numDIV->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        numDIV->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        numMINUS->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        numMINUS->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        numPLUS->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        numPLUS->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        numMULT->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        numMULT->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        num7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        numPOINT->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        numSIGN->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        pileDROP->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        pileDUP->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        pileMEAN->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        pileSUM->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        pileSWAP->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        pileCLEAR->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
