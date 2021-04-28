/******************************************************************************
						   Log  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par  Salome Voltz, Florie Villegas,
							Jade Prévôt, Brandon da Silva Alves
e-mail	  : salome.voltz@insa-lyon.fr, florie.villegas@insa-lyon.fr,
			jade.prevot@insa-lyon.fr, brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//---------------- Interface de la classe <Log> (fichier Log.h) ---------------
#ifndef LOG_H
#define LOG_H
//-------------------------------------------------------- Interfaces utilisées
#include <string>
#include "Extension.h"
//------------------------------------------------------------------ Constantes
//----------------------------------------------------------------------- Types
//-----------------------------------------------------------------------------
// Rôle de la classe <Log>
//		Permet de recencer l'information d'une ligne d'un fichier log.
//-----------------------------------------------------------------------------
using namespace std;

class Log {
	public:
		Extension getExtension() const;
		// Mode d'emploi :
		//		Retourne l'extension de la cible de la requête.
		// Contrat :
		//		Aucun.
	private:
		string ip;
		string logname;
		string username;
		struct Date {
			int jour;
			string mois;
			int annee;
			int heure;
			int minute;
			int seconde;
			string fuseau;
		} date;
		struct Requete {
			string methode;
			string cible;
			string version;
		} requete;
		int returnCode;
		int qteDonnees;
		string referer;
		string navigateur;
	friend class Traitement;
	friend class Lecture;
};

//------------------------------------- Autres définitions dépendantes de <Log>
#endif // LOG_H