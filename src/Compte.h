#ifndef COMPTE_H
#define COMPTE_H

#include <iostream>
#include <string>
using namespace std;

class Compte {
private:
      
    double Solde_Compte;
    int NumeroCompte;
    string Type_Compte;
    string RIB;
    int chequier;

public:

    double solde_Compte;
    int num_Compte;
    string quel_compte;
    string rib_compte;
    int cheque;

    Compte(); // Constructeur par défaut
    Compte(double, int, string, string, int); // Constructeur par défaut
    void afficher(); // Méthode pour afficher les informations du compte
    int recup_num_Compte();
    double recup_solde();
    string recup_type_Compte();
    string recup_RIB();

    void Crediiter(float);
    void Debiter(float);

    int recup_chequier();
    void commdander_chequier();


};

#endif