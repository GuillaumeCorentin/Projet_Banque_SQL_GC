//Client.cpp
#include "Client.h"

#include <iostream>
#include <string>
using namespace std;

//Constructeur par défaut
Client::Client(string Lenom, string Leprenom, string Lenumero_Telephone, string Lenumero_CIN ,int Lenumero_Client, int Lecode_Securite) {
    
    nom = Lenom;
    prenom = Leprenom;
    numero_Telephone = Lenumero_Telephone;
    numero_CIN = Lenumero_CIN;
    numero_Client = Lenumero_Client;
    code_Securite = Lecode_Securite;
    

}

void Client::afficher() {
    
    cout << "Nom : " << nom << endl;
    cout << "Prénom : " << prenom << endl;
    cout << "Numéro de téléphone : " << numero_Telephone << endl;
    cout << "Numéro de compte : " << numero_Client << endl;
    cout << "Numéro CIN : " << numero_CIN << endl;
    
}

int Client::recup_num_Client() {
    num_Client = numero_Client;
    return num_Client;
}

int Client::recup_code_Securite() {
    code_secu = code_Securite;
    return code_secu;
}

string Client::recup_numero_Telephone() {
    num_Telephone = numero_Telephone;
    return num_Telephone;
}

string Client::recup_nom() {
    nom_client = nom;
    return nom_client;
}

string Client::recup_prenom() {
    prenom_client = prenom;
    return prenom_client;
}

string Client::recup_CIN() {
    CIN_Client = numero_CIN;
    return CIN_Client;
}

/*string Client::recupRIB() {
    rib_compte = compte.recup_RIB();
    return rib_compte;
}*/

int Client::menu_client() {

        cout << "Menu Client :" << endl << endl;
        cout << "1. Afficher les informations du client" << endl;
        cout << "2. Afficher le solde du compte" << endl;
        cout << "3. Effectuer un dépôt" << endl;
        cout << "4. Effectuer un retrait" << endl;
        cout << "5. Effectuer un virement" << endl;
        cout << "6. Recupérer son RIB" << endl;
        cout << "7. Commander un chèquier" << endl;
        cout << "8. Quitter" << endl << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        return choix;
}     

