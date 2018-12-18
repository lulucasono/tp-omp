#ifndef MAIN_H
#define MAIN_H

/**
 * Affichage des termes d'un vecteur
 */
void display(double *vec, int length);

/**
 * Somme des termes d'un vecteur
 */
double sum(double *vec, int length);
double paraSum(double * vec, int length);

/**
 * Somme de deux vecteurs, le vecteur ret doit être initialise pour recevoir le resultat
 */
void add(double *vec1, double *vec2, double *ret, int length);

/**
 * Somme de deux vecteurs, le vecteur ret doit être initialise pour recevoir le resultat
 */
void paraAdd(const double *vec1, const double *vec2, double *ret, const int length);
bool cpVec(const double *v1, const double *v2, const int length);

#endif // MAIN_H
