#include "ServiceVoix.h"
#include <iostream>


ServiceVoix::ServiceVoix()
{
	description = "Voix";
	prix = 0.3f;
}


ServiceVoix::~ServiceVoix()
{
}

int ServiceVoix::getLimiteTemps()
{
	return limiteTemps;
}

void ServiceVoix::setLimiteTemps(int lt)
{
	limiteTemps = lt;
}

void ServiceVoix::reset()
{
}

void ServiceVoix::afficher()
{
	Service::afficher();
	std::cout << "Limite temps: " << limiteTemps << " minutes" << std::endl;
}
