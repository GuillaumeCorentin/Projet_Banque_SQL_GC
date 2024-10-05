#include <iostream>
#include <string>
#include "Client.h"
#include "Compte.h"

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

using namespace std;

int NumeroCompte;
int CodeSecure;

int selection; // Variable pour stocker la sélection de l'utilisateur
float montant;
int choix;
string reponse;
int boucle = 0;
int Bboucle = 1;

int BID;
string BNom;
string BPrenom;
string BTelephone;
string BCIN;
int BCode_Secu;
string BRIB;
string BType_Compte;
float BSolde;

// Fonction pour afficher toutes les données de la table 'Clients'
void afficherDonnees(sql::Connection *con) {
    sql::PreparedStatement *pstmt;
    sql::ResultSet *res;

    pstmt = con->prepareStatement("SELECT ID, Nom, Prenom, Telephone, CIN, Code_Secu, RIB, Type_Compten, Solde FROM Clients");

    res = pstmt->executeQuery();

    cout << "\nDonnées actuelles de la table 'Clients':\n";
    while (res->next()) {
            cout << "ID: " << res->getInt("ID")
                  << ", Nom: " << res->getString("Nom")
                  << ", Prénom: " << res->getString("Prenom")
                  << "Telephone: " << res->getString("Telephone")
                  << ", CIN: " << res->getString("CIN")
                  << ", Code_Secu: " << res->getString("Code_Secu")
                  << "RIB: " << res->getString("RIB")
                  << ", Type_Compte: " << res->getString("Type_Compte")
                  << ", Solde: " << res->getDouble("Solde") << endl;
                  
    }

    delete res;
    delete pstmt;
}

// Fonction pour récupérer et afficher les données d'un client spécifique
void RecupClientSpecifique(sql::Connection *con) {
    int clientID;
    //cout << "\nEntrez l'ID du client à rechercher: ";
    //cin >> clientID;
    

    sql::PreparedStatement *pstmt;
    sql::ResultSet *res;
    
        clientID = Bboucle;
        pstmt = con->prepareStatement("SELECT ID, Nom, Prenom, Telephone, CIN, Code_Secu, RIB, Type_Compte, Solde FROM Clients WHERE ID = ?");
        pstmt->setInt(1, clientID); //Select de la ligne du client a afficher

        res = pstmt->executeQuery();

        if(res->next()) {
            cout << "ID: " << res->getInt("ID")
                << ", Nom: " << res->getString("Nom")
                << ", Prénom: " << res->getString("Prenom")
                << ", Telephone: " << res->getString("Telephone")
                << ", CIN: " << res->getString("CIN")
                << ", Code_Secu: " << res->getInt("Code_Secu")
                << ", RIB: " << res->getString("RIB")
                << ", Type_Compte: " << res->getString("Type_Compte")
                << ", Solde: " << res->getDouble("Solde")
                << ", BOUCLE: " << boucle << endl;

            BID = res->getInt("ID");
            BNom = res->getString("Nom");
            BPrenom = res->getString("Prenom");
            BTelephone = res->getString("Telephone");
            BCIN = res->getString("CIN");
            BCode_Secu = res->getInt("Code_Secu");
            BRIB = res->getString("RIB");
            BType_Compte = res->getString("Type_Compte");
            BSolde = res->getDouble("Solde");
            
        } else {
            cout << "Aucun client trouvé avec l'ID " << clientID << ".\n";
        }

        Bboucle++;

    delete res;
    delete pstmt;
}

int main()
{
        try {
            sql::mysql::MySQL_Driver *driver;
            sql::Connection *con;

            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
            con->setSchema("Banque");

            int choix;

            RecupClientSpecifique(con);

            Client Guillaume(BNom, BPrenom, BTelephone, BCIN, BID, BCode_Secu); //Instanciation d'un objet a partir des données de la base de données
            Compte CompteGuillaume1(BSolde, BID, BType_Compte, BRIB, 0);
            
            RecupClientSpecifique(con);
            Client Sungur(BNom, BPrenom, BTelephone, BCIN, BID, BCode_Secu);
            Compte CompteSungur1(BSolde, BID, BType_Compte, BRIB, 0);

            RecupClientSpecifique(con);
            
            Client Pereira(BNom, BPrenom, BTelephone, BCIN, BID, BCode_Secu);
            Compte ComptePereira1(BSolde, BID, BType_Compte, BRIB, 0);

            while (true) {
                cout << " ==================== BIENVENUE DANS VOTRE BANQUE ==================== " << endl;
                cout << " ============================= SELECTION ============================= " << endl;
                cout << " 1. Me connecter " << endl;
                cout << " 2. Quitter " << endl;
                cout << " ============================ VOTRE CHOIX ============================ " << endl;
                cout << "Selection : ";
                cin >> selection;

                switch (selection) {
                case 1:

                    boucle = 0;
                    cout << " ===================== CONNECTEZ-VOUS ===================== " << endl;
                    cout << "Numéro de compte : ";
                    cin >> NumeroCompte;
                    cout << "Code de sécurité : ";
                    cin >> CodeSecure;

                    if (NumeroCompte == Guillaume.recup_num_Client() && CodeSecure == Guillaume.recup_code_Securite()) 
                    {
                        while(boucle != 1)
                    {
                        cout << "\nBienvenue " << Guillaume.recup_nom() << " " << Guillaume.recup_prenom() << " !" << endl << endl;
                        switch (Guillaume.menu_client())
                        {
                        case 1:

                            Guillaume.afficher();
                            break;
                        
                        case 2:

                            cout << "Le solde de votre compte est de " << CompteGuillaume1.recup_solde() << " euros" << endl;
                            break;

                        case 3:

                            cout << "Entrez le montant à déposer : ";
                            cin >> montant;
                            CompteGuillaume1.Crediiter(montant);
                            cout << "'Vous avez déposé " << montant << " euros" << endl;
                            cout << "Votre nouveau solde est de " << CompteGuillaume1.recup_solde() << " euros" << endl;
                            break;
                        
                        case 4:

                            cout << "Entrez le montant à retirer : ";
                            cin >> montant;
                            CompteGuillaume1.Debiter(montant);
                            cout << " Vous avez retiré " << montant << " euros" << endl;
                            cout << "Votre nouveau solde est de " << CompteGuillaume1.recup_solde() << " euros" << endl;
                            break;

                        case 5:

                            cout << "Quel est le montant à transférer ? ";
                            cin >> montant;
                            cout << " A qui voulez-vous transférer ? ";
                            cin >> NumeroCompte;
                            if(NumeroCompte == CompteGuillaume1.recup_num_Compte())
                            {
                                cout << "Vous ne pouvez pas transférer de l'argent sur votre propre compte" << endl;
                            }
                            if (NumeroCompte == CompteSungur1.recup_num_Compte())
                            {
                                CompteGuillaume1.Debiter(montant);
                                CompteSungur1.Crediiter(montant);
                                cout << "Vous avez transféré " << montant << " euros à " << Sungur.recup_nom() << " " << Sungur.recup_prenom() << endl;
                            }
                            if (NumeroCompte == ComptePereira1.recup_num_Compte())
                            {
                                CompteGuillaume1.Debiter(montant);
                                ComptePereira1.Crediiter(montant);
                                cout << "Vous avez transféré " << montant << " euros à " << Pereira.recup_nom() << " " << Pereira.recup_prenom() << endl;
                            }
                            if(NumeroCompte != CompteSungur1.recup_num_Compte() && NumeroCompte != ComptePereira1.recup_num_Compte())
                            {
                                cout << "Ce numéro de compte n'existe pas" << endl;
                            }
                            break;

                        case 6:

                            cout << "Nom: " << Guillaume.recup_nom() << endl;
                            cout << "Prénom: " << Guillaume.recup_prenom() << endl;
                            cout << "Votre RIB: " << CompteGuillaume1.recup_RIB() << endl;
                            break;

                        case 7: 

                        if (CompteGuillaume1.recup_chequier() == 1)
                        {
                            cout << "Vous avez un chéquier" << endl;
                        }
                        if(CompteGuillaume1.recup_chequier() == 0)  
                        {
                            cout << "Vous n'avez pas de chéquier" << endl;
                            cout << "Voulez-vous en acheter un ? (1 pour oui, 0 pour non) ";
                            cin >> choix;
                            if (choix == 1)
                            {
                                CompteGuillaume1.commdander_chequier();
                                cout << "\nVous avez commander un chéquier" << endl;
                            }

                            if (choix == 0)
                            {
                                cout << "\nVous n'avez pas commander de chéquier" << endl;
                            }
                        }

                        break;

                        case 8:

                            boucle = 1;  // Cela va arrêter la boucle de ce client
                            NumeroCompte = 0;  // Réinitialise le numéro de compte
                            CodeSecure = 0;  // Réinitialise le code de sécurité
                            cout << "Vous avez été déconnecté. Retour au menu principal." << endl;
                            break;

                        default:
                        
                            cout << "Choix invalide" << endl;
                            break;
                        }
                        cout << "\nAppuyez sur Entrée pour continuer..." << endl;
                        cin.ignore();
                        cin.get();
                        
                        }
                    }
                    else if (NumeroCompte == CompteSungur1.recup_num_Compte() && CodeSecure == Sungur.recup_code_Securite())
                    {

                        while(boucle != 1)
                    {
                        cout << "\nBienvenue " << Sungur.recup_nom() << " " << Sungur.recup_prenom() << " !" << endl << endl;
                        switch (Sungur.menu_client())
                        {
                        case 1:
                                Sungur.afficher();
                                break;
                        
                        case 2:

                            cout << "Le solde de votre compte est de " << CompteSungur1.recup_solde() << " euros" << endl;
                            break;

                        case 3:

                            cout << "Entrez le montant à déposer : ";
                            cin >> montant;
                            CompteSungur1.Crediiter(montant);
                            cout << "'Vous avez déposé " << montant << " euros" << endl;
                            cout << "Votre nouveau solde est de " << CompteSungur1.recup_solde() << " euros" << endl;
                            break;
                        
                        case 4:

                            cout << "Entrez le montant à retirer : ";
                            cin >> montant;
                            CompteSungur1.Debiter(montant);
                            cout << " Vous avez retiré " << montant << " euros" << endl;
                            cout << "Votre nouveau solde est de " << CompteSungur1.recup_solde() << " euros" << endl;
                            break;

                        case 5:

                            cout << "Quel est le montant à transférer ? ";
                            cin >> montant;
                            cout << " A qui voulez-vous transférer ? ";
                            cin >> NumeroCompte;
                            if(NumeroCompte == CompteGuillaume1.recup_num_Compte())
                            {
                                cout << "Vous ne pouvez pas transférer de l'argent sur votre propre compte" << endl;
                                CompteSungur1.Crediiter(montant);
                            }
                            if (NumeroCompte == CompteGuillaume1.recup_num_Compte())
                            {
                                CompteSungur1.Debiter(montant);
                                CompteGuillaume1.Crediiter(montant);
                                cout << "Vous avez transféré " << montant << " euros à " << Guillaume.recup_nom() << " " << Guillaume.recup_prenom() << endl;
                            }
                            if (NumeroCompte == ComptePereira1.recup_num_Compte())
                            {
                                CompteSungur1.Debiter(montant);
                                ComptePereira1.Crediiter(montant);
                                cout << "Vous avez transféré " << montant << " euros à " << Pereira.recup_nom() << " " << Pereira.recup_prenom() << endl;
                            }
                            if(NumeroCompte != CompteGuillaume1.recup_num_Compte() && NumeroCompte != ComptePereira1.recup_num_Compte())
                            {
                                cout << "Ce numéro de compte n'existe pas" << endl;
                                
                            }
                            break;

                        case 6:

                            cout << "Nom: " << Sungur.recup_nom() << endl;
                            cout << "Prénom: " << Sungur.recup_prenom() << endl;
                            cout << "Votre RIB: " << CompteSungur1.recup_RIB() << endl;
                            break;

                        case 7: 

                        if (CompteSungur1.recup_chequier() == 1)
                        {
                            cout << "Vous avez un chéquier" << endl;
                        }
                        if(CompteSungur1.recup_chequier() == 0)  
                        {
                            cout << "Vous n'avez pas de chéquier" << endl;
                            cout << "Voulez-vous en acheter un ? (1 pour oui, 0 pour non) ";
                            cin >> choix;
                            if (choix == 1)
                            {
                                CompteSungur1.commdander_chequier();
                                cout << "\nVous avez commander un chéquier" << endl;

                            }

                            if (choix == 0)
                            {
                                cout << "\nVous n'avez pas commander de chéquier" << endl;
                            }
                        }

                        break;

                        case 8:
                            boucle = 1;  // Cela va arrêter la boucle de ce client
                            NumeroCompte = 0;  // Réinitialise le numéro de compte
                            CodeSecure = 0;  // Réinitialise le code de sécurité
                            cout << "Vous avez été déconnecté. Retour au menu principal." << endl;
                            break;

                        default:
                            cout << "Choix invalide" << endl;
                            break;
                        }
                        cout << "\nAppuyez sur Entrée pour continuer..." << endl;
                        cin.ignore();
                        cin.get();
                        
                        }
                    }
                    else if (NumeroCompte == ComptePereira1.recup_num_Compte() && CodeSecure == Pereira.recup_code_Securite()) 
                    {

                        while(boucle != 1)
                    {
                        cout << "\nBienvenue " << Pereira.recup_nom() << " " << Pereira.recup_prenom() << " !" << endl << endl;
                        switch (Pereira.menu_client())
                        {
                        case 1:

                                Pereira.afficher();
                                break;
                        
                        case 2:

                            cout << "Le solde de votre compte est de " << ComptePereira1.recup_solde() << " euros" << endl;
                            break;

                        case 3:

                            cout << "Entrez le montant à déposer : ";
                            cin >> montant;
                            ComptePereira1.Crediiter(montant);
                            cout << "'Vous avez déposé " << montant << " euros" << endl;
                            cout << "Votre nouveau solde est de " << ComptePereira1.recup_solde() << " euros" << endl;
                            break;
                        
                        case 4:

                            cout << "Entrez le montant à retirer : ";
                            cin >> montant;
                            ComptePereira1.Debiter(montant);
                            cout << " Vous avez retiré " << montant << " euros" << endl;
                            cout << "Votre nouveau solde est de " << ComptePereira1.recup_solde() << " euros" << endl;
                            break;

                        case 5:

                            cout << "Quel est le montant à transférer ? ";
                            cin >> montant;
                            cout << " A qui voulez-vous transférer ? ";
                            cin >> NumeroCompte;
                            if(NumeroCompte == ComptePereira1.recup_num_Compte())
                            {
                                cout << "Vous ne pouvez pas transférer de l'argent sur votre propre compte" << endl;
                            }
                            if (NumeroCompte == CompteGuillaume1.recup_num_Compte())
                            {
                                ComptePereira1.Debiter(montant);
                                CompteSungur1.Crediiter(montant);
                                cout << "Vous avez transféré " << montant << " euros à " << Guillaume.recup_nom() << " " << Guillaume.recup_prenom() << endl;
                            }
                            if (NumeroCompte == ComptePereira1.recup_num_Compte())
                            {
                                ComptePereira1.Debiter(montant);
                                ComptePereira1.Crediiter(montant);
                                cout << "Vous avez transféré " << montant << " euros à " << Sungur.recup_nom() << " " << Sungur.recup_prenom() << endl;
                            }
                            if(NumeroCompte != CompteSungur1.recup_num_Compte() && NumeroCompte != CompteGuillaume1.recup_num_Compte())
                            {
                                cout << "Ce numéro de compte n'existe pas" << endl;
                            }
                            break;

                        case 6:

                            cout << "Nom: " << Pereira.recup_nom() << endl;
                            cout << "Prénom: " << Pereira.recup_prenom() << endl;
                            cout << "Votre RIB: " << ComptePereira1.recup_RIB() << endl;
                            break;

                        case 7: 

                        if (ComptePereira1.recup_chequier() == 1)
                        {
                            cout << "Vous avez un chéquier" << endl;
                        }
                        if(ComptePereira1.recup_chequier() == 0)  
                        {
                            cout << "Vous n'avez pas de chéquier" << endl;
                            cout << "Voulez-vous en acheter un ? (1 pour oui, 0 pour non) ";
                            cin >> choix;
                            if (choix == 1)
                            {
                                ComptePereira1.commdander_chequier();
                                cout << "\nVous avez commander un chéquier" << endl;

                            }

                            if (choix == 0)
                            {
                                cout << "\nVous n'avez pas commander de chéquier" << endl;
                            }
                        }
                        break;

                        case 8:
                            boucle = 1;  // Cela va arrêter la boucle de ce client
                            NumeroCompte = 0;  // Réinitialise le numéro de compte
                            CodeSecure = 0;  // Réinitialise le code de sécurité
                            cout << "Vous avez été déconnecté. Retour au menu principal." << endl;
                            break;

                        default:
                            cout << "Choix invalide" << endl;
                            break;
                        }
                        cout << "\nAppuyez sur Entrée pour continuer..." << endl;
                        cin.ignore();
                        cin.get();

                    }
                    }
                    else 
                    {
                        cout << "Numéro de compte ou code de sécurité incorrect" << endl;
                    }
                    break;

                case 2:
                cout << "Au revoir" << endl;
                return 0;
                break;

                default:
                cout << "Choix invalide" << endl;
                break;

                }
            }
            
        delete con;
        }
    
    catch (sql::SQLException &e) 
    {

        cerr << "Erreur MySQL : " << e.what() << endl;
        return 1;
    }
    
    return 0;
}


