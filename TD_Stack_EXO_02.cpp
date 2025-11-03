#include <iostream>

struct Coordinate {
 int i;
 int j;
 };

Coordinate FindHighestAdjacent(const Coordinate start, const int tab[5][5]);
Coordinate FindBestWay(Coordinate currentCoords, int tab[5][5], int remainingMoves);

 int main() {

    Coordinate start = {2, 2};
    int tab[5][5] = {   {0,8,7,1,5},
                        {3,5,2,8,9},
                        {0,4,0,1,0},
                        {2,4,3,6,1},
                        {1,4,3,1,0}};

    FindBestWay(start, tab, 5);
    
    return 0;
 }

Coordinate FindHighestAdjacent(const Coordinate start, const int tab[5][5]) {
    Coordinate highest = start;
    int highestValue = tab[start.i][start.j];

    if(start.i-1>=0) { //haut
        if(tab[start.i-1][start.j]>highestValue) {
            highest.i = start.i-1;
            highest.j = start.j;
            highestValue = tab[highest.i][highest.j];
        }
    }
    if(start.i+1<5) { //bas
        if(tab[start.i+1][start.j]>highestValue) {
            highest.i = start.i+1;
            highest.j = start.j;
            highestValue = tab[highest.i][highest.j];
        }
    }
    if(start.j-1>=0) { //gauche
        if(tab[start.i][start.j-1]>highestValue) {
            highest.i = start.i;
            highest.j = start.j-1;
            highestValue = tab[highest.i][highest.j];
        }
    }
    if(start.j+1<5) { //droite
        if(tab[start.i][start.j+1]>highestValue) {
            highest.i = start.i;
            highest.j = start.j+1;
            highestValue = tab[highest.i][highest.j];
        }
    }
    return highest;

}


Coordinate FindBestWay(Coordinate currentCoords, int tab[5][5], int remainingMoves) {
    if (remainingMoves == 0) {
        return currentCoords;
    }

    Coordinate bestCoord = FindHighestAdjacent(currentCoords, tab);

    std::cout << "Déplacement vers (" << bestCoord.i << "," << bestCoord.j << ") avec une valeur de " << tab[bestCoord.i][bestCoord.j] << std::endl;

    tab[bestCoord.i][bestCoord.j] = 0; // Marquer comme visité

    return FindBestWay(bestCoord, tab, remainingMoves - 1);
}

