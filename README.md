# Projet C++ : Les Matrices

L'objectif de ce projet est de réaliser une librairie de classes et fonctions permettant de manipuler des matrices d'éléments. 
En effet, les classes réalisées permettent : 
1. De créer des objets Matrices pour lesquels le type d'éléments est quelconque.
2. De faire des opérations "élémentaires" sur une matrice
3. De faire des opération un peu plus complexe mettant en jeu plusieurs matrices
4. De lire le contenu d'une matrice dans un fichier texte et de créer un objet matrice en mémoire pour stocker les données lues dans le fichier.


## Contraintes techniques 

Pour la réalisation de notre projet, nous avons respecté les quelques contraintes énoncées ci-dessous :
1. Les variables, types, classes, fonction et méthodes respectent les conventions de nommage,
2. Les bonnes pratiques du Génie Logiciel telles qu’elles ont pu être présentées lors des cours d’Algorithmes Orientés Objets et de Langages Orientés Objets ont été mises en œuvre.
3. Nous avons intégré la gestion des exceptions dans notre programme : nous avons utilisé pour cela la classe CException vue en TPs.
4. Nous avons travaillé sous Visual Studio et notre projet est une application console win32.


## Pour commencer

Voici comment fonctionne le programme : il prend en argument des fichiers textes et retourne le résultat de la suite des opérations suivantes :
1. Multiplication de chacune des matrices par une constante c,
2. Division de chacune des matrices par la même constante,
3. Addition de toutes les matrices entre elles : M1+M2+M3...
4. Somme alternée des matrices : M1-M2+M3-M4+M5...
5. Produit des matrices

Les fichiers textes passés en paramètre devront être sous la forme suivante :  
TypeMatrice=<type_base_C>
	NBLignes=<Nombre_de_lignes_de_la_matrice>  
	NBColonnes=<Nombre_de_colonnes_de_la_matrice>  
	Matrice=[  
	<Ligne_1 : autant d’éléments que de colonnes>  
	<Ligne_n : autant d’éléments que de colonnes>  
…  
	<Ligne_NBLignes : autant d’éléments que de colonnes>  
]  
_exemple_:  
	TypeMatrice=double  
	NBLignes=2  
	NBColonnes=3  
	Matrice=[  
	5 3 6  
	1 -2 8  
]  
De plus, il est important de noté que le programme ne gère que des matrices de type double.

## Pré-requis

Aucun pré-requis n'est nécessaire.


## Démarrage

Une fois l'installation terminée, vous pouvez placer l'exécutable `` ProjetC++.exe`` où vous voulez.
Ensuite, pour exécuter correctement le programme, il vous faut entrer dans le terminal le nom de l'exécutable puis le nom des fichiers textes que vous souhaitez lui passer en argument (attention à bien indiquer le chemin des fichiers textes s'ils ne sont pas dans le même répertoire que l'exécutable).

_exemple_: Exécutez la commande ``ProjetC++ M1.txt M2.txt M3.txt M4.txt`` et le programme s'exécutera avec les fichiers M1, M2, M3 et M4 en argument.


## Développé avec

* [Visual Studio 2017](https://visualstudio.microsoft.com/fr/) - IDE


## Auteurs

* **Valentin DESMARES** 
* **Adrien AMOROSO** 


