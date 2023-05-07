/*****************************************************************//**
 * \file   CLecteurMatrice.h
 * \brief  Interface de la classe CLecteurMatrice.
 *		   Cette classe permet de cr�er des matrices de type quelconque
		   � partir d'un fichier texte.	
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#ifndef C_LECTEUR_MATRICE_H
#define C_LECTEUR_MATRICE_H 16


#include "CUtilitaireMatrice.h"


class CLecteurMatrice
{

	/******** M�thodes *********/


public:
	
	CMatrice<double> LECCreerMatDepuisFichier(const char* sFichier);
	/* Cette fonction permet de cr�er une matrice � partir d'un fichier.
	E : Nom du fichier
	N�cessite : n�ant
	S : Un objet de la classe CMatrice
	Entra�ne : Une matrice extraite du fichier est retourn�e.
	*/
};
#endif