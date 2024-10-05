#include "Compte.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>


Compte::Compte(double Lesolde, int Lenum_Compte, string Letype_Compte, string Lerib, int Lechequier)
{
    Solde_Compte = Lesolde;
    NumeroCompte = Lenum_Compte;
    Type_Compte = Letype_Compte;
    RIB = Lerib;
    chequier = Lechequier;
}

void Compte::afficher()
{
    cout << "Solde du compte : " << Solde_Compte << endl;
    cout << "Numéro de compte : " << NumeroCompte << endl;
    cout << "Type de compte : " << Type_Compte << endl;
}

int Compte::recup_num_Compte()
{
    num_Compte = NumeroCompte;
    return num_Compte;
}

double Compte::recup_solde()
{
    solde_Compte = Solde_Compte;
    return solde_Compte;
}

string Compte::recup_type_Compte()
{
    Type_Compte = Type_Compte;
    return Type_Compte;
}

string Compte::recup_RIB()
{
    rib_compte = RIB;
    return rib_compte;
}

void Compte::Crediiter(float montant)
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con = nullptr;  // Initialise le pointeur à nullptr pour éviter les erreurs d'utilisation
    sql::PreparedStatement *pstmt = nullptr;

    try {
        // Initialisation de la connexion MySQL
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
        con->setSchema("Banque");  // Remplace par le nom de ta base de données

        // Mise à jour du solde du compte
        Solde_Compte += montant;

        // Prépare la requête SQL pour mettre à jour le solde
        pstmt = con->prepareStatement("UPDATE Clients SET Solde = ? WHERE id = ?");
        pstmt->setDouble(1, Solde_Compte);  // Met à jour avec le nouveau solde
        pstmt->setInt(2, NumeroCompte);  // Utilise le numéro de compte pour identifier l'entrée

        pstmt->executeUpdate();  // Exécute la mise à jour
        cout << "Solde mis à jour avec succès!\n";

    } catch (sql::SQLException &e) {
        cerr << "Erreur SQL : " << e.what() << endl;  // Affiche une erreur s'il y a un problème
    }

    // Nettoyage des ressources
    delete pstmt;
    delete con;
}


void Compte::Debiter(float montant)
{
    if (Solde_Compte >= montant)
    {
        sql::mysql::MySQL_Driver *driver;
    sql::Connection *con = nullptr;  // Initialise le pointeur à nullptr pour éviter les erreurs d'utilisation
    sql::PreparedStatement *pstmt = nullptr;

    try {
        // Initialisation de la connexion MySQL
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
        con->setSchema("Banque");  // Remplace par le nom de ta base de données

        // Mise à jour du solde du compte
        Solde_Compte -= montant;

        // Prépare la requête SQL pour mettre à jour le solde
        pstmt = con->prepareStatement("UPDATE Clients SET Solde = ? WHERE id = ?");
        pstmt->setDouble(1, Solde_Compte);  // Met à jour avec le nouveau solde
        pstmt->setInt(2, NumeroCompte);  // Utilise le numéro de compte pour identifier l'entrée

        pstmt->executeUpdate();  // Exécute la mise à jour
        cout << "Solde mis à jour avec succès!\n";

    } catch (sql::SQLException &e) {
        cerr << "Erreur SQL : " << e.what() << endl;  // Affiche une erreur s'il y a un problème
    }

    // Nettoyage des ressources
    delete pstmt;
    delete con;
    }
    else
    {
        cout << "Solde insuffisant" << endl;
    }
}

int Compte::recup_chequier()
{
    cheque = chequier;
    return cheque;
}
void Compte::commdander_chequier()
{
    chequier = 1;
}
