#pragma once
#include "Abonne.h"
#include <string>

class Ligne
{
public:
	Ligne(std::string num, Abonne ab);
	Ligne();
	~Ligne();
	// getters
	std::string getNumero();
	Abonne getAbonne();
	// extra
	virtual void afficher();
protected:
	std::string numero;
	Abonne abonne;
};

