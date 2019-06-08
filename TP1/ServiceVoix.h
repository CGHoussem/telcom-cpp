#pragma once
#include "Service.h"

class ServiceVoix : public Service
{
public:
	ServiceVoix();
	~ServiceVoix();
	// Getters
	int getLimiteTemps();
	// Setters
	void setLimiteTemps(int lt);
	// Extra
	virtual void reset();
	virtual void afficher();
private:
	int limiteTemps = 120; // exprimer en minutes
};

