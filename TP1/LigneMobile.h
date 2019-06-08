#pragma once
#include <vector>
#include <string>
#include "Ligne.h"
#include "Service.h"

class LigneMobile : public Ligne
{
public:
	LigneMobile(std::string num, Abonne ab);
	LigneMobile();
	~LigneMobile();
	// Getters
	
	std::vector<Service> getServices();
	// Extra
	void ajouterService(Service s);
	void retirerService(int numService);
	virtual void afficher();

private:
	std::vector<Service> services;
};

