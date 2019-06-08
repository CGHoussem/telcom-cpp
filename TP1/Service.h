#pragma once
#include <string>

class Service
{
public:
	Service(int num, std::string desc, float p);
	Service();
	~Service();
	// Getters
	int getNumero();
	std::string getDescription();
	float getPrix();
	// Setters
	void setNumero(int num);
	void setDescription(std::string desc);
	void setPrix(float p);
	// Extra
	virtual void reset();
	virtual void afficher();
protected:
	int numero;
	std::string description;
	float prix;
};

