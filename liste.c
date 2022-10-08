/**
 * @file liste.c
 * @author meo (meo.prn@outlook.fr)
 * @brief primitives des fonction de la liste
 * @version 0.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "liste.h"

/**
 * @brief creer une liste en fonction de son type
 * 
 * @return liste_t* 
 */
extern t_liste * creer_liste(t_type_liste type){
    t_liste * liste = (t_liste *) malloc(sizeof(t_liste));
    liste->type = type;
    liste->debut_liste = NULL;
    liste->fin_liste = NULL;
    liste->element_courant = NULL;
    switch (type){
        case LISTE_INT:
            liste->precedent = precedent_int;
            liste->suivant = suivant_int;
            liste->valeur_elt = valeur_elt_int;
            liste->modif_elt = modif_elt_int;
            liste->oter_elt = oter_elt_int;
            liste->ajout_droit = ajout_droit_int;
            liste->ajout_gauche = ajout_gauche_int;
            break;
        case LISTE_CHAR:
            liste->precedent = precedent_char;
            liste->suivant = suivant_char;
            liste->valeur_elt = valeur_elt_char;
            liste->modif_elt = modif_elt_char;
            liste->oter_elt = oter_elt_char;
            liste->ajout_droit = ajout_droit_char;
            liste->ajout_gauche = ajout_gauche_char;
            break;
        case LISTE_FLOAT:
            liste->precedent = precedent_float;
            liste->suivant = suivant_float;
            liste->valeur_elt = valeur_elt_float;
            liste->modif_elt = modif_elt_float;
            liste->oter_elt = oter_elt_float;
            liste->ajout_droit = ajout_droit_float;
            liste->ajout_gauche = ajout_gauche_float;
            break;
        case LISTE_DOUBLE:
            liste->precedent = precedent_double;
            liste->suivant = suivant_double;
            liste->valeur_elt = valeur_elt_double;
            liste->modif_elt = modif_elt_double;
            liste->oter_elt = oter_elt_double;
            liste->ajout_droit = ajout_droit_double;
            liste->ajout_gauche = ajout_gauche_double;
            break;
        case LISTE_LONG:
            liste->precedent = precedent_long;
            liste->suivant = suivant_long;
            liste->valeur_elt = valeur_elt_long;
            liste->modif_elt = modif_elt_long;
            liste->oter_elt = oter_elt_long;
            liste->ajout_droit = ajout_droit_long;
            liste->ajout_gauche = ajout_gauche_long;
            break;
        case LISTE_BOOL:
            liste->precedent = precedent_bool;
            liste->suivant = suivant_bool;
            liste->valeur_elt = valeur_elt_bool;
            liste->modif_elt = modif_elt_bool;
            liste->oter_elt = oter_elt_bool;
            liste->ajout_droit = ajout_droit_bool;
            liste->ajout_gauche = ajout_gauche_bool;
            break;
        case LISTE_STRING:
            liste->precedent = precedent_string;
            liste->suivant = suivant_string;
            liste->valeur_elt = valeur_elt_string;
            liste->modif_elt = modif_elt_string;
            liste->oter_elt = oter_elt_string;
            liste->ajout_droit = ajout_droit_string;
            liste->ajout_gauche = ajout_gauche_string;
            break;
    }
    return liste;
}

/**
 * @brief verifier si la liste est vide
 * 
 * @param liste 
 * @return true 
 * @return false 
 */
extern bool est_vide(t_liste * liste){
    return (liste->debut_liste == NULL && liste->fin_liste == NULL);
}

/**
 * @brief verifie si l'element courant est dans la liste
 * 
 * @param liste 
 * @param valeur 
 */
extern bool hors_liste(t_liste * liste){
    return (liste->element_courant == NULL);
}

/**
 * @brief déplacer le curseur sur le premier element de la liste
 * 
 * @param liste 
 */
extern void en_tete(t_liste * liste){
    liste->element_courant = liste->debut_liste;
}

/**
 * @brief déplacer le curseur sur le dernier element de la liste
 * 
 * @param liste 
 */
extern void en_queue(t_liste * liste){
    liste->element_courant = liste->fin_liste;
}

/**
 * @brief déplacer le curseur sur l'element precedent
 * 
 * @param liste 
 */
extern void precedent(t_liste * liste){
    liste->precedent(liste);
}

/**
 * @brief déplacer le curseur sur l'element suivant
 * 
 * @param liste 
 */
extern void suivant(t_liste * liste){
    liste->suivant(liste);
}

/**
 * @brief retourner la valeur de l'element courant
 * 
 * @param liste  
 */
extern void valeur_elt(t_liste * liste, void * val){
    return liste->valeur_elt(liste, val);
}

/**
 * @brief modifier la valeur de l'element courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt(t_liste * liste, void * val){
    liste->modif_elt(liste, val);
}

/**
 * @brief oter l'element courant
 * 
 * @param liste 
 */
extern void oter_elt(t_liste * liste){
    liste->oter_elt(liste);
}

/**
 * @brief ajouter un element a droite de l'element courant
 * 
 * @param liste 
 * @param valeur 
 */
extern void ajout_droit(t_liste * liste, void * valeur){
    liste->ajout_droit(liste, valeur);
}

/**
 * @brief ajouter un element a gauche de l'element courant
 * 
 * @param liste 
 * @param valeur 
 */
extern void ajout_gauche(t_liste * liste, void * valeur){
    liste->ajout_gauche(liste, valeur);
}





/**
 * @brief décale le curseur sur l'element int precedent
 * 
 * @param liste 
 */
static void precedent_int(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_int *)liste->element_courant)->precedent;
    }
}

/**
 * @brief décale le curseur sur l'element char precedent
 * 
 * @param liste 
 */
static void precedent_char(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_char *)liste->element_courant)->precedent;
    }
}

/**
 * @brief décale le curseur sur l'element float precedent
 * 
 * @param liste 
 */
static void precedent_float(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_float *)liste->element_courant)->precedent;
    }
}

/**
 * @brief décale le curseur sur l'element double precedent
 * 
 * @param liste 
 */
static void precedent_double(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_double *)liste->element_courant)->precedent;
    }
}

/**
 * @brief décale le curseur sur l'element long precedent
 * 
 * @param liste 
 */
static void precedent_long(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_long *)liste->element_courant)->precedent;
    }
}

/**
 * @brief décale le curseur sur l'element bool precedent
 * 
 * @param liste 
 */
static void precedent_bool(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_bool *)liste->element_courant)->precedent;
    }
}

/**
 * @brief décale le curseur sur l'element string precedent
 * 
 * @param liste 
 */
static void precedent_string(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_string *)liste->element_courant)->precedent;
    }
}





/**
 * @brief décale le curseur sur l'element int suivant
 * 
 * @param liste 
 */
static void suivant_int(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_int *)liste->element_courant)->suivant;
    }
}

/**
 * @brief décale le curseur sur l'element char suivant
 * 
 * @param liste 
 */
static void suivant_char(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_char *)liste->element_courant)->suivant;
    }
}

/**
 * @brief décale le curseur sur l'element float suivant
 * 
 * @param liste 
 */
static void suivant_float(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_float *)liste->element_courant)->suivant;
    }
}

/**
 * @brief décale le curseur sur l'element double suivant
 * 
 * @param liste 
 */
static void suivant_double(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_double *)liste->element_courant)->suivant;
    }
}

/**
 * @brief décale le curseur sur l'element long suivant
 * 
 * @param liste 
 */
static void suivant_long(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_long *)liste->element_courant)->suivant;
    }
}

/**
 * @brief décale le curseur sur l'element bool suivant
 * 
 * @param liste 
 */
static void suivant_bool(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_bool *)liste->element_courant)->suivant;
    }
}

/**
 * @brief décale le curseur sur l'element string suivant
 * 
 * @param liste 
 */
static void suivant_string(t_liste * liste){
    if(!hors_liste(liste)){
        liste->element_courant = ((t_element_liste_string *)liste->element_courant)->suivant;
    }
}





/**
 * @brief retourne la valeur de l'element int courant
 * 
 * @param liste 
 * @return void* 
 */
extern void valeur_elt_int(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        *((int *)val) = ((t_element_liste_int *)liste->element_courant)->val;
    }
}

/**
 * @brief retourne la valeur de l'element char courant
 * 
 * @param liste 
 * @return void* 
 */
extern void valeur_elt_char(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        *((char *)val) = ((t_element_liste_char *)liste->element_courant)->val;
    }
}

/**
 * @brief retourne la valeur de l'element float courant
 * 
 * @param liste 
 * @return void* 
 */
extern void valeur_elt_float(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        *((float *)val) = ((t_element_liste_float *)liste->element_courant)->val;
    }
}

/**
 * @brief retourne la valeur de l'element double courant
 * 
 * @param liste 
 * @return void* 
 */
extern void valeur_elt_double(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        *((double *)val) = ((t_element_liste_double *)liste->element_courant)->val;
    }
}

/**
 * @brief retourne la valeur de l'element long courant
 * 
 * @param liste 
 * @return void* 
 */
extern void valeur_elt_long(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        *((long *)val) = ((t_element_liste_long *)liste->element_courant)->val;
    }
}

/**
 * @brief retourne la valeur de l'element bool courant
 * 
 * @param liste 
 * @return void* 
 */
extern void valeur_elt_bool(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        *((bool *)val) = ((t_element_liste_bool *)liste->element_courant)->val;
    }
}

/**
 * @brief retourne la valeur de l'element string courant
 * 
 * @param liste 
 * @return void* 
 */
extern void valeur_elt_string(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        *((char **)val) = ((t_element_liste_string *)liste->element_courant)->val;
    }
}





/**
 * @brief modifie la valeur de l'element int courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt_int(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        ((t_element_liste_int *)liste->element_courant)->val = *((int *)val);
    }
}

/**
 * @brief modifie la valeur de l'element char courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt_char(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        ((t_element_liste_char *)liste->element_courant)->val = *((char *)val);
    }
}

/**
 * @brief modifie la valeur de l'element float courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt_float(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        ((t_element_liste_float *)liste->element_courant)->val = *((float *)val);
    }
}

/**
 * @brief modifie la valeur de l'element double courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt_double(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        ((t_element_liste_double *)liste->element_courant)->val = *((double *)val);
    }
}

/**
 * @brief modifie la valeur de l'element long courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt_long(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        ((t_element_liste_long *)liste->element_courant)->val = *((long *)val);
    }
}

/**
 * @brief modifie la valeur de l'element bool courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt_bool(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        ((t_element_liste_bool *)liste->element_courant)->val = *((bool *)val);
    }
}

/**
 * @brief modifie la valeur de l'element string courant
 * 
 * @param liste 
 * @param val 
 */
extern void modif_elt_string(t_liste * liste, void * val){
    if(!hors_liste(liste)){
        ((t_element_liste_string *)liste->element_courant)->val = *((char **)val);
    }
}





/**
 * @brief supprime l'element int courant et se place sur l'element suivant
 * 
 * @param liste 
 */
static void oter_elt_int(t_liste * liste){
    if(!hors_liste(liste)){
        t_element_liste_int * elt = (t_element_liste_int *)liste->element_courant;
        if(elt->precedent != NULL){
            elt->precedent->suivant = elt->suivant;
        }else{
            liste->debut_liste = elt->suivant;
        }
        if(elt->suivant != NULL){
            elt->suivant->precedent = elt->precedent;
        }else{
            liste->fin_liste = elt->precedent;
        }
        liste->element_courant = elt->suivant;
        free(elt);
    }
}

/**
 * @brief supprime l'element char courant et se place sur l'element suivant
 * 
 * @param liste 
 */
static void oter_elt_char(t_liste * liste){
    if(!hors_liste(liste)){
        t_element_liste_char * elt = (t_element_liste_char *)liste->element_courant;
        if(elt->precedent != NULL){
            elt->precedent->suivant = elt->suivant;
        }else{
            liste->debut_liste = elt->suivant;
        }
        if(elt->suivant != NULL){
            elt->suivant->precedent = elt->precedent;
        }else{
            liste->fin_liste = elt->precedent;
        }
        liste->element_courant = elt->suivant;
        free(elt);
    }
}

/**
 * @brief supprime l'element float courant et se place sur l'element suivant
 * 
 * @param liste 
 */
static void oter_elt_float(t_liste * liste){
    if(!hors_liste(liste)){
        t_element_liste_float * elt = (t_element_liste_float *)liste->element_courant;
        if(elt->precedent != NULL){
            elt->precedent->suivant = elt->suivant;
        }else{
            liste->debut_liste = elt->suivant;
        }
        if(elt->suivant != NULL){
            elt->suivant->precedent = elt->precedent;
        }else{
            liste->fin_liste = elt->precedent;
        }
        liste->element_courant = elt->suivant;
        free(elt);
    }
}

/**
 * @brief supprime l'element double courant et se place sur l'element suivant
 * 
 * @param liste 
 */
static void oter_elt_double(t_liste * liste){
    if(!hors_liste(liste)){
        t_element_liste_double * elt = (t_element_liste_double *)liste->element_courant;
        if(elt->precedent != NULL){
            elt->precedent->suivant = elt->suivant;
        }else{
            liste->debut_liste = elt->suivant;
        }
        if(elt->suivant != NULL){
            elt->suivant->precedent = elt->precedent;
        }else{
            liste->fin_liste = elt->precedent;
        }
        liste->element_courant = elt->suivant;
        free(elt);
    }
}

/**
 * @brief supprime l'element long courant et se place sur l'element suivant
 * 
 * @param liste 
 */
static void oter_elt_long(t_liste * liste){
    if(!hors_liste(liste)){
        t_element_liste_long * elt = (t_element_liste_long *)liste->element_courant;
        if(elt->precedent != NULL){
            elt->precedent->suivant = elt->suivant;
        }else{
            liste->debut_liste = elt->suivant;
        }
        if(elt->suivant != NULL){
            elt->suivant->precedent = elt->precedent;
        }else{
            liste->fin_liste = elt->precedent;
        }
        liste->element_courant = elt->suivant;
        free(elt);
    }
}

/**
 * @brief supprime l'element bool courant et se place sur l'element suivant
 * 
 * @param liste 
 */
static void oter_elt_bool(t_liste * liste){
    if(!hors_liste(liste)){
        t_element_liste_bool * elt = (t_element_liste_bool *)liste->element_courant;
        if(elt->precedent != NULL){
            elt->precedent->suivant = elt->suivant;
        }else{
            liste->debut_liste = elt->suivant;
        }
        if(elt->suivant != NULL){
            elt->suivant->precedent = elt->precedent;
        }else{
            liste->fin_liste = elt->precedent;
        }
        liste->element_courant = elt->suivant;
        free(elt);
    }
}

/**
 * @brief supprime l'element string courant et se place sur l'element suivant
 * 
 * @param liste 
 */
static void oter_elt_string(t_liste * liste){
    if(!hors_liste(liste)){
        t_element_liste_string * elt = (t_element_liste_string *)liste->element_courant;
        if(elt->precedent != NULL){
            elt->precedent->suivant = elt->suivant;
        }else{
            liste->debut_liste = elt->suivant;
        }
        if(elt->suivant != NULL){
            elt->suivant->precedent = elt->precedent;
        }else{
            liste->fin_liste = elt->precedent;
        }
        liste->element_courant = elt->suivant;
        free(elt);
    }
}





/**
 * @brief ajoute un element int a droite de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_droit_int(t_liste * liste, void * val){
    t_element_liste_int * elt = (t_element_liste_int *)malloc(sizeof(t_element_liste_int));
    elt->val = *(int *)val;
    if(!liste_vide(liste)){
        elt->suivant = ((t_element_liste_int *)liste->element_courant)->suivant;
        elt->precedent = liste->element_courant;
        if(((t_element_liste_int *)liste->element_courant)->suivant != NULL){
            ((t_element_liste_int *)liste->element_courant)->suivant->precedent = elt;
        }else{
            liste->fin_liste = elt;
        }
        ((t_element_liste_int *)liste->element_courant)->suivant = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element char a droite de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_droit_char(t_liste * liste, void * val){
    t_element_liste_char * elt = (t_element_liste_char *)malloc(sizeof(t_element_liste_char));
    elt->val = *(char *)val;
    if(!liste_vide(liste)){
        elt->suivant = ((t_element_liste_char *)liste->element_courant)->suivant;
        elt->precedent = liste->element_courant;
        if(((t_element_liste_char *)liste->element_courant)->suivant != NULL){
            ((t_element_liste_char *)liste->element_courant)->suivant->precedent = elt;
        }else{
            liste->fin_liste = elt;
        }
        ((t_element_liste_char *)liste->element_courant)->suivant = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element double a droite de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_droit_double(t_liste * liste, void * val){
    t_element_liste_double * elt = (t_element_liste_double *)malloc(sizeof(t_element_liste_double));
    elt->val = *(double *)val;
    if(!liste_vide(liste)){
        elt->suivant = ((t_element_liste_double *)liste->element_courant)->suivant;
        elt->precedent = liste->element_courant;
        if(((t_element_liste_double *)liste->element_courant)->suivant != NULL){
            ((t_element_liste_double *)liste->element_courant)->suivant->precedent = elt;
        }else{
            liste->fin_liste = elt;
        }
        ((t_element_liste_double *)liste->element_courant)->suivant = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

static void ajout_droit_long(t_liste * liste, void * val){
    t_element_liste_long * elt = (t_element_liste_long *)malloc(sizeof(t_element_liste_long));
    elt->val = *(long *)val;
    if(!liste_vide(liste)){
        elt->suivant = ((t_element_liste_long *)liste->element_courant)->suivant;
        elt->precedent = liste->element_courant;
        if(((t_element_liste_long *)liste->element_courant)->suivant != NULL){
            ((t_element_liste_long *)liste->element_courant)->suivant->precedent = elt;
        }else{
            liste->fin_liste = elt;
        }
        ((t_element_liste_long *)liste->element_courant)->suivant = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element bool a droite de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_droit_bool(t_liste * liste, void * val){
    t_element_liste_bool * elt = (t_element_liste_bool *)malloc(sizeof(t_element_liste_bool));
    elt->val = *(bool *)val;
    if(!liste_vide(liste)){
        elt->suivant = ((t_element_liste_bool *)liste->element_courant)->suivant;
        elt->precedent = liste->element_courant;
        if(((t_element_liste_bool *)liste->element_courant)->suivant != NULL){
            ((t_element_liste_bool *)liste->element_courant)->suivant->precedent = elt;
        }else{
            liste->fin_liste = elt;
        }
        ((t_element_liste_bool *)liste->element_courant)->suivant = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element string a droite de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_droit_string(t_liste * liste, void * val){
    t_element_liste_string * elt = (t_element_liste_string *)malloc(sizeof(t_element_liste_string));
    elt->val = (char *)val;
    if(!liste_vide(liste)){
        elt->suivant = ((t_element_liste_string *)liste->element_courant)->suivant;
        elt->precedent = liste->element_courant;
        if(((t_element_liste_string *)liste->element_courant)->suivant != NULL){
            ((t_element_liste_string *)liste->element_courant)->suivant->precedent = elt;
        }else{
            liste->fin_liste = elt;
        }
        ((t_element_liste_string *)liste->element_courant)->suivant = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}





/**
 * @brief ajoute un element int a gauche de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_gauche_int(t_liste * liste, void * val){
    t_element_liste_int * elt = (t_element_liste_int *)malloc(sizeof(t_element_liste_int));
    elt->val = *(int *)val;
    if(!liste_vide(liste)){
        elt->suivant = liste->element_courant;
        elt->precedent = ((t_element_liste_int *)liste->element_courant)->precedent;
        if(((t_element_liste_int *)liste->element_courant)->precedent != NULL){
            ((t_element_liste_int *)liste->element_courant)->precedent->suivant = elt;
        }else{
            liste->debut_liste = elt;
        }
        ((t_element_liste_int *)liste->element_courant)->precedent = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element char a gauche de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_gauche_char(t_liste * liste, void * val){
    t_element_liste_char * elt = (t_element_liste_char *)malloc(sizeof(t_element_liste_char));
    elt->val = *(char *)val;
    if(!liste_vide(liste)){
        elt->suivant = liste->element_courant;
        elt->precedent = ((t_element_liste_char *)liste->element_courant)->precedent;
        if(((t_element_liste_char *)liste->element_courant)->precedent != NULL){
            ((t_element_liste_char *)liste->element_courant)->precedent->suivant = elt;
        }else{
            liste->debut_liste = elt;
        }
        ((t_element_liste_char *)liste->element_courant)->precedent = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element float a gauche de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_gauche_float(t_liste * liste, void * val){
    t_element_liste_float * elt = (t_element_liste_float *)malloc(sizeof(t_element_liste_float));
    elt->val = *(float *)val;
    if(!liste_vide(liste)){
        elt->suivant = liste->element_courant;
        elt->precedent = ((t_element_liste_float *)liste->element_courant)->precedent;
        if(((t_element_liste_float *)liste->element_courant)->precedent != NULL){
            ((t_element_liste_float *)liste->element_courant)->precedent->suivant = elt;
        }else{
            liste->debut_liste = elt;
        }
        ((t_element_liste_float *)liste->element_courant)->precedent = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element double a gauche de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_gauche_double(t_liste * liste, void * val){
    t_element_liste_double * elt = (t_element_liste_double *)malloc(sizeof(t_element_liste_double));
    elt->val = *(double *)val;
    if(!liste_vide(liste)){
        elt->suivant = liste->element_courant;
        elt->precedent = ((t_element_liste_double *)liste->element_courant)->precedent;
        if(((t_element_liste_double *)liste->element_courant)->precedent != NULL){
            ((t_element_liste_double *)liste->element_courant)->precedent->suivant = elt;
        }else{
            liste->debut_liste = elt;
        }
        ((t_element_liste_double *)liste->element_courant)->precedent = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element string a gauche de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_gauche_long(t_liste * liste, void * val){
    t_element_liste_long * elt = (t_element_liste_long *)malloc(sizeof(t_element_liste_long));
    elt->val = *(long *)val;
    if(!liste_vide(liste)){
        elt->suivant = liste->element_courant;
        elt->precedent = ((t_element_liste_long *)liste->element_courant)->precedent;
        if(((t_element_liste_long *)liste->element_courant)->precedent != NULL){
            ((t_element_liste_long *)liste->element_courant)->precedent->suivant = elt;
        }else{
            liste->debut_liste = elt;
        }
        ((t_element_liste_long *)liste->element_courant)->precedent = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element bool a gauche de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_gauche_bool(t_liste * liste, void * val){
    t_element_liste_bool * elt = (t_element_liste_bool *)malloc(sizeof(t_element_liste_bool));
    elt->val = *(bool *)val;
    if(!liste_vide(liste)){
        elt->suivant = liste->element_courant;
        elt->precedent = ((t_element_liste_bool *)liste->element_courant)->precedent;
        if(((t_element_liste_bool *)liste->element_courant)->precedent != NULL){
            ((t_element_liste_bool *)liste->element_courant)->precedent->suivant = elt;
        }else{
            liste->debut_liste = elt;
        }
        ((t_element_liste_bool *)liste->element_courant)->precedent = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}

/**
 * @brief ajoute un element string a gauche de l'element courant
 * 
 * @param liste 
 * @param val 
 */
static void ajout_gauche_string(t_liste * liste, void * val){
    t_element_liste_string * elt = (t_element_liste_string *)malloc(sizeof(t_element_liste_string));
    elt->val = (char *)val;
    if(!liste_vide(liste)){
        elt->suivant = liste->element_courant;
        elt->precedent = ((t_element_liste_string *)liste->element_courant)->precedent;
        if(((t_element_liste_string *)liste->element_courant)->precedent != NULL){
            ((t_element_liste_string *)liste->element_courant)->precedent->suivant = elt;
        }else{
            liste->debut_liste = elt;
        }
        ((t_element_liste_string *)liste->element_courant)->precedent = elt;
    }
    else{
        liste->debut_liste = elt;
        liste->fin_liste = elt;
        elt->precedent = NULL;
        elt->suivant = NULL;
    }
}
