M:Petit probleme concernant les angles: comme PI n'est pas exact, on a cosinus(90)=0.0000001213 truc du genre... je sais pas si on peut changer ça.

M: pour les operations sur des données qui ne devraient pas fonctionner (par exemple Modulo sur 2 réels, ou factoriel sur entier etc) J'ai fait que les 2 données dépilées sont re-empilées. Donc sur la calculatrice, c'est comme si rien ne s'est passé. (Mais l'operateur modulo disparait de la pile)
Pour le moment c'est comme ça, on peut ajouter une exception, mais je vois pas trop comment pour le moment. (Juste un throw?)


- Opérations sur les expressions :
  	1) Expression X + => Expression.enfiler_fin(X); Expression.enfiler_fin(+);
	2) X Expression + => Expression.enfiler_debut(X); Expression.enfiler_fin(+);

- Gérer la division par zéro

http://sourcemaking.com/design_patterns/template_method
