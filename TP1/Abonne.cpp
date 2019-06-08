#include <iostream>
#include "Abonne.h"

Abonne::Abonne(int num, std::string n, std::string adr)
	: numSerie(num), nom(n), adresse(adr)
{
}
Abonne::Abonne()
{
}
Abonne::~Abonne()
{
}

int Abonne::getNumSerie() {
	return numSerie;
}
std::string Abonne::getNom() {
	return nom;
}
std::string Abonne::getAdresse(){
	return adresse;
}
void Abonne::setNumSerie(int num) {
	numSerie = num;
}
void Abonne::setNom(std::string n) {
	nom = n;
}
void Abonne::setAdresse(std::string adr) {
	adresse = adr;
}
void Abonne::afficher() {
	std::cout << "Abonne " << numSerie << "\n\tNom: " << nom << "\n\tAdresse: " << adresse << std::endl;
}
