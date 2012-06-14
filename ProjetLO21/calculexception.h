#ifndef CALCULEXCEPTION_H
#define CALCULEXCEPTION_H

#include <exception>
#include <string>
#include <QString>
#include <QMessageBox>

class CalculException {
private :
    QString info;

public:
    CalculException(const QString str) : info("Erreur : " + str) {}
    const QString getInfo() const { return info; }
    void afficher()
        {
            QMessageBox msgBox(0);
            msgBox.setWindowTitle("Exception");
            msgBox.setText(getInfo());
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStandardButtons(QMessageBox::Ok );
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
        }
};

#endif // CALCULEXCEPTION_H
