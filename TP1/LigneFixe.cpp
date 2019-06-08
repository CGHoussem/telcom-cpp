#include "LigneFixe.h"
#include <iostream>


LigneFixe::LigneFixe(std::string num, Abonne ab, std::string locGeo)
{
	numero = num;
	abonne = ab;
	locationGeo = locGeo;
}

LigneFixe::LigneFixe()
{
}


LigneFixe::~LigneFixe()
{
}

void LigneFixe::afficher()
{
	Ligne::afficher();
	std::cout << "\tLocation Geo: " << locationGeo << std::endl;
}
