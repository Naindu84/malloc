## theron_b

|==|===|==|===========

|==|===|==|===========|==|====

## What are you talking about ?

I have to create a new metadata in the end of process.

More, I will allocate the difference of the pointer and his new version.

Finally, I will put the datas of the pointer in his new version.

La fonction malloc :

Elle vérifie s'il existe une place disponible dans la liste chainee des elements
 du malloc.

Il faut ajouter la vérification du pointeur dans la liste chainee des elements
 du malloc.

Et s'il n'y est pas allouer normalement.


Donc il y a trois choix possibles :

- Soit l'element en question est deja malloc et il y a assez de place pour
 pouvoir le remettre.

- On change juste sa taille et on met le ptr_free a 0;

- Soit l'element en question est deja malloc et il n'y a pas assez de place
 pour pouvoir le remettre.

- Soit l'element en question n'est pas encore malloque.
## it's more than three option no ?

- On effectue le malloc correctement.

************************************************************************************

Ok, on a un petit probleme sur la moulinette, petit log de ce que j'ai avec quelque puts(malloc/free try // success) :
malloc try
malloc success
Legend... :
:( => NOK
:| => BOF
:) => GOOD
<3 => VERY GOOD
Ary :)
By Six && Massou

malloc try
malloc success
free try
free success
malloc try
Segmentation fault



So, maybe a little deferencing from my part :
Invalid write of size 4
	add_elem_in_list_with_pos (my_gere_list.c:58)

En attente de te lire, cordialement.
=p
