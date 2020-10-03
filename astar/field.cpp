#include "field.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Square::Square(){
   
}

Square::Square(int xw, int yw, enum state statew):x(xw),y(yw),square_state(statew)
{
}

Field::Field(){
    x=32;
    y=23;
    green_case={0,7};
    red_case={28,9};
}

int Field::x_size(Field Field){
    return Field.x;
}

int Field::y_size(Field Field){
    return Field.y;
}

Square Field::new_Square(int x, int y, enum state state){
    Square Square(x,y,state);
    return Square;
}


Field Field::fillmap(Field Field){
    for (int i=0; i < Field.x_size(Field); i++) {
        for (int j=0; j<Field.y_size(Field); j++) {
            Field.map[i][j]=Field.new_Square(i,j,nothing);
            if (i==0 && j==7) {
                Field.map[i][j]=Field.new_Square(i, j, departure);
            }
            if (i==28 && j==9) {
                Field.map[i][j]=Field.new_Square(i, j, arrival);
            }
        }
    }
    for (int j=0; j<Field.y_size(Field); j++) {
        if (j==0||j==1) {
            for (int i = 20; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==2||j==3) {
            for (int i=21; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==4) {
            for (int i=23; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==5) {
            for (int i=8; i < 16; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=25; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==6) {
            for (int i=10; i < 19; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=29; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==7) {
            for (int i=14; i < 20; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==8) {
            for (int i=16; i < 20; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==9) {
            for (int i=16; i < 21; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==10) {
            for (int i=17; i < 21; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==11) {
            for (int i=18; i < 21; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=27; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==12) {
            for (int i=18; i < 21; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=25; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==13) {
            for (int i=7; i < 8; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=19; i < 21; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=24; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==14) {
            for (int i=7; i < 9; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=20; i < 22; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=24; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==15) {
            for (int i=8; i < 10; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=20; i < 22; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=24; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==16) {
            for (int i=8; i < 11; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=20; i < 22; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=23; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==17) {
            for (int i=9; i < 12; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=20; i < 21; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=23; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==18) {
            for (int i=8; i < 12; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=19; i < 21; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=22; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==19) {
            for (int i=8; i < 12; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=18; i < 20; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=22; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==20) {
            for (int i=7; i < 11; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=21; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==21) {
            for (int i=6; i < 10; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=21; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==22) {
            for (int i=5; i < 9; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=21; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
        if (j==23) {
            for (int i=4; i < 9; i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
            for (int i=21; i < Field.x_size(Field); i++) {
                Field.map[i][j]=Field.new_Square(i, j, obstacle);
            }
        }
    }
    return Field;
}

void Field::printMap(Field Field){
    ofstream heatmap;
    heatmap.open("./vision.ppm", std::ofstream::out | std::ofstream::trunc);
    heatmap << "P3 \n" <<std::endl; //Portable pixel map mode
    heatmap << (Field.x_size(Field)) << " " << (Field.y_size(Field)) <<std::endl; //Size of file
    heatmap << "255" <<std::endl;//Max number of color

    for (int j=0; j< Field.y_size(Field); j++) {
        for (int i=0; i < Field.x_size(Field); i++) {
            int R,G,B;
            if (Field.map[i][j].square_state==obstacle) {
                R=0.;
                G=0.;
                B=0.;
            }
            else if (Field.map[i][j].square_state==nothing) {
                R=255.;
                G=255.;
                B=255.;
            }
            else if (Field.map[i][j].square_state==departure) {
                R=0.;
                G=255.;
                B=0.;
            }
            else if (Field.map[i][j].square_state==arrival){
                R=255.;
                G=0.;
                B=0.;
            }
            else if (Field.map[i][j].square_state==path){
                R=135.;
                G=206.;
                B=235.;
            }

            heatmap << setw(3) << R << " " << setw(3) << G << " " << setw(3) << B << "  ";
        }
    }
      heatmap << "\n" << endl;
      heatmap.close();

}

enum state Field::is_valid(int x, int y, Field Field){
    return Field.map[x][y].square_state;
}

