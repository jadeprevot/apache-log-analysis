#include <sstream>
#include <iostream>
#include <getopt.h>
#include "Traitement.h"
#include "Lecture.h"
using namespace std;

string urlBase("http://intranet-if.insa-lyon.fr");

void Erreur(int code, const string& message) {
	switch (code) {
		case 1: {
			cerr << "Erreur. Usage: " << message << " [OPTION]... FICHIER" << endl;
			cerr << "OPTIONS:	-g FICHIER 	permet de produire un fichier au format GraphViz dans FICHIER" << endl;
			cerr << "		-e 		exclu les documents avec une extension .png, .jpg, .css ou .js" << endl;
			cerr << "		-t heure 	ne prend en compte que les hits qui sont dans le créneau horaire correspondant à l’intervalle [heure, heure+1[." << endl;
			break;
		}
		case 2: {
			cerr << "Erreur lors de l'ouverture du fichier \"" << message << "\"." << endl;
			cerr << "Veuillez réessayer svp." << endl;
			break;
		}
		case 3: {
			cerr << "Erreur. Veuillez renseigner un nom de fichier de log svp." << endl;
			break;
		}
		case 4: {
			cerr << "Erreur. Trop d'arguments." << endl;
			break;
		}
		case 5: {
			cerr << "Erreur lors de l'ouverture du fichier en écriture \"" << message << "\"." << endl;
			break;
		}
		case 6: {
			cerr << "Erreur, option invalide." << endl;
			break;
		}
		case 7: {
			cerr << "Erreur, heure non correcte." << endl;
			break;
		}
		default: {
			cerr << "Erreur, erreur non reconnue." << endl;
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	Traitement traitement;
	bool optionG = false;
	ofstream fichierDot;
	bool optionE = false;
	bool optionT = false;
	int heure;

	char c;
	while ((c = getopt(argc, argv, "g:et:u:")) != -1) {
		switch (c) {
			case 'g': {
				fichierDot.open(optarg, ios::out | ios::trunc);
				if (!fichierDot.is_open()) {
					Erreur(5, optarg);
					exit(5);
				}
				optionG = true;
				break;
			}
			case 'e': {
				optionE = true;
				break;
			}
			case 't': {
				stringstream ss(optarg);
				double tmp;
				ss >> tmp;
				heure = tmp;
				if (ss.fail() || (double) heure - tmp || heure > 23 || heure < 0) {
					Erreur(7, "");
					exit(7);
				}
				optionT = true;
				break;
			}
			case 'u': {
				urlBase = optarg;
				break;
			}
			default: {
				Erreur(6, "");
				exit(6);
			}
		}
	}

	if (optind == argc) {
		Erreur(3, "");
		exit(3);
	}

	Lecture fichier(argv[optind]);
	if (!fichier.is_open()) {
		Erreur(2, argv[optind]);
		exit(2);
	}

	if (++optind != argc) {
		Erreur(4, "");
		exit(4);
	}

	traitement.LireFichierLogs(fichier, optionE, optionT, heure);
	fichier.close();

	traitement.AfficherTop10();

	if (optionG) {
		traitement.CreerFichier(fichierDot);
		fichierDot.close();
	}

	exit(0);
}
