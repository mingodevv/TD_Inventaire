# TD0 : Inventaire de RPG

Projet C++17 console construit avec CMake.

Pour compiler, lancer et ajouter des fichiers, voir le **Guide du projet C++** fourni avec le cours.

Compilation rapide en ligne de commande :

```bash
cmake -S . -B build
cmake --build build
```

## Réponses aux questions du TD

### C.1 : EnchantCopy

La valeur reste à 40 po. `EnchantCopy` reçoit l'épée **par valeur**, donc une copie : c'est la copie qui est modifiée, puis détruite à la fin de la fonction. L'épée du sac n'est pas touchée.

### C.3 : FindByName("Arc long")

La fonction renvoie `nullptr`, car l'objet n'existe pas. Utiliser ce pointeur sans le vérifier revient à déréférencer un pointeur nul : le programme plante, parfois avant même d'avoir affiché le texte en attente. Correction : tester `if (bow == nullptr)` avant de s'en servir.

### D.1 : pourquoi `const Item&` ?

Le `&` évite une copie inutile de l'objet (qui contient un `std::string`). Le `const` garantit qu'`AddItem` ne modifie pas l'objet reçu, et permet aussi de lui passer un objet temporaire comme `Item("Bouclier", 6.0f, 55)`.

### D.2 : retirer le `const` de GetWeight()

```
C2662 'float Item::GetWeight(void)': cannot convert 'this' pointer from 'const Item' to 'Item &'
```

Dans `AddItem`, `GetTotalWeight` et `Print`, `GetWeight()` est appelée sur un objet const. Or, sur un objet const, on ne peut appeler que des méthodes const. (L'erreur C2088 de la ligne 80 en découle : c'est une erreur en cascade.)

### D.3 : pas de `delete`, pas de fuite ?

Il n'y a aucun `new`. `bag` est détruit automatiquement à la fin de `main`, et son `std::vector` libère tout seul sa mémoire et les `Item` qu'il contient (principe du RAII).

### D.4 : le pointeur vers le Bouclier après dix ajouts

Il n'est plus forcément valide. Quand le vector manque de place, il réalloue un bloc plus grand, y déplace les éléments et libère l'ancien : le pointeur vise alors de la mémoire libérée. Il faut rappeler `FindByName` après avoir modifié le sac.
