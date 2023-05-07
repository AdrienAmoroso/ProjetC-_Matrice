/*****************************************************************//**
 * \file   CException.h
 * \brief  Interface de la classe CException.
 *		   Cette classe permet de créer des objets qui sont remontés
 *		   lors de la levée d’exceptions dans le programme.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#ifndef EXCEP_H
#define EXCEP_H 11

#include <iostream>
using namespace std;

// Définition de la valeur initiale d’une exception
#define PAS_ERREUR 0
#define ENTRER_VALEUR 106


class CException
{
	/******** Attributs *********/

private:
	unsigned int uiEXCValeur; // Variable contenant la valeur de l'exception

public:

	/******** Constructeurs - Destructeur *********/

	CException();
	/* Constructeur par défaut de la classe CException qui permet d'initialiser un objet.
		E : néant
		Nécessite : néant
		S : néant
		Entraîne : L'exception est initialisée à PAS_ERREUR.
	*/
	~CException() {}
	/* Destructeur de la classe CException.
		E : néant
		Nécessite : néant
		S : néant
		Entraîne : L'exception est détruite.
	*/


	/******** Méthodes *********/


	const unsigned int EXCLireValeur();
	/* Cette fonction permet de consulter la valeur de l’exception.
		E : néant
		Nécessite : néant
		S : Valeur de l'exception
		Entraîne : La valeur de l'exception est retournée.
	*/
	void EXCModifierValeur(unsigned int uiNvValeur);
	/* Cette fonction permet de modifier la valeur de l’exception.
		E : Nouvelle valeur
		Nécessite : néant
		S : néant
		Entraîne : La valeur de l'exception est modifiée.
	*/
	void EXCAfficherErreur();
	/* Cette fonction permet d'afficher un message d'erreur.
		E : néant
		Nécessite : néant
		S : néant
		Entraîne : Un message d'erreur est affiché.
	*/
};
#include "CException.ipp"

#endif