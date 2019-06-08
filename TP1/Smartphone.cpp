#include "Smartphone.h"
#include <iostream>


Smartphone::Smartphone(int num, std::string mar, std::string mod, std::string col)
	: numSerie(num), marque(mar), modele(mod), couleur(col)
{
}

Smartphone::Smartphone()
{
}


Smartphone::~Smartphone()
{
}

int Smartphone::getNumSerie()
{
	return numSerie;
}

std::string Smartphone::getMarque()
{
	return marque;
}

std::string Smartphone::getModele()
{
	return modele;
}

std::string Smartphone::getCouleur()
{
	return couleur;
}

void Smartphone::setNumSerie(int num)
{
	numSerie = num;
}

void Smartphone::setMarque(std::string mar)
{
	marque = mar;
}

void Smartphone::setModele(std::string mod)
{
	modele = mod;
}

void Smartphone::setCouleur(std::string col)
{
	couleur = col;
}

void Smartphone::afficher()
{
	std::cout << "Smartphone " << numSerie << std::endl;
	std::cout << "\tMarque: " << marque << std::endl;
	std::cout << "\tModele: " << modele << std::endl;
	std::cout << "\tCouleur: " << couleur << std::endl;
}
