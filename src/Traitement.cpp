/******************************************************************************
						   Traitement  -  description
							 -------------------
début	   : 20.11.2020
copyright   : (C) 2020 par  Salome Voltz, Florie Villegas,
							Jade Prévôt, Brandon da Silva Alves
e-mail	  : salome.voltz@insa-lyon.fr, florie.villegas@insa-lyon.fr,
			jade.prevot@insa-lyon.fr, brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//------ Réalisation de la classe <Traitement> (fichier Traitement.cpp) -------

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
#include <string>
#include <iostream>
#include <set>
//----------------------------------------------------------- Include personnel
#include "Traitement.h"
#include "Log.h"
#include "Extension.h"
//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques

void Traitement::LireFichierLogs(Lecture& fichier, bool optionE, bool optionT, int heure)
// Algorithme :
//	Aucun
{
	Log log;
	while (fichier >> log) {
		if (optionT && log.date.heure != heure) continue;
		Extension extension = log.getExtension();
		if (optionE && (extension == Extension::PNG ||
						extension == Extension::JPG ||
						extension == Extension::BMP ||
						extension == Extension::ICO ||
						extension == Extension::GIF ||
						extension == Extension::CSS ||
						extension == Extension::JS)) continue;
		data[log.requete.cible].first++;
		data[log.requete.cible].second[log.referer]++;
	}
}

void Traitement::AfficherTop10()
// Algorithme :
//	Aucun
{
	unordered_map<string, pair<int, unordered_map<string, int>>>::const_iterator it;
	for(it = data.begin(); it != data.end(); ++it) {
		top10.emplace(it->second.first, it->first);
	}
	multimap<int, string>::const_reverse_iterator rit;
	int i;
	for (rit = top10.rbegin(), i = 0; rit != top10.rend() && i < 10; ++rit, ++i) {
		cout << rit->second << "(" << rit->first << " hits)" << endl;
	}
}

void Traitement :: CreerFichier(ofstream& fichier) const
// Algorithme :
//	Aucun
{
	set<string>noeuds;
	unordered_map<string, pair<int, unordered_map<string, int>>>::const_iterator it;
	unordered_map<string, int> :: const_iterator it2;
	for(it = data.begin(); it != data.end(); ++it)
	{
		noeuds.insert(it->first);
		for(it2=it->second.second.begin();it2!=it->second.second.end();++it2)
		{
			noeuds.insert(it2->first);
		}

	}

	fichier << "digraph {" << endl;

	int i=0;
	set<string> :: const_iterator itset;

	map <string,int> graphe;

	for(itset = noeuds.begin(); itset!= noeuds.end(); ++itset)
	{
		fichier << "	" << "node" << i << " [label=\"" << *itset << "\"];" << endl;
		graphe[*itset] = i;
		i++;
	}

	for(it = data.begin(); it != data.end(); ++it)
	{
		for(it2=it->second.second.begin();it2!=it->second.second.end();++it2)
		{
			fichier << "	" << "node" << graphe[it2->first] << " -> node" << graphe[it->first] << " [label=\"" << it2->second << "\"];" <<endl;
		}

	}

	fichier << "}" << endl;
}

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
