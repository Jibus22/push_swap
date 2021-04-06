# ALGO PUSH A TO B :
## Concept
 On essaye de placer au mieux `[topA-n -- topA+n]`  dans la stack B.
 Pour cela on calcule avant toute chose le nombre de moves nécessaire pour
 placer chaque `2n` valeurs et on garde le plus efficace.
 
## La logique est :
 Pour chaque valeurs de A dans `[(topA - n) - (topA + n)]`, est
 calculé le nombre de moves nécéssaire à son placement idéal dans B.
 Cela implique donc des moves dans A ainsi que des moves dans B.
 Il faut dès lors prendre en compte les doubles moves (`RR`, `RRR`).

 La valeur qui sera déplacée dans B sera celle qui implique le moins de moves.
 
## Une limite de moves doit être donnée.
 Si la stack B mesure 100 et qu'il faut faire 45 rotate pour placer
 notre valeur, on ne valide pas ce move trop important et on préfere soit :
 - Poper la valeur sur le bottom de A si cela permet de faire une suite.
 - Pusher sur topB même si ça crée un "désordre".

 De fait, on se retrouve avec une stack A avec plusieurs suites en pyramide
 ascendante, et descendante pour la B.


## Boucle infinie ?
 Que faire si on se retrouve vers une fin de stack A et que les potentielles
 valeurs à push sur B sont en dehors de la limite de moves donnée ?
 Il y a ici un risque de boucle infinie à RA sans arrêt.

 On peut garder en mémoire un index de la première suite créée. Cet index
 est mis à jour à chaque `RA`.
 Dès lors qu'il est atteint on sait qu'on a un potentiel risque et on change
 alors le comportement de l'algo :
 Il faut tout pousser sur la stack B de manière intelligente.
 - Si on arrive pas à placer les valeurs dans la stack B on les push au top en conservant une logique d'ordre décroissant.


# ALGO PUSH B TO A :

 <3
