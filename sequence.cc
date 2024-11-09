#include "sequence.hh"
#include<iostream>

void sc_initialiservide(sequence & s){
    s.taille=0;
    s.capacite = 5;  // modif ajouté
    s.couleurs = new couleur[s.capacite];
}

/* avant la modification de la structure
void sc_ajouter(sequence &s, couleur c){
    couleur* newSeq = new couleur[s.taille+1];
    //copier les ancienne valeur de ma sequence dans newSeq
    for( indicesequence i=0; i<s.taille ; i++){
        newSeq[i]= s.couleurs[i];
    }

    //ajouter la dernier couleur
    newSeq[s.taille]=c;


    //supprimer l'ancienne sequence
    delete[] s.couleurs;

    //modifier la taille de la sequence et la sequence
    s.taille++;
    s.couleurs=newSeq;

}*/

void sc_ajouter(sequence &s, couleur c){
    if( s.taille ==s.capacite){
        s.capacite+=5;
        couleur* newSeq = new couleur[s.capacite];
        //copier les ancienne valeur de ma sequence dans newSeq
        for( indicesequence i=0; i<s.taille ; i++)
        {            newSeq[i]= s.couleurs[i];}

        //supprimer l'ancienne sequence et la remplacer par la nouvelle
        delete[] s.couleurs;
        s.couleurs=newSeq;
    }
    //ajoute de la couleur
    s.couleurs[s.taille] = c;
    s.taille++;
}


void sc_afficher(couleur c){
    switch (c) {
    case couleur::rouge :
            std::cout<<"rouge";
            break;
    case couleur::bleu :
        std::cout<<"bleu";
        break;
    case couleur::vert :
        std::cout<<"vert";
        break;
    case couleur::jaune :
        std::cout<<"jaune";
        break;
    default:
        std::cout<<"";
   }
}

void sc_afficher(sequence s){
    std::cout<<"taille : "<<s.taille<<"\n";
    std::cout<<"sequence : ";
    for(indicesequence i=0; i<s.taille; i++){
            sc_afficher(s.couleurs[i]);
            std::cout<<" ";
        }
    std::cout<<std::endl;
}

void sc_copier(sequence &b, const sequence & a){
    b.taille=a.taille;
    //suprimer la sequance de b
    delete[] b.couleurs;
    //remplacer la sequence de b par a
    couleur* newSeq = new couleur[a.taille];
    //copier les ancienne valeur de ma sequence dans newSeq
    for( indicesequence i=0; i<a.taille ; i++){
        newSeq[i]= a.couleurs[i];
    }
    b.couleurs =newSeq;


}

couleur sc_acces(sequence s, indicesequence i){
    return s.couleurs[i];
}

void sc_vider(sequence &s){
    s.taille=0;
    s.capacite = 5;  // Réinitialise la capacité à 5
    delete[] s.couleurs;
    s.couleurs=nullptr;
}

bool sc_comparer(const sequence &a, const sequence &b){
    if( a.taille==b.taille){
            for(indicesequence i=0; i<a.taille; i++){
                if( sc_acces(a,i) != sc_acces(b,i) ){
                    return false;
                }
            }
            return true;
        }
        return false;
}

sequence::~sequence(){
    delete[] _couleurs;
}


