/* 
 * File:   Couleur.h
 * Author: a
 *
 * Created on 7 mai 2015, 13:52
 */

#ifndef COULEUR_H
#define	COULEUR_H

namespace mia {
struct Couleur
{
    short rouge, vert, bleu, opacite;

    /// Constructor :
    ///--------------
    inline Couleur() {
        rouge= 0;
        vert= 0;
        vert= 0;
        opacite= 255;
    };
    inline Couleur(short r, short g, short b, short a= 255) {
        rouge= r & 0x00FF;
        vert= g & 0x00FF;
        bleu= b & 0x00FF;
        opacite= a & 0x00FF;
    };

    inline Couleur(int i) {
        rouge= short(( i & 0xFF000000 ) >> 24 );
        vert= short(( i & 0x00FF0000 ) >> 16 );
        bleu= short(( i & 0x0000FF00 ) >> 8 );
        opacite= short( i & 0x000000FF );
    };

    /// Asignement :
    ///-------------
    inline Couleur &operator=(const Couleur &c)
    {
        rouge= c.rouge;
        vert= c.vert;
        bleu= c.bleu;
        opacite= c.opacite;
        return (*this);
    }
    inline Couleur &operator=(const int &i)
    {
        rouge= short(( i & 0xFF000000 ) >> 24 );
        vert= short(( i & 0x00FF0000 ) >> 16 );
        bleu= short(( i & 0x0000FF00 ) >> 8 );
        opacite= short( i & 0x000000FF );
        return (*this);
    }

    /// Comparaison :
    ///--------------
    inline bool operator==(const Couleur &c)const {
        return ( rouge == c.rouge && vert == c.vert && bleu == c.bleu && opacite == c.opacite );
    }
};

};


#endif	/* COULEUR_H */

