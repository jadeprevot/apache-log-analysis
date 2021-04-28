/******************************************************************************
						   Log  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par  Salome Voltz, Florie Villegas,
							Jade Prévôt, Brandon da Silva Alves
e-mail	  : salome.voltz@insa-lyon.fr, florie.villegas@insa-lyon.fr,
			jade.prevot@insa-lyon.fr, brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//------------- Réalisation de la classe <Log> (fichier Log.cpp) --------------

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
#include <string>
//----------------------------------------------------------- Include personnel
#include "Log.h"
#include "Extension.h"
//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques

Extension Log::getExtension() const
// Algorithme :
//	Aucun
{
	long unsigned int pos = requete.cible.find_last_of(".");
	if (pos == string::npos) {
		return Extension::OTHER;
	}

	string tmp = requete.cible.substr(pos, requete.cible.length() - pos);

	if (tmp == ".html") {
		return Extension::HTML;
	}
	else if (tmp == ".png") {
		return Extension::PNG;
	}
	else if (tmp == ".jpg" || tmp == ".jpeg") {
		return Extension::JPG;
	}
	else if (tmp == ".bmp") {
		return Extension::BMP;
	}
	else if (tmp == ".gif") {
		return Extension::GIF;
	}
	else if (tmp == ".ico") {
		return Extension::ICO;
	}
	else if (tmp == ".css") {
		return Extension::CSS;
	}
	else if (tmp == ".js") {
		return Extension::JS;
	}
	else {
		return Extension::OTHER;
	}
}

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
