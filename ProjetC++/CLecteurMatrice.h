/*****************************************************************//**
 * \file   CLecteurMatrice.h
 * \brief  Interface de la classe CLecteurMatrice.
 *		   Cette classe permet de créer des matrices de type quelconque
		   à partir d'un fichier texte.	
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#ifndef C_LECTEUR_MATRICE_H
#define C_LECTEUR_MATRICE_H 16


#include "CUtilitaireMatrice.h"


class CLecteurMatrice
{

	/******** Méthodes *********/


public:
	
	CMatrice<double> LECCreerMatDepuisFichier(const char* sFichier);
	/* Cette fonction permet de créer une matrice à partir d'un fichier.
	E : Nom du fichier
	Nécessite : néant
	S : Un objet de la classe CMatrice
	Entraîne : Une matrice extraite du fichier est retournée.
	*/
};
#endif