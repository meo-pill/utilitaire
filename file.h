/**
 * @file file.h
 * @author meo (meo.prn@outlook.fr)
 * @brief fichier de mise en oeuvre de la File
 * @version 0.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element_file_int{
    int val;
    struct element_file_int *suivant;
} t_element_file_int;

typedef struct element_file_char{
    char val;
    struct element_file_char *suivant;
} t_element_file_char;

typedef struct element_file_float{
    float val;
    struct element_file_float *suivant;
} t_element_file_float;

typedef struct element_file_double{
    double val;
    struct element_file_double *suivant;
} t_element_file_double;

typedef struct element_file_long{
    long val;
    struct element_file_long *suivant;
} t_element_file_long;

typedef struct element_file_bool{
    bool val;
    struct element_file_bool *suivant;
} t_element_file_bool;

typedef struct element_file_string{
    char *val;
    struct element_file_string *suivant;
} t_element_file_string;

typedef enum type_file{
    FILE_INT,
    FILE_CHAR,
    FILE_FLOAT,
    FILE_DOUBLE,
    FILE_LONG,
    FILE_BOOL,
    FILE_STRING
} t_type_file;

typedef struct file{
    void * premier;
    void * dernier;
    t_type_file type;
    void (*enfiler)(struct file *, void *);
    void (*defiler)(struct file *, void *);
} t_file;

extern t_file * creer_file(t_type_file type);
extern bool est_vide(t_file * file);

extern void enfiler(t_file * file, void * val);
extern void defiler(t_file * file, void * val);





static void enfiler_int(t_file * file, void * val);
static void enfiler_char(t_file * file, void * val);
static void enfiler_float(t_file * file, void * val);
static void enfiler_double(t_file * file, void * val);
static void enfiler_long(t_file * file, void * val);
static void enfiler_bool(t_file * file, void * val);
static void enfiler_string(t_file * file, void * val);

static void defiler_int(t_file * file, void * val);
static void defiler_char(t_file * file, void * val);
static void defiler_float(t_file * file, void * val);
static void defiler_double(t_file * file, void * val);
static void defiler_long(t_file * file, void * val);
static void defiler_bool(t_file * file, void * val);
static void defiler_string(t_file * file, void * val);

#endif