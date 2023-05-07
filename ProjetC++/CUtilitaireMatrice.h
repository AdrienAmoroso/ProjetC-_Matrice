/*****************************************************************//**
 * \file   CUtilitaireMatrice.h
 * \brief  Interface de la classe CUtilitaireMatrice.
 *		   Cette classe permet de faire des opérations sur des objets 
 *		   de la classe CMatrice.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#ifndef C_UTILITAIRE_MATRICE_H
#define C_UTILITAIRE_MATRICE_H 12

#include "CMatrice.h"

#define PRODUIT_ILLICITE 100
#define DIMENSIONS_MATRICES_DIFFERENTES 101


template<typename MType>
class CUtilitaireMatrice
{

	/******** Méthodes *********/

public:

	CMatrice<MType> UTIProduitMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2);
	/* Cette fonction permet de retourner le produit de deux matrices.
	E : Deux matrices de type quelconque
	Nécessite : Le nombre de lignes de la première matrice doit être égal
				au nombre de colonnes de la seconde matrice.
	S : La matrice correspondant au produit des deux matrices passées en paramètres
	Entraîne : Le produit des deux matrices est retourné.
    */

	CMatrice<MType> UTITransposee(CMatrice<MType>& mtMATParam);
	/* Cette fonction permet de retourner la transposée d'une matrice.
	E : Une matrice de type quelconque
	Nécessite : néant
	S : La matrice correspondant à la transposée de la matrice passée en paramètre
	Entraîne : Le transposée de la matrice est retournée.
	*/

	CMatrice<MType> UTISommeMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2);
	/* Cette fonction permet de retourner le somme de deux matrices.
	E : Deux matrices de type quelconque
	Nécessite : Les matrices doivent être de mêmes dimensions.
	S : La matrice correspondant à la somme des deux matrices passées en paramètres
	Entraîne : La somme des deux matrices est retournée.
	*/

	CMatrice<MType> UTISoustractionMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2);
	/* Cette fonction permet de retourner la soustraction de deux matrices.
	E : Deux matrices de type quelconque
	Nécessite : Les matrices doivent être de même dimension.
	S : La matrice correspondant à la soustraction des deux matrices passées en paramètres
	Entraîne : La soustraction des deux matrices est retournée.
	*/
};
#include "CUtilitaireMatrice.ipp"

#endif