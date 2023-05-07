/*****************************************************************//**
 * \file   CUtilitaireMatrice.ipp
 * \brief  Corps de la classe CUtilitaireMatrice.
 *		   Cette classe permet de faire des op�rations sur des objets
 *		   de la classe CMatrice.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

 /*CLASSE CException
	 DOCUMENTATION
		 Attributs : uiEXCValeur : entier naturel, contient la valeur de l�exception.
		 Structure : Cette classe contient une m�thode de modification de la valeur
					 de l'exception, une m�thode de consultation de celle-ci et
					 une m�thode d'affichage des messages d'erreurs.
		 M�thode : n�ant
		 Modules internes:*/


// CORPS


/**************************************************************
Nom : UTIProduitMatrice
***************************************************************
Cette fonction permet de retourner le produit de deux matrices.
***************************************************************
Entr�e : Deux matrices de type quelconque
N�cessite : Le nombre de lignes de la premi�re matrice doit �tre 
			�gal au nombre de colonnes de la seconde matrice.
Sortie : La matrice correspondant au produit des deux matrices 
		 pass�es en param�tres
Entra�ne : Le produit des deux matrices est retourn�.
***************************************************************/
template<typename MType>
CMatrice<MType> CUtilitaireMatrice<MType>::UTIProduitMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2)
{
	// V�rification que le nombre de colonnes de la premi�re matrice est �gal au nombre de lignes de la deuxi�me matrice
	if (mtMATParam1.MATGetNbCol() != mtMATParam2.MATGetNbLignes()) {
		CException EXCProduitIllicite;
		EXCProduitIllicite.EXCModifierValeur(PRODUIT_ILLICITE);
		throw(EXCProduitIllicite);
	}

	// Cr�ation d'une matrice r�sultat avec le nombre de lignes de la premi�re matrice et le nombre de colonnes de la deuxi�me matrice
	CMatrice<MType> mtMATResultat(mtMATParam1.MATGetNbLignes(), mtMATParam2.MATGetNbCol());

	// Multiplication des matrices selon la r�gle des matrices
	for (unsigned int i = 0; i < mtMATParam1.MATGetNbLignes(); i++) {
		for (unsigned int j = 0; j < mtMATParam2.MATGetNbCol(); j++) {
			MType mtResultatElement = 0;
			for (unsigned int k = 0; k < mtMATParam1.MATGetNbCol(); k++) {
				mtResultatElement += mtMATParam1.MATLireElement(i, k) * mtMATParam2.MATLireElement(k, j);
			}
			mtMATResultat.MATModifierElement(i, j, mtResultatElement);
		}
	}

	// Renvoi de la matrice r�sultat
	return mtMATResultat;
}


/**************************************************************
Nom : UTITransposee
***************************************************************
Cette fonction permet de retourner la transpos�e d'une matrice.
***************************************************************
Entr�e : Une matrice de type quelconque
N�cessite : n�ant
Sortie : La matrice correspondant � la transpos�e de la matrice
		 pass�e en param�tre
Entra�ne : La transpos�e de la matrice est retourn�e.
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
Entr�e : Deux matrices de type quelconque
N�cessite : Les deux matrices doivent �tre de m�mes dimensions.
Sortie : La matrice correspondant � la somme des deux matrices
		 pass�es en param�tres
Entra�ne : La somme des deux matrices est retourn�e.
***************************************************************/
template<typename MType>
CMatrice<MType> CUtilitaireMatrice<MType>::UTISommeMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2)
{
	// V�rification que les deux matrices ont les m�mes dimensions
	if (mtMATParam1.MATGetNbLignes() != mtMATParam2.MATGetNbLignes() || mtMATParam1.MATGetNbCol() != mtMATParam2.MATGetNbCol()) {
		CException EXCDimDifferentes;
		EXCDimDifferentes.EXCModifierValeur(DIMENSIONS_MATRICES_DIFFERENTES);
		throw(EXCDimDifferentes);
	}

	// Cr�ation d'une matrice r�sultat avec les m�mes dimensions que les deux matrices d'entr�e
	CMatrice<MType> mtMATResultat(mtMATParam1.MATGetNbLignes(), mtMATParam1.MATGetNbCol());

	// Addition des deux matrices �l�ment par �l�ment
	for (unsigned int i = 0; i < mtMATParam1.MATGetNbLignes(); i++) {
		for (unsigned int j = 0; j < mtMATParam1.MATGetNbCol(); j++) {
			mtMATResultat.MATModifierElement(i, j, mtMATParam1.MATLireElement(i, j) + mtMATParam2.MATLireElement(i, j));
		}
	}

	// Renvoi de la matrice r�sultat
	return mtMATResultat;
}


/**************************************************************
Nom : UTISoustractionMatrice
***************************************************************
Cette fonction permet de retourner la soustraction de deux matrices.
***************************************************************
Entr�e : Deux matrices de type quelconque
N�cessite : Les deux matrices doivent �tre de m�mes dimensions.
Sortie : La matrice correspondant � la soustraction des deux
		 matrices pass�es en param�tres
Entra�ne : La soustraction des deux matrices est retourn�e.
***************************************************************/
template<typename MType>
CMatrice<MType> CUtilitaireMatrice<MType>::UTISoustractionMatrice(CMatrice<MType>& mtMATParam1, CMatrice<MType>& mtMATParam2)
{
	// V�rification que les deux matrices ont les m�mes dimensions
	if (mtMATParam1.MATGetNbLignes() != mtMATParam2.MATGetNbLignes() || mtMATParam1.MATGetNbCol() != mtMATParam2.MATGetNbCol()) {
		CException EXCDimDifferentes;
		EXCDimDifferentes.EXCModifierValeur(DIMENSIONS_MATRICES_DIFFERENTES);
		throw(EXCDimDifferentes);
	}

	// Cr�ation d'une matrice r�sultat avec les m�mes dimensions que les matrices d'entr�e
	CMatrice<MType> mtMATResultat(mtMATParam1.MATGetNbLignes(), mtMATParam1.MATGetNbCol());

	// Soustraction des deux matrices �l�ment par �l�ment
	for (unsigned int i = 0; i < mtMATParam1.MATGetNbLignes(); i++) {
		for (unsigned int j = 0; j < mtMATParam1.MATGetNbCol(); j++) {
			mtMATResultat.MATModifierElement(i, j, mtMATParam1.MATLireElement(i, j) - mtMATParam2.MATLireElement(i, j));
		}
	}

	// Renvoi de la matrice r�sultat
	return mtMATResultat;
}