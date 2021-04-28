/******************************************************************************
						   Traitement  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par  Salome Voltz, Florie Villegas,
							Jade Prévôt, Brandon da Silva Alves
e-mail	  : salome.voltz@insa-lyon.fr, florie.villegas@insa-lyon.fr,
			jade.prevot@insa-lyon.fr, brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//-------- Interface de la classe <Traitement> (fichier Traitement.h) ---------
#ifndef TRAITEMENT_H
#define TRAITEMENT_H
//-------------------------------------------------------- Interfaces utilisées
using namespace std;
#include <unordered_map>
#include <map>
#include <string>
#include "Lecture.h"
#include "Extension.h"
//------------------------------------------------------------------ Constantes
//----------------------------------------------------------------------- Types
//-----------------------------------------------------------------------------
// Rôle de la classe <Traitement>
//		Permet de d'effectuer les différentes opérations du programme analog.
//-----------------------------------------------------------------------------
using namespace std;

class Traitement {
	public:
		void LireFichierLogs(Lecture& fichier, bool optionE, bool optionT, int heure);
		// Mode d'emploi :
		//		Lit le fichier de log fichier. Si optionE est vrai alors ignore
		//		les log qui références des images ou des fichiers d'extensions
		//		css et js. Si optionT est vrai alors ignore les logs qui ne sont
		//		pas dans le créneau horaire [heure, heure+1[.
		// Contrat :
		//		Aucun.
		void AfficherTop10();
		// Mode d'emploi :
		//		Affiches les 10 lignes de log qui correspondents aux pages les
		//		plus visitées.
		// Contrat :
		//		Aucun.
		void CreerFichier(ofstream& fichier) const;
		// Mode d'emploi :
		//		Crée un le fichier fichier décrivant en langage DOT le graphe
		//		correspondant au fichier de log.
		// Contrat :
		//		Aucun.
	private:
		unordered_map<string, pair<int, unordered_map<string, int>>> data;
		// unordered_map<cible, pair<nb de consultation, unordered_map<referer, nombre de consultations de cible depuis referer>>> data;
		multimap<int, string> top10;
};

//------------------------------ Autres définitions dépendantes de <Traitement>

#endif // TRAITEMENT_H