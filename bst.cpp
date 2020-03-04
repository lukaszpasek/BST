#include "bst.h"

bst::bst()
{
    korzen= 0;
}

bst::~bst()
{
}

bool bst::doloz_it( double co )
{
    if( korzen== 0 )
    {
        korzen= new element;
        korzen->kl= co;
        korzen->lewe= korzen->prawe= 0;
        return true;
    }
    element *p, *q;
    p= korzen;
    while( p!= 0 )
    {
        if( co== p->kl )
            return false;
        q= p;
        if( co< p->kl )
            p= p->lewe;
        else// co> p->kl
            p= p->prawe;
    }
    p= new element;
    p->kl= co;
    p->lewe= p->prawe= 0;
    if( co< q->kl )
        q->lewe= p;
    else
        q->prawe= p;
    return true;
}

bool bst::doloz( double co )
{
    return _doloz( co, korzen );
}

bool bst::_doloz( double co, element * & k )
{
    if( k== 0 )
    {
        k= new element;
        k->kl= co;
        k->lewe= k->prawe= 0;
        return true;
    }
    if( co== k->kl )
        return false;
    if( co< k->kl )
        return _doloz( co, k->lewe );
    //else co> k->kl
        return _doloz( co, k->prawe );
}

bool bst::usun( double co )
{
    return _usun( co, korzen );
}

bool bst::_usun( double co, element *&k )
{
    if( k== 0 )
        return false;
    if( co< k->kl )
        return _usun( co, k->lewe );
    else if( co> k->kl )
        return _usun( co, k->prawe );
    /* k->kl== co */
    if( k->lewe== 0&& k->prawe== 0 )// lisc
    {
        delete k;
        k= 0;
        return true;
    }
    if( k->lewe== 0 )// jedno dziecko
    {
        element *p= k;
        k= k->prawe;
        delete p;
        return true;
    }
    if( k->prawe== 0 )// jedno dziecko
    {
        element *p= k;
        k= k->lewe;
        delete p;
        return true;
    }
    /* dwoje dzieci */
    element *p, *q;
    p= k->lewe;
    q= 0;
    while( p->prawe!= 0 )
    {
        q= p;
        p= p->prawe;
    }
    if( q!= 0 )
    {
        q->prawe= p->lewe;
        p->lewe= k->lewe;
    }
    p->prawe= k->prawe;
    delete k;
    k= p;
    return true;
}

bool bst::jest( double co ) const
{

}

bool bst::czy_puste() const
{

}

ostream& operator<<( ostream &out, const bst &org )
{
    out<<"vvvvvvvvvvvv"<< endl;
    org._drukuj( out, org.korzen, 0, 0 );
    out<<"^^^^^^^^^^^^"<< endl;
    return out;
}

/*
void bst::_drukuj( ostream &out, element *k, int gl ) const
{
    for( int i= 0; i< gl; i++ )
        out<<"  ";
    if( k== 0 )
    {
        out<<'X'<< endl;
        return;
    }
    out<< k->kl<< endl;
    if( k->lewe!= 0|| k->prawe!= 0 )
    {
        _drukuj( out, k->lewe, gl+ 1 );
        _drukuj( out, k->prawe, gl+ 1 );
    }
}
*/

void bst::_drukuj( ostream &out, element *k, int gl, int z ) const
{
    if( k== 0 )
        return;
    for( int i= 0; i< gl; i++ )
        out<<"  ";
    switch( z )
    {
    case -1:
        out<<'<';
        break;
    case 0:
        break;
    case 1:
        out<<'>';
        break;
    }
    out<< k->kl<< endl;
    _drukuj( out, k->lewe, gl+ 1, -1 );
    _drukuj( out, k->prawe, gl+ 1, 1 );
}





