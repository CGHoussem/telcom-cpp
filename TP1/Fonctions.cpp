#include "Fonctions.h"

int afficherMenuPrincipal() {
	int choice = 0;
	std::system("cls");
	std::cout << "-- GESTION DES ABONNES --\n";
	std::cout << "1.\tCreer un abonne\n";
	std::cout << "2.\tSupprimer un abonne\n";
	std::cout << "3.\tAfficher les abonnes\n";
	std::cout << "-- GESTION DES LIGNES --\n";
	std::cout << "4.\tCreer et associer une ligne a un abonne\n";
	std::cout << "5.\tSupprimer une ligne\n";
	std::cout << "6.\tAfficher les lignes\n";
	std::cout << "-- GESTION DES SERVICES --\n";
	std::cout << "7.\tAssocier un service a une ligne\n";
	std::cout << "8.\tEnlever un service d'une ligne\n";
	std::cout << "9.\tAfficher les services d'une ligne\n\n";
	std::cout << "0.\tQUITTER\n";
	std::cout << "Entrez votre choix: ";
	std::cin >> choice;

	return choice;
}