# Fdf

Premier projet de la branche graphique de 42.
Le but est de, grâce à la librairie graphique qui nous est donnée (minilibix)
de représenter en '3D' le cadrillage topographique qui nous est donné en paramètre.

Un make permet de compiler le programme.
Des maps de test sont disponibles dans le dossier test_maps.
Executer la commande : "./fdf test_maps/42.fdf" pour lancer la visualisation graphique du fichier 42.fdf
la touche echap permet de sortir du programme et les touches 'WASD' de deplacer la forme sur votre plan, tout le reste est affiché dans le menu.

(edit.) : suite a la nouvelle maj Mojave OpenGl est devenu obsolète, si vous avez des warning à la compilation, rien de dramatique le programme marchera ...

ex. pour 42.fdf :

```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

```
![image1](https://github.com/ncoursol/Fdf/blob/master/screenshot/image1.png)

autre ex. plus conséquent :

![image1](https://github.com/ncoursol/Fdf/blob/master/screenshot/image2.png)
![image1](https://github.com/ncoursol/Fdf/blob/master/screenshot/image3.png)
