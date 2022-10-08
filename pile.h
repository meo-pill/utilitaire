/**
 * @file pile.h
 * @author meo (meo.prn@outlook.fr)
 * @brief fichier de mise en oeuvre de la Pile
 * @version 0.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct element_pile_int{
    int val;
    struct element_pile_int *precedent;
}t_element_pile_int;

typedef struct element_pile_char{
    char val;
    struct element_pile_char *precedent;
}t_element_pile_char;

typedef struct element_pile_float{
    float val;
    struct element_pile_float *precedent;
}t_element_pile_float;

typedef struct element_pile_double{
    double val;
    struct element_pile_double *precedent;
}t_element_pile_double;

typedef struct element_pile_long{
    long val;
    struct element_pile_long *precedent;
}t_element_pile_long;

typedef struct element_pile_bool{
    bool val;
    struct element_pile_bool *precedent;
}t_element_pile_bool;

typedef struct element_pile_string{
    char *val;
    struct element_pile_string *precedent;
}t_element_pile_string;

typedef enum type_pile{
    PILE_INT,
    PILE_CHAR,
    PILE_FLOAT,
    PILE_DOUBLE,
    PILE_LONG,
    PILE_BOOL,
    PILE_STRING
}t_type_pile;

typedef struct pile{
    void * haut_pile;
    t_type_pile type;
    int taille;
    void (*empiler)(struct pile *, void *);
    void (*depiler)(struct pile *, void *);
    void (*peek)(struct pile *, void *);
}t_pile;

extern t_pile *creer_pile(t_type_pile type);
extern bool pile_vide(t_pile *pile);

extern void empiler(t_pile *pile, void *val);
extern void depiler(t_pile *pile, void *val);
extern void peek(t_pile *pile, void *val);





static void empiler_int(t_pile *pile, void *val);
static void empiler_char(t_pile *pile, void *val);
static void empiler_float(t_pile *pile, void *val);
static void empiler_double(t_pile *pile, void *val);
static void empiler_long(t_pile *pile, void *val);
static void empiler_bool(t_pile *pile, void *val);
static void empiler_string(t_pile *pile, void *val);

static void depiler_int(t_pile *pile, void *val);
static void depiler_char(t_pile *pile, void *val);
static void depiler_float(t_pile *pile, void *val);
static void depiler_double(t_pile *pile, void *val);
static void depiler_long(t_pile *pile, void *val);
static void depiler_bool(t_pile *pile, void *val);
static void depiler_string(t_pile *pile, void *val);

static void peek_int(t_pile *pile, void *val);
static void peek_char(t_pile *pile, void *val);
static void peek_float(t_pile *pile, void *val);
static void peek_double(t_pile *pile, void *val);
static void peek_long(t_pile *pile, void *val);
static void peek_bool(t_pile *pile, void *val);
static void peek_string(t_pile *pile, void *val);

#endif