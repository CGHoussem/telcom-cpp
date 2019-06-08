#pragma once

#include <string>

class Abonne
{
public:
	Abonne(int num, std::string n, std::string adr);
	Abonne();
	~Abonne();
	// Getters
	int getNumSerie();
	std::string getNom();
	std::string getAdresse();
	// Setters
	void setNumSerie(int num);
	void setNom(std::string n);
	void setAdresse(std::string adr);
	// Extra
	void afficher();
private:
	int numSerie;
	std::string nom;
	std::string adresse;
};

