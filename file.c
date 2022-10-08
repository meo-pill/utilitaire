/**
 * @file file.c
 * @author meo (meo.prn@outlook.fr)
 * @brief primitive des fonction de la file
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "file.h"

/**
 * @brief creer une file vide en fonction du type
 * 
 * @return t_file* 
 */
extern t_file * creer_file(t_type_file type){
	t_file * file = (t_file *) malloc(sizeof(t_file));
	file->type = type;
	file->premier = NULL;
	file->dernier = NULL;
	switch (type){
		case FILE_INT:
			file->enfiler = enfiler_int;
			file->defiler = defiler_int;
			break;
		case FILE_CHAR:
			file->enfiler = enfiler_char;
			file->defiler = defiler_char;
			break;
		case FILE_FLOAT:
			file->enfiler = enfiler_float;
			file->defiler = defiler_float;
			break;
		case FILE_DOUBLE:
			file->enfiler = enfiler_double;
			file->defiler = defiler_double;
			break;
		case FILE_LONG:
			file->enfiler = enfiler_long;
			file->defiler = defiler_long;
			break;
		case FILE_BOOL: 
			file->enfiler = enfiler_bool;
			file->defiler = defiler_bool;
			break;
		case FILE_STRING:
			file->enfiler = enfiler_string;
			file->defiler = defiler_string;
			break;
		default:
			break;
	}
	return file;
}

/**
 * @brief verifier si la file est vide
 * 
 * @param file 
 * @return true 
 * @return false 
 */
extern bool est_vide_file(t_file * file){
	return file->premier == NULL && file->dernier == NULL;
}

/**
 * @brief ajouter un element a la file
 * 
 * @param file 
 * @param val 
 */
extern void enfiler(t_file * file, void * val){
	file->enfiler(file, val);
}

/**
 * @brief extrai un element de la file
 * 
 * @param file 
 * @return void* 
 */
extern void defiler(t_file * file,void * val){
	file->defiler(file, val);
}





/**
 * @brief ajouter un int a la file
 * 
 * @param file 
 * @param val 
 */
static void enfiler_int(t_file * file, void * val){
	t_element_file_int * element = (t_element_file_int *) malloc(sizeof(t_element_file_int));
	element->val = *((int *) val);
	element->suivant = NULL;
	if(est_vide_file(file)){
		file->premier = element;
		file->dernier = element;
	}
	else{
		((t_element_file_int *)file->dernier)->suivant = element;
		file->dernier = element;
	}
}

/**
 * @brief ajouter un char a la file
 * 
 * @param file 
 * @param val 
 */
static void enfiler_char(t_file * file, void * val){
	t_element_file_char * element = (t_element_file_char *) malloc(sizeof(t_element_file_char));
	element->val = *((char *) val);
	element->suivant = NULL;
	if(est_vide_file(file)){
		file->premier = element;
		file->dernier = element;
	}
	else{
		((t_element_file_char *)file->dernier)->suivant = element;
		file->dernier = element;
	}
}

/**
 * @brief ajouter un float a la file
 * 
 * @param file 
 * @param val 
 */
static void enfiler_float(t_file * file, void * val){
	t_element_file_float * element = (t_element_file_float *) malloc(sizeof(t_element_file_float));
	element->val = *((float *) val);
	element->suivant = NULL;
	if(est_vide_file(file)){
		file->premier = element;
		file->dernier = element;
	}
	else{
		((t_element_file_float *)file->dernier)->suivant = element;
		file->dernier = element;
	}
}

/**
 * @brief ajouter un double a la file
 * 
 * @param file 
 * @param val 
 */
static void enfiler_double(t_file * file, void * val){
	t_element_file_double * element = (t_element_file_double *) malloc(sizeof(t_element_file_double));
	element->val = *((double *) val);
	element->suivant = NULL;
	if(est_vide_file(file)){
		file->premier = element;
		file->dernier = element;
	}
	else{
		((t_element_file_double *)file->dernier)->suivant = element;
		file->dernier = element;
	}
}

/**
 * @brief ajouter un long a la file
 * 
 * @param file 
 * @param val 
 */
static void enfiler_long(t_file * file, void * val){
	t_element_file_long * element = (t_element_file_long *) malloc(sizeof(t_element_file_long));
	element->val = *((long *) val);
	element->suivant = NULL;
	if(est_vide_file(file)){
		file->premier = element;
		file->dernier = element;
	}
	else{
		((t_element_file_long *)file->dernier)->suivant = element;
		file->dernier = element;
	}
}

/**
 * @brief ajouter un bool a la file
 * 
 * @param file 
 * @param val 
 */
static void enfiler_bool(t_file * file, void * val){
	t_element_file_bool * element = (t_element_file_bool *) malloc(sizeof(t_element_file_bool));
	element->val = *((bool *) val);
	element->suivant = NULL;
	if(est_vide_file(file)){
		file->premier = element;
		file->dernier = element;
	}
	else{
		((t_element_file_bool *)file->dernier)->suivant = element;
		file->dernier = element;
	}
}

/**
 * @brief ajouter un string a la file
 * 
 * @param file 
 * @param val 
 */
static void enfiler_string(t_file * file, void * val){
	t_element_file_string * element = (t_element_file_string *) malloc(sizeof(t_element_file_string));
	element->val = (char *) val;
	element->suivant = NULL;
	if(est_vide_file(file)){
		file->premier = element;
		file->dernier = element;
	}
	else{
		((t_element_file_string *)file->dernier)->suivant = element;
		file->dernier = element;
	}
}





/**
 * @brief retirée un int de la file
 * 
 * @param file 
 * @param val 
 */
static void defiler_int(t_file * file, void * val){
	if(est_vide_file(file)){
		printf("Erreur : la file des int est vide");
		return;
	}
	t_element_file_int * element = (t_element_file_int *) file->premier;
	*((int *) val) = element->val;
	file->premier = element->suivant;
	if(file->premier == NULL){
		file->dernier = NULL;
	}
	free(element);
}

/**
 * @brief retirée un char de la file
 * 
 * @param file 
 * @param val 
 */
static void defiler_char(t_file * file, void * val){
	if(est_vide_file(file)){
		printf("Erreur : la file des char est vide");
		return;
	}
	t_element_file_char * element = (t_element_file_char *) file->premier;
	*((char *) val) = element->val;
	file->premier = element->suivant;
	if(file->premier == NULL){
		file->dernier = NULL;
	}
	free(element);
}

/**
 * @brief retirée un float de la file
 * 
 * @param file 
 * @param val 
 */
static void defiler_float(t_file * file, void * val){
	if(est_vide_file(file)){
		printf("Erreur : la file des float est vide");
		return;
	}
	t_element_file_float * element = (t_element_file_float *) file->premier;
	*((float *) val) = element->val;
	file->premier = element->suivant;
	if(file->premier == NULL){
		file->dernier = NULL;
	}
	free(element);
}

/**
 * @brief retirée un double de la file
 * 
 * @param file 
 * @param val 
 */
static void defiler_double(t_file * file, void * val){
	if(est_vide_file(file)){
		printf("Erreur : la file des double est vide");
		return;
	}
	t_element_file_double * element = (t_element_file_double *) file->premier;
	*((double *) val) = element->val;
	file->premier = element->suivant;
	if(file->premier == NULL){
		file->dernier = NULL;
	}
	free(element);
}

/**
 * @brief retirée un long de la file
 * 
 * @param file 
 * @param val 
 */
static void defiler_long(t_file * file, void * val){
	if(est_vide_file(file)){
		printf("Erreur : la file des long est vide");
		return;
	}
	t_element_file_long * element = (t_element_file_long *) file->premier;
	*((long *) val) = element->val;
	file->premier = element->suivant;
	if(file->premier == NULL){
		file->dernier = NULL;
	}
	free(element);
}

/**
 * @brief retirée un bool de la file
 * 
 * @param file 
 * @param val 
 */
static void defiler_bool(t_file * file, void * val){
	if(est_vide_file(file)){
		printf("Erreur : la file des bool est vide");
		return;
	}
	t_element_file_bool * element = (t_element_file_bool *) file->premier;
	*((bool *) val) = element->val;
	file->premier = element->suivant;
	if(file->premier == NULL){
		file->dernier = NULL;
	}
	free(element);
}

/**
 * @brief retirée un string de la file
 * 
 * @param file 
 * @param val 
 */
static void defiler_string(t_file * file, void * val){
	if(est_vide_file(file)){
		printf("Erreur : la file des string est vide");
		return;
	}
	t_element_file_string * element = (t_element_file_string *) file->premier;
	*((char **) val) = element->val;
	file->premier = element->suivant;
	if(file->premier == NULL){
		file->dernier = NULL;
	}
	free(element);
}