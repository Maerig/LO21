#include "log.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include "calculexception.h"

void ecrire_log(std::string str)
{
    {
        std::ofstream f("logs.txt", std::ios::out | std::ios::app);
        if(f)
        {
            time_t heure;
            time(&heure);
            f<<ctime(&heure)<<str<<"\n\n";
            f.close();
        }
        else
            throw CalculException("Ouverture du fichier impossible.");
    }
}

void ecrire_log(std::string str,Donnee* data)
{
    {
        std::ofstream f("logs.txt", std::ios::out | std::ios::app);
        if(f)
        {
            time_t heure;
            time(&heure);
            f<<ctime(&heure)<<str;
            data->afficher(f);
            f<<"\n\n";
            f.close();
        }
        else
            throw CalculException("Ouverture du fichier impossible.");
    }
}
