#pragma once
#include<iostream>

enum class couleur{
    rouge,
    bleu,
    jaune,
    vert
};

using indicesequence = std::size_t;
struct sequence {
    couleur * couleurs;
    indicesequence taille;
    indicesequence capacite;  //modif ajouté

};


void sc_initialiservide(sequence & s);
void sc_ajouter(sequence &s, couleur c);
void sc_afficher(sequence s);
void sc_copier(sequence &b, const sequence & a);
void sc_afficher(couleur s);
couleur sc_acces(sequence s, indicesequence i);
void sc_vider(sequence &s);
bool sc_comparer(const sequence &a, const sequence &b);
