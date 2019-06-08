#include "ServiceDATA.h"
#include <iostream>


ServiceDATA::ServiceDATA(int envIni)
{
	description = "DATA";
	prix = 45.5;
	
	enveloppeInitiale = envIni;
}

ServiceDATA::ServiceDATA()
{
	prix = 45.5;
	description = "DATA";
}


ServiceDATA::~ServiceDATA()
{
}

void ServiceDATA::reset()
{
	dataConsommee = 0;
}

void ServiceDATA::afficher()
{
	Service::afficher();
	std::cout << "\tEnveloppe Initialie: " << enveloppeInitiale << std::endl;
	std::cout << "\tCharge: " << charge << std::endl;
	std::cout << "\tDATA Consommee: " << dataConsommee << " mb" << std::endl;
}
