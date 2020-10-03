#ifndef __FIELD_H_
#define __FIELD_H_

/*!
 * \file field.hpp
 * \brief Ce fichier permet de coder le terrain que nous utilisons pour l'Astar avec ses obstacles etc. /!\ NE PAS MODIFIER LE FICHIER /!\
 * \author SD
 */

#include <array>

//32 * 23

/*!
 * \brief Taille maximum en x de la map
 */
#define MAX_X 50
/*!
 * \brief Taille maximum en y de la map
 */
#define MAX_Y 50

/*!
 * \brief Énumération permettant d'associer à une case un état
 * \param nothing La case est vide, nous pouvons passer dessus
 * \param obstacle La case est un obstacle impossible d'aller dessus
 * \param departure Point de départ de l'aventure
 * \param arrival Point d'arrivée
 * \param path Un point considéré comme élément du chemin entre le point de départ et le point d'arrivée
 */
enum state{
nothing,
obstacle,
departure,
arrival,
path,
};

/**
 * \brief Une simple structure permettant d'avoir une position*/
struct Position{
    int x;
    int y;
};

/*!
 * \class Square
 * \brief Classe permettant de coder un carré de la map
 */
class Square{
    public:
        /**
         * \brief Constructeur de la classe, permet de créer un nouveau carré
         */
        Square();
        /**
         * \brief Constructeur surchargé de la classe
         * \param xw la position x voulue pour la nouvelle case
         * \param yw la position y voulue pour la nouvelle case
         * \param statew l'état voulu pour la nouvelle case*/
        Square(int xw, int yw, enum state statew);
        /**
         * \brief L'état courant de la case
         */
        enum state square_state;
    private:
        int x;
        int y;
};

/*
 * \class Field
 * \brief Classe permettant de coder la map
 */
class Field {
    public :
        /**
         * \brief Permet d'initialiser une map totalement vide*/
        Field();
        /**
         * \brief Permet d'obtenir la taille du terrain en x
         * \param Field le terrain sur lequel on travaille */
        int x_size(Field Field);
        /**
         * \brief Permet d'obtneir la taille du terrain en y
         * \param Field le terrain sur lequel on travaille */
        int y_size(Field Field);
        /**
         * \breif Permet de remplir la map avec les différents obstacles */
        Field fillmap(Field Field);
        /**
         * \brief Permet d'afficher tous les éléments de la map (départ, arrivée, chemin, obstacles) dans vision.ppm que l'on peut ouvrir avec la commande "eog -f vision.pmm"*/
        void printMap(Field Field);

        /** \brief Permet d'obtenir l'état d'une case */
        enum state is_valid(int x, int y, Field Field);

        std::array<std::array<Square,MAX_X>,MAX_Y> map;

        struct Position green_case;

        struct Position red_case;

    private :
        Square new_Square(int x, int y, enum state state);
        int x;
        int y;
};

#endif // __FIELD_H_
