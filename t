|==|===|==|===========

|==|===|==|===========|==|====

I have to create a new metadata in the end of process.

More, I will allocate the difference of the pointer and his new version.

Finally, I will put the datas of the pointer in his new version.

La fonction malloc :

Elle vérifie s'il existe une place disponible dans la liste chainee des elements du malloc.

Il faut ajouter la vérification du pointeur dans la liste chainee des elements du malloc.

Et s'il n'y est pas allouer normalement.


Donc il y a trois choix possibles :

-Soit l'element en question est deja malloque et il y a assez de place pour pouvoir le remettre.

 -On change juste sa taille et on met le ptr_free a 0;

-Soit l'element en question est deja malloque et il n'y a pas assez de place pour pouvoir le remettre.

 -On va creer une nouvelle metadata.
 -On va recréer un nouveau pointeur de donnee.
 -On le fera pointer sur l'ancien pointeur de donnee.
 -On changera sa taille en fonction de sa nouvelle taille.
 -On changera son statut free en pas free.

-Soit l'element en question n'est pas encore malloque.

 -On effectue le malloc correctement.

0x4222288
Adresse du premier pointeur 0x4222050
Taille du pointeur 568
Adresse du deuxieme pointeur 0x42222b0
Taille du pointeur 42
Adresse du troisieme pointeur 0x4222304
Taille du pointeur 1457664