#pragma once
#include "Service.h"
class ServiceDATA :
	public Service
{
public:
	ServiceDATA(int envIni);
	ServiceDATA();
	~ServiceDATA();
	virtual void reset();
	virtual void afficher();
private:
	int enveloppeInitiale;
	float pourcentage = 0.6f;
	int charge = 0;
	int dataConsommee = 0; // Exprimer en mb
};

