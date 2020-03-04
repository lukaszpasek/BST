#ifndef bst_H
#define bst_H

#include<stdlib.h>
#include<iostream>
using namespace std;


class bst
{
public:
    bst();
    ~bst();
    bool doloz_it( double co );
    bool doloz( double co );
    bool usun( double co );
    bool jest( double co ) const;
    bool czy_puste() const;
    friend ostream& operator<<( ostream &out, const bst &org );
private:
    class element
    {
    public:
        double kl;
        element *lewe, *prawe;
    } *korzen;
    bool _doloz( double co, element *&k );
    bool _usun( double co, element *&k );
    //void _drukuj( ostream &out, element *k, int glebokosc ) const;
    void _drukuj( ostream &out, element *k, int glebokosc, int znacznik ) const;
};

#endif // bst_H
