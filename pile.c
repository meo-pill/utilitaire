/**
 * @file pile.c
 * @author meo (meo.prn@outlook.fr)
 * @brief primitive des fonction de la pile
 * @version 0.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "pile.h"

/**
 * @brief creer une pile en fonction de son type
 * 
 * @return pile_t* 
 */
extern t_pile *creer_pile(t_type_pile type){
    t_pile *pile = (t_pile *)malloc(sizeof(t_pile));
    if (pile == NULL)
    {
        printf("Erreur d'allocation de la pile");
        exit(EXIT_FAILURE);
    }

    pile->type = type;
    pile->taille = 0;
    pile->haut_pile = NULL;

    switch (type){
        case PILE_INT:
            pile->empiler = empiler_int;
            pile->depiler = depiler_int;
            pile->peek = peek_int;
            break;
        case PILE_CHAR:
            pile->empiler = empiler_char;
            pile->depiler = depiler_char;
            pile->peek = peek_char;
            break;
        case PILE_FLOAT:
            pile->empiler = empiler_float;
            pile->depiler = depiler_float;
            pile->peek = peek_float;
            break;
        case PILE_DOUBLE:
            pile->empiler = empiler_double;
            pile->depiler = depiler_double;
            pile->peek = peek_double;
            break;
        case PILE_LONG:
            pile->empiler = empiler_long;
            pile->depiler = depiler_long;
            pile->peek = peek_long;
            break;
        case PILE_BOOL:
            pile->empiler = empiler_bool;
            pile->depiler = depiler_bool;
            pile->peek = peek_bool;
            break;
        case PILE_STRING:
            pile->empiler = empiler_string;
            pile->depiler = depiler_string;
            pile->peek = peek_string;
            break;
    }
    return pile;
}

extern bool pile_vide(t_pile *pile){
    return (pile->taille == 0 && pile->haut_pile == NULL);
}

/**
 * @brief empiler un element dans la pile donnée en parametre
 * 
 * @param pile 
 * @param element 
 */
extern void empiler(t_pile *pile, void *val){
    pile->empiler(pile, val);
}

/**
 * @brief depiler un element dans la pile donnée en parametre
 * 
 * @param pile 
 * @return void* 
 */
extern void depiler(t_pile *pile, void *val){
    pile->depiler(pile, val);
}

/**
 * @brief retourne le sommet de la pile
 * 
 * @param pile 
 * @return void* 
 */
extern void peek(t_pile *pile, void *val){
    pile->peek(pile, val);
}





/**
 * @brief empiler une valeur de type int dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void empiler_int(t_pile *pile, void *val){
    t_element_pile_int * element = malloc(sizeof(t_element_pile_int));
    element -> precedent = pile-> haut_pile;
    element -> val = *(int *)val;
    pile->haut_pile = element;
    pile->taille++;
}

/**
 * @brief empiler une valeur de type char dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void empiler_char(t_pile *pile, void *val){
    t_element_pile_char * element = malloc(sizeof(t_element_pile_char));
    element -> precedent = pile-> haut_pile;
    element -> val = *(char *)val;
    pile->haut_pile = element;
    pile->taille++;
}

/**
 * @brief empiler une valeur de type float dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void empiler_float(t_pile *pile, void *val){
    t_element_pile_float * element = malloc(sizeof(t_element_pile_float));
    element -> precedent = pile-> haut_pile;
    element -> val = *(float *)val;
    pile->haut_pile = element;
    pile->taille++;
}

/**
 * @brief empiler une valeur de type double dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void empiler_double(t_pile *pile, void *val){
    t_element_pile_double * element = malloc(sizeof(t_element_pile_double));
    element -> precedent = pile-> haut_pile;
    element -> val = *(double *)val;
    pile->haut_pile = element;
    pile->taille++;
}

/**
 * @brief empiler une valeur de type long dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void empiler_long(t_pile *pile, void *val){
    t_element_pile_long * element = malloc(sizeof(t_element_pile_long));
    element -> precedent = pile-> haut_pile;
    element -> val = *(long *)val;
    pile->haut_pile = element;
    pile->taille++;
}

/**
 * @brief empiler une valeur de type bool dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void empiler_bool(t_pile *pile, void *val){
    t_element_pile_bool * element = malloc(sizeof(t_element_pile_bool));
    element -> precedent = pile-> haut_pile;
    element -> val = *(bool *)val;
    pile->haut_pile = element;
    pile->taille++;
}

/**
 * @brief empiler une valeur de type string dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void empiler_string(t_pile *pile, void *val){
    t_element_pile_string * element = malloc(sizeof(t_element_pile_string));
    element -> precedent = pile-> haut_pile;
    element -> val = *(char **)val;
    pile->haut_pile = element;
    pile->taille++;
}





/**
 * @brief depiler une valeur de type int dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void depiler_int(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile int est vide");
        val = NULL;
        return;
    }
    t_element_pile_int * element = pile->haut_pile;
    *(int *)val = element->val;
    pile->haut_pile = element->precedent;
    free(element);
    pile->taille--;
}

/**
 * @brief depiler une valeur de type char dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void depiler_char(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile char est vide");
        val = NULL;
        return;
    }
    t_element_pile_char * element = pile->haut_pile;
    *(char *)val = element->val;
    pile->haut_pile = element->precedent;
    free(element);
    pile->taille--;
}

/**
 * @brief depiler une valeur de type float dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void depiler_float(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile float est vide");
        val = NULL;
        return;
    }
    t_element_pile_float * element = pile->haut_pile;
    *(float *)val = element->val;
    pile->haut_pile = element->precedent;
    free(element);
    pile->taille--;
}

/**
 * @brief depiler une valeur de type double dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void depiler_double(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile double est vide");
        val = NULL;
        return;
    }
    t_element_pile_double * element = pile->haut_pile;
    *(double *)val = element->val;
    pile->haut_pile = element->precedent;
    free(element);
    pile->taille--;
}

/**
 * @brief depiler une valeur de type long dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void depiler_long(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile long est vide");
        val = NULL;
        return;
    }
    t_element_pile_long * element = pile->haut_pile;
    *(long *)val = element->val;
    pile->haut_pile = element->precedent;
    free(element);
    pile->taille--;
}

/**
 * @brief depiler une valeur de type bool dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void depiler_bool(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile bool est vide");
        val = NULL;
        return;
    }
    t_element_pile_bool * element = pile->haut_pile;
    *(bool *)val = element->val;
    pile->haut_pile = element->precedent;
    free(element);
    pile->taille--;
}

/**
 * @brief depiler une valeur de type string dans la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void depiler_string(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile string est vide");
        val = NULL;
        return;
    }
    t_element_pile_string * element = pile->haut_pile;
    *(char **)val = element->val;
    pile->haut_pile = element->precedent;
    free(element);
    pile->taille--;
}





/**
 * @brief regarde la valeur de type int au sommet de la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void peek_int(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile int est vide");
        val = NULL;
        return;
    }
    *(int *)val = ((t_element_pile_int *)pile->haut_pile)->val;
}

/**
 * @brief regarde la valeur de type char au sommet de la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void peek_char(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile char est vide");
        val = NULL;
        return;
    }
    *(char *)val = ((t_element_pile_char *)pile->haut_pile)->val;
}

/**
 * @brief regarde la valeur de type float au sommet de la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void peek_float(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile float est vide");
        val = NULL;
        return;
    }
    *(float *)val = ((t_element_pile_float *)pile->haut_pile)->val;
}

/**
 * @brief regarde la valeur de type double au sommet de la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void peek_double(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile double est vide");
        val = NULL;
        return;
    }
    *(double *)val = ((t_element_pile_double *)pile->haut_pile)->val;
}

/**
 * @brief regarde la valeur de type long au sommet de la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void peek_long(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile long est vide");
        val = NULL;
        return;
    }
    *(long *)val = ((t_element_pile_long *)pile->haut_pile)->val;
}

/**
 * @brief regarde la valeur de type bool au sommet de la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void peek_bool(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile bool est vide");
        val = NULL;
        return;
    }
    *(bool *)val = ((t_element_pile_bool *)pile->haut_pile)->val;
}

/**
 * @brief regarde la valeur de type string au sommet de la pile donnée en parametre
 * 
 * @param pile 
 * @param val 
 */
static void peek_string(t_pile *pile, void *val){
    if(pile_vide(pile)){
        printf("Erreur : la pile string est vide");
        val = NULL;
        return;
    }
    *(char **)val = ((t_element_pile_string *)pile->haut_pile)->val;
}