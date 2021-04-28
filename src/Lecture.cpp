/******************************************************************************
						   Lecture  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par  Salome Voltz, Florie Villegas,
							Jade Prévôt, Brandon da Silva Alves
e-mail	  : salome.voltz@insa-lyon.fr, florie.villegas@insa-lyon.fr,
			jade.prevot@insa-lyon.fr, brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//--------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ----------

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include <fstream>
#include <iostream>
#include <sstream>
//----------------------------------------------------------- Include personnel
#include "Lecture.h"
#include "Log.h"
//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques

//------------------------------------------------------ Surcharge d'opérateurs

Lecture& Lecture::operator>>(Log& log)
// Algorithme :
//	Aucun
{
	extern string urlBase;

	char c;
	string tmp;
	stringstream ss;
	long unsigned int pos;

	std::getline(*this, log.ip, ' ');
	std::getline(*this, log.logname, ' ');
	std::getline(*this, log.username, ' ');

	this->get(c);

	std::getline(*this, tmp, '/');
	ss = stringstream(tmp);
	ss >> log.date.jour;
	std::getline(*this, log.date.mois, '/');
	std::getline(*this, tmp, ':');
	ss = stringstream(tmp);
	ss >> log.date.annee;
	std::getline(*this, tmp, ':');
	ss = stringstream(tmp);
	ss >> log.date.heure;
	std::getline(*this, tmp, ':');
	ss = stringstream(tmp);
	ss >> log.date.minute;
	std::getline(*this, tmp, ' ');
	ss = stringstream(tmp);
	ss >> log.date.seconde;
	std::getline(*this, log.date.fuseau, ']');

	this->get(c);
	this->get(c);

	std::getline(*this, log.requete.methode, ' ');
	std::getline(*this, log.requete.cible, ' ');
	std::getline(*this, log.requete.version, '"');

	this->get(c);

	std::getline(*this, tmp, ' ');
	ss = stringstream(tmp);
	ss >> log.returnCode;
	if (ss.fail()) {
		log.returnCode = -1;
	}

	std::getline(*this, tmp, ' ');
	ss = stringstream(tmp);
	ss >> log.qteDonnees;
	if (ss.fail()) {
		log.qteDonnees = -1;
	}

	this->get(c);

	std::getline(*this, tmp, '"');
	pos = tmp.find(urlBase);
	if (pos == string::npos) {
		log.referer = tmp;
	}
	else {
		log.referer = tmp.substr(urlBase.length(), tmp.length() - urlBase.length());
	}

	this->get(c);

	std::getline(*this, log.navigateur);

	return *this;
}

//------------------------------------------------- Constructeurs - destructeur

Lecture::Lecture(const string& nomFichier) : ifstream(nomFichier)
// Algorithme :
//	Aucun
{

}

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
