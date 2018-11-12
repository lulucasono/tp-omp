#ifndef MAIN_H
#define MAIN_H

/**
 * Affichage des termes d'un vecteur
 */
void display(int *vec, int length);

/**
 * Somme des termes d'un vecteur
 */
long sum(int *vec, int length);

/**
 * Somme de deux vecteurs, le vecteur ret doit être initialise pour recevoir le resultat
 */
void add(int *vec1, int *vec2, int *ret, int length);

/**
 * Somme de deux vecteurs, le vecteur ret doit être initialise pour recevoir le resultat
 */
void paraAdd(const int *vec1, const int *vec2, int *ret, const int length);
bool cpVec(const int *v1, const int *v2, const int length);

#endif // MAIN_H
