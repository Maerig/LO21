
- En fait, le patron de méthode c'est la classe Opérateur, qui appelle la fonction virtuelle calculer. Pas besoin de rajouter autre chose.

- Oui, il faut passer la pile en paramètre.
- Ce sera beaucoup plus simple et pratique avec un switch.

+ Dans tous les cas, quand on appelle Calculer(), on dépile un ou deux opérateurs et on les définit comme successeurs de l'opérateur.
  Seulement après, on effectue le calcul et on empile le résultat. Ça  sert à rien pour l'instant, mais ce sera beaucoup plus simple
  quand on fera les expressions.

http://sourcemaking.com/design_patterns/template_method
