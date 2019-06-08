#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Abonne.h"
#include "Ligne.h"
#include "LigneFixe.h"
#include "LigneMobile.h"
#include "Service.h"
#include "ServiceDATA.h"
#include "ServiceSMS.h"
#include "ServiceVoix.h"

void afficherMenuPrincipal();
void afficherMenuLigne();
void afficherChoixAbonnes(std::vector<Abonne>& listeAbonnes);
void afficherChoixLignes(std::vector<LigneMobile>& listeLignes);
void ajouterAbonne(std::vector<Abonne>& listeAbonnes);
void afficherAbonnes(std::vector<Abonne>& listeAbonnes);
void supprimerAbonne(std::vector<Abonne>& listeAbonnes, int numSerie);
Abonne getAbonne(std::vector<Abonne>& listeAbonnes, int numSerie);
void creerLigneFixe(std::vector<LigneFixe>& listeLignes, std::vector<Abonne>& listeAbonnes);
void creerLigneMobile(std::vector<LigneMobile>& listeLignes, std::vector<Abonne>& listeAbonnes);
template<typename T>
void afficherLignes(std::vector<T> listeLignes);
void ajouterService(LigneMobile& l);
void enleverService(LigneMobile& l);
void afficherServices(LigneMobile& l);

int main()
{
	int choice = 0;
	int numSerie = 0;
	int choix;
	std::vector<Abonne> listeAbonnes;
	std::vector<LigneFixe> listeLignesFixe;
	std::vector<LigneMobile> listeLignesMobile;

	std::cout << "Bienvenue à HoussemCom!\n"; 
	do {
		afficherMenuPrincipal();
		std::cout << "Entrez votre choix: ";
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			std::cout << "Au revoir!\n";
			exit(0);
			break;
		case 1:
			ajouterAbonne(listeAbonnes);
			break;
		case 2:
			std::cout << "Entrez le numero de serie de l'abonne a supprimer: ";
			std::cin >> numSerie;
			supprimerAbonne(listeAbonnes, numSerie);
			break;
		case 3:
			afficherAbonnes(listeAbonnes);
			break;
		case 4:
			if (!listeAbonnes.empty()){

				do {
					afficherMenuLigne();
					std::cout << "Entrez votre choix: ";
					std::cin >> choix;
					switch (choix) {
					case 0:
						break;
					case 1:
						creerLigneFixe(listeLignesFixe, listeAbonnes);
						break;
					case 2:
						creerLigneMobile(listeLignesMobile, listeAbonnes);
						break;
					default:
						std::cout << "Choix invalide!\n";
						break;
					}
				} while (choix < 0 || choix > 2);
			}
			else{
				std::cout << "Il n'existe aucun abonne!\n";
			}
			break;
		case 5:
			if (!listeLignesFixe.empty()){
				std::cout << "La liste des ligne fixe:" << std::endl;
				afficherLignes(listeLignesFixe);
			}
			else {
				std::cout << "Il n'existe aucune ligne fixe!" << std::endl;
			}
			if (!listeLignesMobile.empty()){
				std::cout << "La liste des ligne mobile:" << std::endl;
				afficherLignes(listeLignesMobile);
			}
			else {
				std::cout << "Il n'existe aucune ligne mobile!" << std::endl;
			}
			break;
		case 6:
			if (!listeLignesMobile.empty()) {
				afficherChoixLignes(listeLignesMobile);
				std::cin >> choix;
				ajouterService(listeLignesMobile[choix]);
			}
			else {
				std::cout << "Il n'existe aucune ligne mobile!" << std::endl;
			}
			break;
		case 7:
			if (!listeLignesMobile.empty()) {
				afficherChoixLignes(listeLignesMobile);
				std::cin >> choix;
				enleverService(listeLignesMobile[choix]);
			}
			else {
				std::cout << "Il n'existe aucune ligne mobile!" << std::endl;
			}
			break;
		case 8:
			if (!listeLignesMobile.empty()) {
				afficherChoixLignes(listeLignesMobile);
				std::cin >> choix;
				afficherServices(listeLignesMobile[choix]);
			}
			else {
				std::cout << "Il n'existe aucune ligne mobile!" << std::endl;
			}
			break;
		case 9:
			if (!listeLignesMobile.empty()) {
				for (Abonne& a : listeAbonnes) {
					float somme = 0;
					for (LigneMobile& l : listeLignesMobile) {
						if (l.getAbonne().getNumSerie() == a.getNumSerie()) {
							for (Service& s : l.getServices()) {
								somme += s.getPrix();
							}
						}
					}
					std::cout << "Facture de l'abonne " << a.getNom() << " est de somme : " << somme << " Euro" << std::endl;
				}
			}
			else {
				std::cout << "Il n'existe aucune ligne mobile a facturer" << std::endl;
			}
			break;
		case 10:
			if (!listeLignesMobile.empty()){
				for (LigneMobile& l : listeLignesMobile) {
					for (Service& s : l.getServices()) {
						s.reset();
					}
				}
				std::cout << "Tout les compteurs ont ete mise a zero" << std::endl;
			}
			else {
				std::cout << "Il n'existe aucune ligne" << std::endl;
			}
			break;
		default:
			break;
		}
		std::system("pause");
	} while (choice != 0);
}

void afficherMenuPrincipal() {
	std::system("cls");
	std::cout << "-- GESTION DES ABONNES --\n";
	std::cout << "1.\tCreer un abonne\n";
	std::cout << "2.\tSupprimer un abonne\n";
	std::cout << "3.\tAfficher les abonnes\n";
	std::cout << "-- GESTION DES LIGNES --\n";
	std::cout << "4.\tCreer et associer une ligne a un abonne\n";
	std::cout << "5.\tAfficher les lignes\n";
	std::cout << "-- GESTION DES SERVICES --\n";
	std::cout << "6.\tAjouter un service a une ligne\n";
	std::cout << "7.\tEnlever un service d'une ligne\n";
	std::cout << "8.\tAfficher les services d'une ligne\n";
	std::cout << "-- FACTURES DES ABONNES --\n";
	std::cout << "9.\tAfficher la facture d'un abonne\n";
	std::cout << "10.\tRemettre tous les compteurs a zero\n";
	std::cout << "\t----------------------\n";
	std::cout << "0.\tQUITTER\n";
}
void afficherMenuLigne() {
	std::system("cls");
	std::cout << "La liste de possibilites des lignes:" << std::endl;
	std::cout << "1.\tLigne fixe\n";
	std::cout << "2.\tLigne mobile\n";
	std::cout << "0.\tANNULER\n";
}
void afficherChoixAbonnes(std::vector<Abonne>& listeAbonnes) {
	std::cout << "Voici la liste des abonnes:" << std::endl;
	for (size_t i = 0; i < listeAbonnes.size(); i++) {
		std::cout << "\t" << i << ". " << listeAbonnes[i].getNom() << std::endl;
	}
}
void afficherChoixLignes(std::vector<LigneMobile>& listeLignes) {
	std::cout << "Voici la liste des lignes mobile:" << std::endl;
	for (size_t i = 0; i < listeLignes.size(); i++) {
		std::cout << "\t" << i << ". " << listeLignes[i].getNumero() << std::endl;
	}
}

void ajouterAbonne(std::vector<Abonne>& listeAbonnes) {
	std::srand(std::time(NULL));
	std::string name, adresse;

	std::cout << "Entrez le nom de l'abonne: ";
	std::cin >> name;
	std::cout << "Entrez l'adresse de l'abonne: ";
	std::cin >> adresse;

	Abonne a((rand() % RAND_MAX) & RAND_MAX, name, adresse);
	listeAbonnes.push_back(a);
	std::cout << "L'abonne " << name << " a ete ajouter avec succee!\n";
}
void afficherAbonnes(std::vector<Abonne>& listeAbonnes) {
	for (Abonne& a : listeAbonnes) {
		a.afficher();
		std::cout << "----------\n";
	}
}
void supprimerAbonne(std::vector<Abonne>& listeAbonnes, int numSerie) {
	for (size_t i = 0; i < listeAbonnes.size(); i++) {
		if (listeAbonnes[i].getNumSerie() == numSerie) {
			listeAbonnes.erase(listeAbonnes.begin() + i);
		}
	}
	std::cout << "L'abonne de numero de serie " << numSerie << " a ete supprimer avec succee!\n";
}
Abonne getAbonne(std::vector<Abonne>& listeAbonnes, int numSerie) {
	Abonne a;
	for (size_t i = 0; i < listeAbonnes.size(); i++) {
		if (listeAbonnes[i].getNumSerie() == numSerie) {
			a = listeAbonnes[i];
		}
	}
	return a;
}

void creerLigneFixe(std::vector<LigneFixe>& listeLignes, std::vector<Abonne>& listeAbonnes) {
	std::string locGeo, numLigne;
	int abonneIndex;
	std::cout << "Entrez le numero de la ligne: ";
	std::cin >> numLigne;
	std::cout << "Entrez la location geographique: ";
	std::cin >> locGeo;
	afficherChoixAbonnes(listeAbonnes);
	std::cout << "Choisir l'abonne associe: ";
	std::cin >> abonneIndex;
	LigneFixe l(numLigne, listeAbonnes[abonneIndex], locGeo);
	listeLignes.push_back(l);
	std::cout << "La ligne " << numLigne << " a ete ajouter avec succee!\n";
}
void creerLigneMobile(std::vector<LigneMobile>& listeLignes, std::vector<Abonne>& listeAbonnes) {
	std::string numLigne;
	int abonneIndex;
	char choix;
	std::cout << "Entrez le numero de la ligne: ";
	std::cin >> numLigne;
	afficherChoixAbonnes(listeAbonnes);
	std::cout << "Choisir l'abonne associe: ";
	std::cin >> abonneIndex;
	LigneMobile l(numLigne, listeAbonnes[abonneIndex]);
	std::cout << "Voulez-vous ajouter un/des service(s) a cette ligne? (O/N) ";
	std::cin >> choix;

	if (toupper(choix) == 'O') {
		ajouterService(l);
	}

	listeLignes.push_back(l);
	std::cout << "La ligne " << numLigne << " a ete ajouter avec succee!\n";
}

template <typename T>
void afficherLignes(std::vector<T> listeLignes) {
	for (T& l : listeLignes) {
		l.afficher();
		std::cout << "-----------\n";
	}
}

void ajouterService(LigneMobile& l) {
	std::string type;
	Service s;
	std::cout << "Les services sont: SMS, DATA, Voix\n";
	std::cout << "Entrez le type du service voulu: ";
	std::cin >> type;
	if (type.compare("SMS") == 0) {
		s = ServiceSMS();
	}
	else if (type.compare("DATA") == 0) {
		int envIni;
		std::cout << "Entrez le montant de l'enveloppe initiale (Go): ";
		std::cin >> envIni;
		s = ServiceDATA(envIni);
	}
	else if (type.compare("Voix") == 0) {
		s = ServiceVoix();
	}
	l.ajouterService(s);
}
void enleverService(LigneMobile& l) {
	int choix;
	std::cout << "La liste des services de cette ligne est:" << std::endl;
	for (size_t i = 0; i < l.getServices().size(); i++) {
		Service s(l.getServices()[i]);
		std::cout << "\t" << i << ". " << s.getDescription() << std::endl;
	}
	std::cout << "Entrez le service a enlever: ";
	std::cin >> choix;
	if (choix >= 0 && choix <= 2) {
		l.retirerService(l.getServices()[choix].getNumero());
	}
	else {
		std::cout << "Choix Invalide!" << std::endl;
	}
}
void afficherServices(LigneMobile& l) {
	std::cout << "La liste des services de cette ligne est:" << std::endl;
	for (size_t i = 0; i < l.getServices().size(); i++) {
		std::cout << "\t";
		l.getServices()[i].afficher();
	}
}