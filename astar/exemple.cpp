#include "client.hpp"

#include <vector>
#include <stdlib.h>

using namespace std;

Algorithm::Algorithm(){
   
}

Field Algorithm::initialisation(Field Field){
    Field=Field.fillmap(Field);
    return Field;
}

// Fonctions auxiliaires que j'utilise pour mon algorithme mais qui restent dans ce fichier

vector<Position> find_good_cell(Field Field){
    vector<Position> good_cell;
    for (int i=0; i< Field.x_size(Field); i++) {
        for (int j=0; j< Field.y_size(Field); j++) {
            if (Field.map[i][j].square_state==nothing) {
                if (Field.is_valid(i+1, j, Field)==departure || Field.is_valid(i+1, j, Field)==path) {
                    good_cell.push_back({i,j});
                }
                if (Field.is_valid(i-1, j, Field)==departure || Field.is_valid(i-1, j, Field)==path) {
                    good_cell.push_back({i,j});
                }
                if (Field.is_valid(i, j+1, Field)==departure || Field.is_valid(i, j+1, Field)==path) {
                    good_cell.push_back({i,j});
                }
                if (Field.is_valid(i, j-1, Field)==departure || Field.is_valid(i, j-1, Field)==path) {
                    good_cell.push_back({i,j});
                }
            }
        }
    }
    return good_cell;
}

// Fin

Field Algorithm::pathfinding(Field Field){
    while(1){
        vector<Position> good_cell=find_good_cell(Field);
        int random;
        if (good_cell.size()!=0) {
            random=rand() % good_cell.size();
        }
        else {
            printf("\033[31mJ'ai échoué :'( \033[0m \n'");
            break;
        }
        int x = good_cell[random].x;
        int y = good_cell[random].y;
        Field.map[x][y].square_state=path;
        if ((x+1==Field.red_case.x && y==Field.red_case.y)
            ||(x==Field.red_case.x && y==Field.red_case.y+1)
            ||(x-1==Field.red_case.x && y==Field.red_case.y)
            ||(x==Field.red_case.x && y-1==Field.red_case.y)) {
            printf("\033[32mChemin trouvé !\033[0m \n");
            break;
        }
        Field.printMap(Field);
    }
    return Field;
}

Field finalization(){
    Algorithm Random;
    Field soluce;
    soluce.fillmap(soluce);
    soluce=Random.initialisation(soluce);
    soluce.printMap(soluce);
    soluce=Random.pathfinding(soluce);
    Random.name="Random !";
    return soluce;
}

int main(int argc, char *argv[]) {
    finalization();
    return 0;
}
