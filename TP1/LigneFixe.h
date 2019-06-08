#pragma once
#include "Ligne.h"
#include <string>

class LigneFixe : public Ligne
{
public:
	LigneFixe(std::string num, Abonne ab, std::string locGeo);
	LigneFixe();
	~LigneFixe();
	virtual void afficher();
private:
	std::string locationGeo;
};
