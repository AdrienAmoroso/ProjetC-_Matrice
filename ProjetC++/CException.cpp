/*****************************************************************//**
 * \file   CException.cpp
 * \brief  Corps de la classe CException.
 *		   Cette classe permet de cr�er des objets qui sont remont�s
 *		   lors de la lev�e d�exceptions dans le programme.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#include "CException.h"

// CORPS


/**************************************************************
Nom : CException
***************************************************************
Constructeur par d�faut de la classe CException qui permet
d�initialiser un objet.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : L�exception est initialis�e � PAS_ERREUR.
***************************************************************/
CException::CException()
{
	uiEXCValeur = PAS_ERREUR;
}


/**************************************************************
Nom : EXCAfficherErreur
***************************************************************
Cette fonction permet d'afficher un message d'erreur.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Un message d'erreur est affich�.
***************************************************************/
void CException::EXCAfficherErreur()
{
	switch (uiEXCValeur) {

	case 100:
		// PRODUIT_ILLICITE
		cerr << "Erreur : Les dimensions des 2 matrices ne correspondent pas : produit illicite." << endl;
		break;

	case 101:
		// DIMENSIONS_MATRICES_DIFFERENTES
		cerr << "Erreur : Les 2 matrices ne sont pas de meme dimension." << endl;
		break;

	case 102:
		// DIVISION_PAR_ZERO
		cerr << "Erreur : Division par zero." << endl;
		break;

	case 103:
		// TABLEAU_NULL
		cerr << "Erreur : Tableau mis � NULL." << endl;
		break;

	case 104:
		// INDEX_LIGNE_DEPASSE
		cerr << "Erreur : Le numero de ligne ne correspond pas aux dimensions de la matrice." << endl;
		break;

	case 105:
		// INDEX_COLONNE_DEPASSE
		cerr << "Erreur : Le numero de colonne ne correspond pas aux dimensions de la matrice." << endl;
		break;

	case 106:
		// INDEX_COLONNE_DEPASSE
		cerr << "Erreur : Le nom d'un des fichiers est mal renseigne." << endl;
		break;

	case 107:
		// FORMAT_INCORRECT
		cerr << "Erreur : Le format de la matrice est incorrect." << endl;
		break;
	
	default:
		// ERREUR INCONNUE
		cerr << "Erreur d'origine inconnue." << endl;
	}
}