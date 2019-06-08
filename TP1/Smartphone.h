#pragma once

#include <string>

class Smartphone
{
public:
	Smartphone(int num, std::string mar, std::string mod, std::string col);
	Smartphone();
	~Smartphone();
	int getNumSerie();
	std::string getMarque();
	std::string getModele();
	std::string getCouleur();
	void setNumSerie(int num);
	void setMarque(std::string mar);
	void setModele(std::string mod);
	void setCouleur(std::string col);
	void afficher();
private:
	int numSerie;
	std::string marque;
	std::string modele;
	std::string couleur;
};

