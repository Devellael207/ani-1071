#Faute 1: manque du point virgule(;)
*message exact: error:expected ';' after expression
*ligne signalée:ligne 3
*ligne reellement fautive : ligne 3 comme le precise le compilateur
*étape : au niveau du compilateur (analyse la syntaxe) lors de la compilation
Mais il est important que ce manque de (;) souligne directement le ligne suivante .
##Faute 2:changer 'printf' par 'Printf'
*message exact: error:use of undeclared identifier 'Printf'; did you mean 'printf'
*ligne signalée :ligne 3
*ligne  reelement fautive : 3 comme le dit le compilateur 
*étape :au niveau du compilateur mais sauf qu'ici il ne s'agis pas d'une erreur de syntaxe mais plutot de symbole.le compilateur cherche donc Printf et ne trouve pour le c++
mais on vas constacter dans le message d'erreur que le compilateur nous propose automatiquement la syntaxe correct d'ou on peut lire (did you mean 'printf') il faut remarque donc que ce changement souligne la ligne où il Printf
###Faute 3 :Enlever la ligne #incude <stdio.h>
*message exact affichee : error: use of undeclared identifier 'printf'
*ligne signalée : ligne 3
*ligne reelement fautive : ligne 1 car il y'a l'abscece de cette ligne  
*étape :au niveau du preprocesseur qui n"as pas copier le contenue 'stdio.h' mais l'erreur est detecte apres par le compilateur car il decouvre que 'printf' n'existe nulle part
