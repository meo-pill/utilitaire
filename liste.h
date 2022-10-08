/**
 * @file liste.h
 * @author meo (meo.prn@outlook.fr)
 * @brief fichier de mise en oeuvre de la liste
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element_liste_int{
    int val;
    struct element_liste_int *suivant;
    struct element_liste_int *precedent;
}t_element_liste_int;

typedef struct element_liste_char{
    char val;
    struct element_liste_char *suivant;
    struct element_liste_char *precedent;
}t_element_liste_char;

typedef struct element_liste_float{
    float val;
    struct element_liste_float *suivant;
    struct element_liste_float *precedent;
}t_element_liste_float;

typedef struct element_liste_double{
    double val;
    struct element_liste_double *suivant;
    struct element_liste_double *precedent;
}t_element_liste_double;

typedef struct element_liste_long{
    long val;
    struct element_liste_long *suivant;
    struct element_liste_long *precedent;
}t_element_liste_long;

typedef struct element_liste_bool{
    bool val;
    struct element_liste_bool *suivant;
    struct element_liste_bool *precedent;
}t_element_liste_bool;

typedef struct element_liste_string{
    char *val;
    struct element_liste_string *suivant;
    struct element_liste_string *precedent;
}t_element_liste_string;

typedef enum type_liste{
    LISTE_INT,
    LISTE_CHAR,
    LISTE_FLOAT,
    LISTE_DOUBLE,
    LISTE_LONG,
    LISTE_BOOL,
    LISTE_STRING
}t_type_liste;

typedef union type_liste_union{
    t_element_liste_int *liste_int;
    t_element_liste_char *liste_char;
    t_element_liste_float *liste_float;
    t_element_liste_double *liste_double;
    t_element_liste_long *liste_long;
    t_element_liste_bool *liste_bool;
    t_element_liste_string *liste_string;
}t_type_liste_union;

typedef struct liste{
    void * debut_liste;
    void * fin_liste;
    void * element_courant;
    void (*precedent)(struct liste *);
    void (*suivant)(struct liste *);
    void (*valeur_elt)(struct liste *, void *);
    void (*modif_elt)(struct liste *, void *);
    void (*oter_elt)(struct liste *);
    void (*ajout_droit)(struct liste *, void *);
    void (*ajout_gauche)(struct liste *, void *);
    t_type_liste type;
}t_liste;

extern t_liste * creer_liste(t_type_liste type);
extern bool liste_vide(t_liste * liste);
extern bool hors_liste(t_liste * liste);
extern void en_tete(t_liste * liste);
extern void en_queue(t_liste * liste);

extern void precedent(t_liste * liste);
extern void suivant(t_liste * liste);
extern void valeur_elt(t_liste * liste, void * val);
extern void modif_elt(t_liste * liste, void * val);
extern void oter_elt(t_liste * liste);
extern void ajout_droit(t_liste * liste, void * val);
extern void ajout_gauche(t_liste * liste, void * val);





static void precedent_int(t_liste * liste);
static void precedent_char(t_liste * liste);
static void precedent_float(t_liste * liste);
static void precedent_double(t_liste * liste);
static void precedent_long(t_liste * liste);
static void precedent_bool(t_liste * liste);
static void precedent_string(t_liste * liste);

static void suivant_int(t_liste * liste);
static void suivant_char(t_liste * liste);
static void suivant_float(t_liste * liste);
static void suivant_double(t_liste * liste);
static void suivant_long(t_liste * liste);
static void suivant_bool(t_liste * liste);
static void suivant_string(t_liste * liste);

static void valeur_elt_int(t_liste * liste, void * val);
static void valeur_elt_char(t_liste * liste, void * val);
static void valeur_elt_float(t_liste * liste, void * val);
static void valeur_elt_double(t_liste * liste, void * val);
static void valeur_elt_long(t_liste * liste, void * val);
static void valeur_elt_bool(t_liste * liste, void * val);
static void valeur_elt_string(t_liste * liste, void * val);

static void modif_elt_int(t_liste * liste, void * val);
static void modif_elt_char(t_liste * liste, void * val);
static void modif_elt_float(t_liste * liste, void * val);
static void modif_elt_double(t_liste * liste, void * val);
static void modif_elt_long(t_liste * liste, void * val);
static void modif_elt_bool(t_liste * liste, void * val);
static void modif_elt_string(t_liste * liste, void * val);

static void oter_elt_int(t_liste * liste);
static void oter_elt_char(t_liste * liste);
static void oter_elt_float(t_liste * liste);
static void oter_elt_double(t_liste * liste);
static void oter_elt_long(t_liste * liste);
static void oter_elt_bool(t_liste * liste);
static void oter_elt_string(t_liste * liste);

static void ajout_droit_int(t_liste * liste, void * val);
static void ajout_droit_char(t_liste * liste, void * val);
static void ajout_droit_float(t_liste * liste, void * val);
static void ajout_droit_double(t_liste * liste, void * val);
static void ajout_droit_long(t_liste * liste, void * val);
static void ajout_droit_bool(t_liste * liste, void * val);
static void ajout_droit_string(t_liste * liste, void * val);

static void ajout_gauche_int(t_liste * liste, void * val);
static void ajout_gauche_char(t_liste * liste, void * val);
static void ajout_gauche_float(t_liste * liste, void * val);
static void ajout_gauche_double(t_liste * liste, void * val);
static void ajout_gauche_long(t_liste * liste, void * val);
static void ajout_gauche_bool(t_liste * liste, void * val);
static void ajout_gauche_string(t_liste * liste, void * val);

#endif