#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Abonne.h"
#include "Ligne.h"
#include "Service.h"

int afficherMenuPrincipal();

// Gestion des abonnes
void ajouterAbonne(std::list<Abonne> *listeAbonne);
void supprimerAbonne(std::list<Abonne> *listeAbonne, int numSerie);
void afficherAbonnes(std::list<Abonne> listeAbonne);

// Gestion des lignes
void ajouterLigne(std::list<Ligne> *listeLigne, Abonne a);
void supprimerLigne(std::list<Ligne> *listeLigne, int numero);
void afficherLignes(std::list<Ligne> listeLigne);

// Gestion des services
void associerService(Service service, Ligne ligne);
