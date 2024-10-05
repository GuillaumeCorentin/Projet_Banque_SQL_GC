// Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Compte.h"
using namespace std;

class Client {

private:

    string nom;
    string prenom;
    string numero_Telephone;
    string numero_CIN;
    int numero_Client;
    int code_Securite;
    
    int choix;
    
public:

    int num_Client;
    int code_secu;
    string num_Telephone;
    string CIN_Client;
    string nom_client;
    string prenom_client;
    //string rib_compte;
    
    Client(); // Constructeur par défaut
    Client(string, string, string, string, int, int); // Constructeur par défaut
    void afficher(); // Méthode pour afficher les informations du client
    int recup_num_Client();
    int recup_code_Securite();
    string recup_numero_Telephone();
    string recup_nom();
    string recup_prenom();
    string recup_CIN();
    //string recupRIB();
    
    int menu_client();
    
};



#endif
