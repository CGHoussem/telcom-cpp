#include "Service.h"
#include <iostream>


Service::Service(int num, std::string desc, float p)
	: numero(num), description(desc), prix(p)
{
}

Service::Service()
{
	numero = (rand() % RAND_MAX) & RAND_MAX;
	description = "";
	prix = 0;
}


Service::~Service()
{
}

int Service::getNumero()
{
	return numero;
}

std::string Service::getDescription()
{
	return description;
}

float Service::getPrix()
{
	return prix;
}

void Service::setNumero(int num)
{
	numero = num;
}

void Service::setDescription(std::string desc)
{
	description = desc;
}

void Service::setPrix(float p)
{
	prix = p;
}

void Service::reset()
{
}

void Service::afficher()
{
	std::cout << "Service " << numero << "(" << description  << ") | " << prix << "€" << std::endl;
}
