#ifndef __CLIENT_H_
#define __CLIENT_H_

#include "field.hpp"

/*
** \file client.hpp
** \brief Fichier permettant de spécifier les fonctions nécessaires dans un client
** \author SD
*/

/*
** \class Algorithm
** \brief Classe regroupant les différentes fonction d'un client
 */
class Algorithm{
    public :
        Algorithm();
        /**
         * \brief Permet d'initialiser le terrain (c'est à dire déclarer une instance Field et la completer)*/
        Field initialisation(Field Field);

        /**
         * \brief Algorihme coeur de votre stratégie*/
        Field pathfinding(Field Field);

        /**
         * \brief Nom de votre stratégie !*/
        std::string name;
};


/**
 * \brief Permet de finaliser la chose avant de l'envoyer en test*/
Field finalization();

#endif // __CLIENT_H_
