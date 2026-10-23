# SVG_project_C

1. [Fonctionnalités](#-fonctionnalités)
2. [Prérequis & Compilation](#-prérequis--compilation)
3. [Utilisation](#-utilisation)
4. [Ce que j'ai appris](#-ce-que-jai-appris)

##  Fonctionnalités
Le programme permet de manipuler un "viewport" :
* Formes gérées : Cercles, ellipses, carrés, rectangles, lignes, enchaînements de lignes (polylignes), polygones.
* Transformations géométriques et modification du style: 
  * Modification de la couleur de trait et de la couleur de fond d' une forme.
  * Modification de la position $X$ et $Y$ d' un point.
  * Déplacement en $X$ et $Y$ d' une forme
  * Rotation par rapport au centre de la fenetre selon un angle donné
  * inversion selon l'axe $X$ ou $Y$
* Gestion des fichiers : Sauvegarde et chargement des structures graphiques.

##  Prérequis & compilation
* Pour compiler le projet :
  ```bash
  make build
* Pour compiler et executer le projet
  ```bash
  make build && ./projet
* Pour supprimer les binaires et l' executable
  ```bash
  make clean
## Utilsation

* Une fois le projet compilé, vous pouvez lancer l'exécutable généré :
```bash
./projet
```
* pour visualiser les formes creer : 
    * ouvrir le fichier svgformer.svg
## Ce que j'ai appris
* La rigueur de la gestion de la mémoire
* L'utilisation des struct, union, enum et liste chainé
