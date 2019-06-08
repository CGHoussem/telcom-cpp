#include <iostream>
#include "LigneMobile.h"

LigneMobile::LigneMobile(std::string num, Abonne ab)
{
	numero = num;
	abonne = ab;
}

LigneMobile::LigneMobile()
{
}


LigneMobile::~LigneMobile()
{
}

std::vector<Service> LigneMobile::getServices()
{
	return services;
}

void LigneMobile::ajouterService(Service s)
{
	services.push_back(s);
}

void LigneMobile::retirerService(int numService)
{
	for (size_t i = 0; i < services.size(); i++) {
		if (services[i].getNumero() == numService) {
			services.erase(services.begin() + i);
		}
	}
	std::cout << "Le service a ete retirer avec succee" << std::endl;
}

void LigneMobile::afficher()
{
	Ligne::afficher();
	if (!services.empty()){
		std::cout << "\tServices:\n";
		for (Service& s : services) {
			std::cout << "\t";
			s.afficher();
			std::cout << "\t-----------\n";
		}
	}
	else {
		std::cout << "\tCette ligne possede aucun service!" << std::endl;
	}
}
