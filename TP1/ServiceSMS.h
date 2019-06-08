#pragma once
#include "Service.h"
class ServiceSMS : public Service
{
public:
	ServiceSMS();
	~ServiceSMS();
	virtual void reset();
	virtual void afficher();
private:
	int smsEnvoyes;
	int smsRecu;
	int limiteEnvoi;
	// TODO class not completed
};

