/*****************************************************************//**
 * \file   CMatrice.h
 * \brief  Interface de la classe CMatrice.
 *		   Cette classe permet de créer des matrices de type quelconque
 *		   et de les manipuler.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#ifndef C_MATRICE_H
#define C_MATRICE_H 10

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "CException.h"

#define DIVISION_PAR_ZERO 102
#define TABLEAU_NULL 103
#define INDEX_LIGNE_DEPASSE 104
#define INDEX_COLONNE_DEPASSE 105
#define FORMAT_INCORRECT 107

using namespace std;



template <class MType>
class CMatrice
{
	/******** Attributs *********/

private:
	unsigned int uiMATNbLignes;

	unsigned int uiMATNbCol;

	MType **ppmtMATTableau;

public:

	/******** Constructeurs - Destructeur *********/

	CMatrice<MType>();
	/* Constructeur par défaut de la classe.
		E : néant
		Nécessite : néant
		S : néant
		Entraîne : La matrice est initialisée.
	*/
	CMatrice<MType>(unsigned int uiNumCol, unsigned int uiNumLigne);
	/* Constructeur de confort de la classe qui créé une matrice à partir de dimensions données.
		E : Matrice de type quelconque
		Nécessite : néant
		S : néant
		Entraîne : La matrice est initialisée à partir de dimensions données.
	*/
	
	CMatrice<MType>(const CMatrice<MType>& mtMATParam);
	/* Constructeur de recopie de la classe.
		E : Objet CMatrice
		Nécessite : néant
		S : néant
		Entraîne : La matrice est initialisée à partir d'une matrice d'un objet CMatrice donné.
	*/

	~CMatrice<MType>();
	/* Destructeur de la classe CMatrice.
		E : néant
		Nécessite : néant
		S : néant
		Entraîne : La matrice est détruite.
	*/


	/********  Méthodes *********/


	// Accesseurs en lecture

	const unsigned int MATGetNbLignes();
	/* Cette fonction permet de consulter le nombre de lignes.
		E : néant
		Nécessite : néant
		S : Nombre de lignes
		Entraîne : La valeur du nombre de lignes est retournée.
	*/

	const unsigned int MATGetNbCol();
	/* Cette fonction permet de consulter le nombre de colonnes.
		E : néant
		Nécessite : néant
		S : Nombre de colonnes
		Entraîne : La valeur du nombre de colonnes est retournée.
	*/

	void MATAfficherMatrice();
	/* Cette fonction permet d'afficher les éléments de la matrice.
		E : néant
		Nécessite : néant
		S : néant
		Entraîne : La matrice s'affiche à l'écran.
	*/

	const MType MATLireElement(unsigned int uiNumLigne, unsigned int uiNumCol);
	/* Cette fonction permet de consulter un élément de la matrice à une position donnée.
		E : Numéro de ligne et numéro de colonne
		Nécessite : néant
		S : L'élément à cette position
		Entraîne : L'élément à la position donnée est retourné.
	*/

	// Accesseur en écriture

	void MATModifierElement(unsigned int uiMATNumLigne, unsigned int uiMATNumCol, MType mtNvElement);
	/* Cette fonction permet de modifier un élément à la position donnée.
		E : Numéro de ligne, numéro de colonne ainsi que le nouvel élément
		Nécessite : néant
		S : néant
		Entraîne : L'élément à la position donnée est modifié.
	*/
	

	// Surcharge des Opérateurs


	/**************************************************************
	Nom : operator*
	***************************************************************
	Surcharge de l'opérateur * qui permet de multiplier une matrice
	à une constante.
	***************************************************************
	Entrée : Constante
	Nécessite : néant
	Sortie : CMatrice multipliée par la constante.
	Entraîne : La matrice est multipliée par la constante.
	***************************************************************/
	CMatrice<MType> operator*(const MType& mtValeur)
	{
		CMatrice<MType> mtMATResultat(uiMATNbCol, uiMATNbLignes);

		for (unsigned int i = 0; i < uiMATNbLignes; i++)
		{
			for (unsigned int j = 0; j < uiMATNbCol; j++)
			{
				mtMATResultat.ppmtMATTableau[i][j] = ppmtMATTableau[i][j] * mtValeur;
			}
		}

		return mtMATResultat;
	}

	/**************************************************************
	Nom : operator/
	***************************************************************
	Surcharge de l'opérateur / qui permet de diviser une matrice par
	une constante.
	***************************************************************
	Entrée : Constante
	Nécessite : néant
	Sortie : CMatrice divisée par la constante.
	Entraîne : La matrice est divisée par la constante.
	***************************************************************/
	CMatrice operator/(const MType& mtValeur)
	{
		if (mtValeur == 0)
		{
			CException ValeurNulle;
			ValeurNulle.EXCModifierValeur(DIVISION_PAR_ZERO);
			throw(ValeurNulle);
		}
		
		CMatrice<MType> mtMATResultat(uiMATNbCol, uiMATNbLignes);

		for (unsigned int i = 0; i < uiMATNbLignes; i++)
		{
			for (unsigned int j = 0; j < uiMATNbCol; j++)
			{
				mtMATResultat.ppmtMATTableau[i][j] = ppmtMATTableau[i][j] / mtValeur;
			}
		}

		return mtMATResultat;
	}

	/**************************************************************
	Nom : operator<<
	***************************************************************
	Surcharge de l'opérateur << qui permet d'afficher le contenu 
	d'un objet CMatrice avec la fonction cout dans notre cas (et
	généralement avec un objet de la classe ostream).
	***************************************************************
	Entrée : Objet CMatrice
	Nécessite : néant
	Sortie : CMatrice
	Entraîne : La matrice est affichée à l'écran avec cout.
	***************************************************************/
	friend ostream& operator<<(ostream& os, const CMatrice<MType>& mtMATParam)
	{
		for (unsigned int i = 0; i < mtMATParam.uiMATNbLignes; i++)
		{
			for (unsigned int j = 0; j < mtMATParam.uiMATNbCol; j++)
			{
				os << mtMATParam.ppmtMATTableau[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	/**************************************************************
	Nom : operator=
	***************************************************************
	Surcharge de l'opérateur = qui permet d'affecter le contenu d'un
	objet CMatrice dans un autre.
	***************************************************************
	Entrée : Objet CMatrice
	Nécessite : néant
	Sortie : néant
	Entraîne : La matrice est affectée à l'objet passé en paramètre.
	***************************************************************/
	CMatrice<MType>& operator=(const CMatrice<MType>& mtMATParam)
	{
		if (this != &mtMATParam) {
			// Copie des valeurs de l'autre matrice dans la matrice actuelle
			for (unsigned int i = 0; i < uiMATNbLignes; i++) {
				for (unsigned int j = 0; j < uiMATNbCol; j++) {
					ppmtMATTableau[i][j] = mtMATParam.ppmtMATTableau[i][j];
				}
			}
		}

		uiMATNbLignes = mtMATParam.uiMATNbLignes;
		uiMATNbCol = mtMATParam.uiMATNbCol;

		return *this;
	}
};

#include "CMatrice.ipp"
#endif