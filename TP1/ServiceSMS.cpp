#include "ServiceSMS.h"
#include <iostream>


ServiceSMS::ServiceSMS()
{
	description = "SMS";
	prix = 25.5f;
	smsEnvoyes = 0;
	smsRecu = 0;
}


ServiceSMS::~ServiceSMS()
{
}

void ServiceSMS::reset()
{
	smsEnvoyes = 0;
	smsRecu = 0;
}

void ServiceSMS::afficher()
{
	Service::afficher();
	std::cout << "\tSMS Envoyes: " << smsEnvoyes << std::endl;
	std::cout << "\tSMS Reçu: " << smsRecu << std::endl;
	std::cout << "\tLimite d'envoi: " << limiteEnvoi << std::endl;
}
