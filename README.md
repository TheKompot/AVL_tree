# AVL_tree

## Triedy
### Node
* Vrchol v strome, ma svoju hodnotu, vysku a  poniter na praveho a laveho syna
* pri nastaveni seba sameho za svojho syna vyhodi NodeError

### Tree
* zakladne vlastnosti binarneho stromu 
* ma abstraktne metody del, find, insert
* da sa pri tvorbe instancie dat vrchol a nastavit ho na koren stromu

### AVL
* dedi  Tree
* ma naprogramovane methody del, find a insert

### AVL_test
* dedi AVL
* existuje aby sa dali lahsie testovat metody ktore nechcem aby boli public (napr prava ci lava rotacia stromu)

## Benchmark
