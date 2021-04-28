/******************************************************************************
						   Lecture  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par  Salome Voltz, Florie Villegas,
							Jade Prévôt, Brandon da Silva Alves
e-mail	  : salome.voltz@insa-lyon.fr, florie.villegas@insa-lyon.fr,
			jade.prevot@insa-lyon.fr, brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//----------- Interface de la classe <Lecture> (fichier Lecture.h) ------------
#ifndef LECTURE_H
#define LECTURE_H
//-------------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
#include "Log.h"
//------------------------------------------------------------------ Constantes
//----------------------------------------------------------------------- Types
//-----------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//		Permet de gérer la lecture d'une ligne de log.
// 		Spécialisation de ifstream.
//-----------------------------------------------------------------------------
using namespace std;

class Lecture : public ifstream {
	public:
		Lecture(const string& nomFichier);
		// Mode d'emploi :
		//		Créer un objet Lecture à partir du fichier nomFichier.
		// Contrat :
		//		Aucun.
		Lecture& operator>>(Log& log);
		// Mode d'emploi :
		//		Lit une ligne de log dans log. Retourne l'objet courant.
		// Contrat :
		//		Aucun.
};

//--------------------------------- Autres définitions dépendantes de <Lecture>

#endif // LECTURE_H