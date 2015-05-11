#ifndef MIA_COLOR_H
#define MIA_COLOR_H

//#include <iostream>

namespace mia {
struct Color
{
    short red, green, blue, alfa;

    /// Constructor :
    ///--------------
    inline Color() {
        red= 0;
        green= 0;
        green= 0;
        alfa= 255;
    };
    inline Color(short r, short g, short b, short a= 255) {
        red= r & 0x00FF;
        green= g & 0x00FF;
        blue= b & 0x00FF;
        alfa= a & 0x00FF;
    };

    inline Color(int i) {
        red= short(( i & 0xFF000000 ) >> 24 );
        green= short(( i & 0x00FF0000 ) >> 16 );
        blue= short(( i & 0x0000FF00 ) >> 8 );
        alfa= short( i & 0x000000FF );
    };

    /// Asignement :
    ///-------------
    inline Color &operator=(const Color &c)
    {
        red= c.red;
        green= c.green;
        blue= c.blue;
        alfa= c.alfa;
        return (*this);
    }
    inline Color &operator=(const int &i)
    {
        red= short(( i & 0xFF000000 ) >> 24 );
        green= short(( i & 0x00FF0000 ) >> 16 );
        blue= short(( i & 0x0000FF00 ) >> 8 );
        alfa= short( i & 0x000000FF );
        return (*this);
    }

    /// Comparaison :
    ///--------------
    inline bool operator==(const Color &c)const {
        return ( red == c.red && green == c.green && blue == c.blue && alfa == c.alfa );
    }
};

};

#endif // COLOR_H
