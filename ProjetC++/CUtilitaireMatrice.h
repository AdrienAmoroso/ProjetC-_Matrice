/*****************************************************************//**
 * \file   CUtilitaireMatrice.h
 * \brief  Interface de la classe CUtilitaireMatrice.
 *		   Cette classe permet de faire des op�rations sur des objets 
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

	/******** M�thodes *********/

public:

	CMatrice<MType> UTIProduitMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2);
	/* Cette fonction permet de retourner le produit de deux matrices.
	E : Deux matrices de type quelconque
	N�cessite : Le nombre de lignes de la premi�re matrice doit �tre �gal
				au nombre de colonnes de la seconde matrice.
	S : La matrice correspondant au produit des deux matrices pass�es en param�tres
	Entra�ne : Le produit des deux matrices est retourn�.
    */

	CMatrice<MType> UTITransposee(CMatrice<MType>& mtMATParam);
	/* Cette fonction permet de retourner la transpos�e d'une matrice.
	E : Une matrice de type quelconque
	N�cessite : n�ant
	S : La matrice correspondant � la transpos�e de la matrice pass�e en param�tre
	Entra�ne : Le transpos�e de la matrice est retourn�e.
	*/

	CMatrice<MType> UTISommeMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2);
	/* Cette fonction permet de retourner le somme de deux matrices.
	E : Deux matrices de type quelconque
	N�cessite : Les matrices doivent �tre de m�mes dimensions.
	S : La matrice correspondant � la somme des deux matrices pass�es en param�tres
	Entra�ne : La somme des deux matrices est retourn�e.
	*/

	CMatrice<MType> UTISoustractionMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2);
	/* Cette fonction permet de retourner la soustraction de deux matrices.
	E : Deux matrices de type quelconque
	N�cessite : Les matrices doivent �tre de m�me dimension.
	S : La matrice correspondant � la soustraction des deux matrices pass�es en param�tres
	Entra�ne : La soustraction des deux matrices est retourn�e.
	*/
};
#include "CUtilitaireMatrice.ipp"

#endif