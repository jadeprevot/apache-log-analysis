% ANALOG(1) Version 1.0 | "Analog" Documentation

NAME
====

**analog** — Analyseur de logs Apache.

SYNOPSIS
========

	./analog [OPTIONS]... FILE

DESCRIPTION
===========

Analog est un analyseur de logs Apache. Il permet d'afficher les 10 cibles les plus atteintes. Il permet de filtrer les résultats selon l'extension de la cible ou selon l'heure de la requête. Il permet également de produire un fichier caratéristique de la communication décrite dans le fichier log Apache en langage DOT.

FILE :
	le fichier de log Apache.

Options
-------

* -e

	Ne prend pas en compte les fichiers de type images, css et javascript.

* -t heure

	Ne prend en compte que les cibles comprisent dans l'intervalle horaire \[t, t+1\[.

* -g file

	Permet de produire un fichier contenant une description du fichier log en DOT.

* -u addr

	Permet de renseigner l'adresse de base des différentes cibles. Par défaut celle-ci est *http://intranet-if.insa-lyon.fr*.

HowTo
-----

À partir du répertoire racine de l'application,

compiler :

	make

exécuter :

	./analog [OPTIONS]... FILE

lancer les tests :

	./test/mktest.sh

FILES
=====

* *analog*

	exécutable

* *src/*

	répertoire contenant les fichiers sources;

* *bin/*

	répertoire contenant les fichiers binaires;

* *test/*

	répertoire contenant différents jeux de test.

ENVIRONMENT
===========

ligne de commande

BUGS
====



AUTHORS
=======

* Jade Prevôt <jade.prevot@insa-lyon.fr>
* Salome Voltz <salome.voltz@insa-lyon.fr>
* Florie Villegas <florie.villegas@insa-lyon.fr>
* Brandon Alves <brandon.da-silva-alves@insa-lyon.fr>

SEE ALSO
========

