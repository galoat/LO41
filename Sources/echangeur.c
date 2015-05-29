/**
* \file echangeur.c
* \brief Programme de simulation des échangeurs
* \author Florian Lacour & Michaël Ayeng
* \version 0.2
* \date 13 Mai 2015
*/

#include "echangeur.h"

/**
* \fn void creationEchangeur(echangeur* c,int Id,int D,int G,int H,int B)
* \brief Fonction permettant le paramètrage d'un echangeur
*
* \param c Structure de l'échangeur
* \param Id Numéro d'identification de l'échangeur
* \param D Numéro de l'échangeur se trouvant à droite
* \param G Numéro de l'échangeur se trouvant à gauche
* \param H Numéro de l'échangeur se trouvant en haut
* \param B Numéro de l'échangeur se trouvant en bas
*
*/
void creationEchangeur(echangeur* c,int Id,int D,int G,int H,int B){
    c->numId = Id;
    c->haut = H;
    c->bas = B;
    c->droite = D;
    c->gauche = G;
    c->occuper = false;
}

/**
* \fn void afficherEchangeur(echangeur* c)
* \brief Fonction permettant l'affichage d'informations concernant un échangeur
*
* \param c Structure de l'échangeur
*
*/
void afficherEchangeur(echangeur* c){
  printf("\n-----------------------");
  printf("\nInformations echangeur n°%d",c->numId);
  printf("\n-----------------------");
  printf("\n\tConnexion haute: %d\n\tConnexion basse: %d\n\tConnexion gauche: %d\n\tConnexion droite: %d\n\tBlocage: %d",c->haut,c->bas,c->gauche,c->droite,c->occuper);
}

/**
* \fn void creationVehicule(vehicule* v,int IdEchangeur,int depart,int arrivee)
* \brief Fonction permettant le paramètrage d'un véhicule
*
* \param v Structure du véhicule
* \param IdEchangeur Numéro d'identification de l'échangeur
* \param depart Point de départ du véhicule
* \param arrivee Point d'arrivée du véhicule
*
*/
void creationVehicule(vehicule* v,int IdEchangeur,int depart,int arrivee){
  v->IdEchangeur = IdEchangeur;
  v->depart = depart;
  v->arrivee = arrivee;
}

/**
* \fn void afficherVehicule(vehicule* v)
* \brief Fonction permettant l'affichage d'informations concernant un véhicule
*
* \param c Structure du véhicule
*
*/
void afficherVehicule(vehicule* v){
  printf("\n-----------------------");
  printf("\nInformations véhicule");
  printf("\n-----------------------");
  printf("\n\tEchangeur propriétaire: %d\n\tPoint de départ: %d\n\tPoint d'arrivée: %d",v->IdEchangeur,v->depart,v->arrivee);
}

/**
* \fn void* traitantThread(void* param)
* \brief Fonction gerant un thread "Echangeur"
*
* \param param Pointeur contenant un echangeur
*
*/
void* traitantThreadEchangeur(void* param){
    echangeur* ech= (echangeur*) param;
    // Utilisation Mutex ????
    afficherEchangeur(ech);
    fflush(stdout);
    pthread_exit(NULL);
}