/*****************************************************************//**
 * \file   CUtilitaireMatrice.ipp
 * \brief  Corps de la classe CUtilitaireMatrice.
 *		   Cette classe permet de faire des opérations sur des objets
 *		   de la classe CMatrice.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

 /*CLASSE CException
	 DOCUMENTATION
		 Attributs : uiEXCValeur : entier naturel, contient la valeur de l’exception.
		 Structure : Cette classe contient une méthode de modification de la valeur
					 de l'exception, une méthode de consultation de celle-ci et
					 une méthode d'affichage des messages d'erreurs.
		 Méthode : néant
		 Modules internes:*/


// CORPS


/**************************************************************
Nom : UTIProduitMatrice
***************************************************************
Cette fonction permet de retourner le produit de deux matrices.
***************************************************************
Entrée : Deux matrices de type quelconque
Nécessite : Le nombre de lignes de la première matrice doit être 
			égal au nombre de colonnes de la seconde matrice.
Sortie : La matrice correspondant au produit des deux matrices 
		 passées en paramètres
Entraîne : Le produit des deux matrices est retourné.
***************************************************************/
template<typename MType>
CMatrice<MType> CUtilitaireMatrice<MType>::UTIProduitMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2)
{
	// Vérification que le nombre de colonnes de la première matrice est égal au nombre de lignes de la deuxième matrice
	if (mtMATParam1.MATGetNbCol() != mtMATParam2.MATGetNbLignes()) {
		CException EXCProduitIllicite;
		EXCProduitIllicite.EXCModifierValeur(PRODUIT_ILLICITE);
		throw(EXCProduitIllicite);
	}

	// Création d'une matrice résultat avec le nombre de lignes de la première matrice et le nombre de colonnes de la deuxième matrice
	CMatrice<MType> mtMATResultat(mtMATParam1.MATGetNbLignes(), mtMATParam2.MATGetNbCol());

	// Multiplication des matrices selon la règle des matrices
	for (unsigned int i = 0; i < mtMATParam1.MATGetNbLignes(); i++) {
		for (unsigned int j = 0; j < mtMATParam2.MATGetNbCol(); j++) {
			MType mtResultatElement = 0;
			for (unsigned int k = 0; k < mtMATParam1.MATGetNbCol(); k++) {
				mtResultatElement += mtMATParam1.MATLireElement(i, k) * mtMATParam2.MATLireElement(k, j);
			}
			mtMATResultat.MATModifierElement(i, j, mtResultatElement);
		}
	}

	// Renvoi de la matrice résultat
	return mtMATResultat;
}


/**************************************************************
Nom : UTITransposee
***************************************************************
Cette fonction permet de retourner la transposée d'une matrice.
***************************************************************
Entrée : Une matrice de type quelconque
Nécessite : néant
Sortie : La matrice correspondant à la transposée de la matrice
		 passée en paramètre
Entraîne : La transposée de la matrice est retournée.
***************************************************************/
template<typename MType>
CMatrice<MType> CUtilitaireMatrice<MType>::UTITransposee(CMatrice<MType>& mtMATParam)
{
	CMatrice<MType> mtMATResultat(mtMATParam.MATGetNbCol(), mtMATParam.MATGetNbLignes());

	for (unsigned int i = 0; i < mtMATParam.MATGetNbLignes(); ++i)
	{
		for (unsigned int j = 0; j < mtMATParam.MATGetNbCol(); ++j)
		{
			MType mtResultatElement = mtMATParam.MATLireElement(i, j);
			mtMATResultat.MATModifierElement(j, i, mtResultatElement);
		}
	}

	return mtMATResultat;
}


/**************************************************************
Nom : UTISommeMatrice
***************************************************************
Cette fonction permet de retourner la somme de deux matrices.
***************************************************************
Entrée : Deux matrices de type quelconque
Nécessite : Les deux matrices doivent être de mêmes dimensions.
Sortie : La matrice correspondant à la somme des deux matrices
		 passées en paramètres
Entraîne : La somme des deux matrices est retournée.
***************************************************************/
template<typename MType>
CMatrice<MType> CUtilitaireMatrice<MType>::UTISommeMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2)
{
	// Vérification que les deux matrices ont les mêmes dimensions
	if (mtMATParam1.MATGetNbLignes() != mtMATParam2.MATGetNbLignes() || mtMATParam1.MATGetNbCol() != mtMATParam2.MATGetNbCol()) {
		CException EXCDimDifferentes;
		EXCDimDifferentes.EXCModifierValeur(DIMENSIONS_MATRICES_DIFFERENTES);
		throw(EXCDimDifferentes);
	}

	// Création d'une matrice résultat avec les mêmes dimensions que les deux matrices d'entrée
	CMatrice<MType> mtMATResultat(mtMATParam1.MATGetNbLignes(), mtMATParam1.MATGetNbCol());

	// Addition des deux matrices élément par élément
	for (unsigned int i = 0; i < mtMATParam1.MATGetNbLignes(); i++) {
		for (unsigned int j = 0; j < mtMATParam1.MATGetNbCol(); j++) {
			mtMATResultat.MATModifierElement(i, j, mtMATParam1.MATLireElement(i, j) + mtMATParam2.MATLireElement(i, j));
		}
	}

	// Renvoi de la matrice résultat
	return mtMATResultat;
}


/**************************************************************
Nom : UTISoustractionMatrice
***************************************************************
Cette fonction permet de retourner la soustraction de deux matrices.
***************************************************************
Entrée : Deux matrices de type quelconque
Nécessite : Les deux matrices doivent être de mêmes dimensions.
Sortie : La matrice correspondant à la soustraction des deux
		 matrices passées en paramètres
Entraîne : La soustraction des deux matrices est retournée.
***************************************************************/
template<typename MType>
CMatrice<MType> CUtilitaireMatrice<MType>::UTISoustractionMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2)
{
	// Vérification que les deux matrices ont les mêmes dimensions
	if (mtMATParam1.MATGetNbLignes() != mtMATParam2.MATGetNbLignes() || mtMATParam1.MATGetNbCol() != mtMATParam2.MATGetNbCol()) {
		CException EXCDimDifferentes;
		EXCDimDifferentes.EXCModifierValeur(DIMENSIONS_MATRICES_DIFFERENTES);
		throw(EXCDimDifferentes);
	}

	// Création d'une matrice résultat avec les mêmes dimensions que les matrices d'entrée
	CMatrice<MType> mtMATResultat(mtMATParam1.MATGetNbLignes(), mtMATParam1.MATGetNbCol());

	// Soustraction des deux matrices élément par élément
	for (unsigned int i = 0; i < mtMATParam1.MATGetNbLignes(); i++) {
		for (unsigned int j = 0; j < mtMATParam1.MATGetNbCol(); j++) {
			mtMATResultat.MATModifierElement(i, j, mtMATParam1.MATLireElement(i, j) - mtMATParam2.MATLireElement(i, j));
		}
	}

	// Renvoi de la matrice résultat
	return mtMATResultat;
}