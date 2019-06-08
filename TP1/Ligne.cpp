#include "Ligne.h"
#include <iostream>

Ligne::Ligne(std::string num, Abonne ab)
	: numero(num), abonne(ab)
{
}

Ligne::Ligne() {

}

Ligne::~Ligne()
{
}

std::string Ligne::getNumero()
{
	return numero;
}

Abonne Ligne::getAbonne()
{
	return abonne;
}

void Ligne::afficher()
{
	std::cout << "Ligne numero " << numero << std::endl;
	std::cout << "\tAbonne: " << abonne.getNumSerie() << std::endl;
}


