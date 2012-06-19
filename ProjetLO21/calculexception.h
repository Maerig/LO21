#ifndef CALCULEXCEPTION_H
#define CALCULEXCEPTION_H

#include <exception>
#include <string>
#include <QString>
#include <QMessageBox>

/// \brief Classe utilisee pour les exceptions.

class CalculException {
private :
    /// \brief Contient le message a afficher lors de l'exception.
    QString info;

public:
    /// \brief Constructeur de la classe.
    /// \param str : Message a afficher.
    CalculException(const QString str) : info("Erreur : " + str) {}
    /// \brief Getter de la classe.
    /// Renvoie le message a afficher.
    /// \return info
    const QString getInfo() const { return info; }
    /// \brief Methode utilisee pour afficher l'exception dans une fenetre.
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
