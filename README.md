Guillaume Corentin
BTS CIEL 2ème Année

Ce Projet possède comme sujet, la gestion d'une banque

Le système possède une base de données.

Ce base de données contient toutes les information des clients, 1 ligne est égal a un client.

Le programme en lui même permet la gestion de compte client.

Afin de gérer son compte l'utilisateur doit se connecter a l'aide de son numero de compte/client et son compte de sécurité.

Si les infomations sont correcte, l'utilisateur auras la possibilité de:

-Créditer son compte (faire un dépôt)
-Débiter son compte (faire un retrait)
-Effectuer un virement à un autre client de la banque
-Commander un chéquier
-Récurérer son RIB

Commande pour compiler les programmes si le dossier le dossier complet a été ouvert

    g++ -o build/main src/main.cpp src/Compte.cpp src/Client.cpp -I/usr/include/cppconn -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn

Commande pour executer le main si le dossier le dossier complet a été ouvert

    ./build/main