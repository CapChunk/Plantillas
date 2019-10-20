#ifndef SEARCHER_H
#define SEARCHER_H
#include <iostream>
#include  <stdexcept>
#include "lista_estatica.h"
using namespace std;

class  Searcher
{
public:

    size_t sequential (ListaEstatica<10, int > &a, int &val)  ;
    size_t binary (ListaEstatica<10, int > &a, int &val)  ;
};

size_t Searcher :: sequential (ListaEstatica<10, int > &a, int &val)
{
    size_t i=0;
    while ( i  < a.size()  /*&&  a[i] != val */)
    {
        if (a[i] == val)
        {
            return i;
        }
        else
        {
             ++i;
        }
     }
                return a.size();
}

size_t Searcher ::binary (ListaEstatica<10, int > &a, int &val)
{
    size_t  l = 0, r;
   r = a.size();
   do {
       size_t m = (l+r)/2;

       if( val == a[m] )
       {
           return m;
       }
       else if ( val  < a[m]  )
       {
           r = m-1 ;
       }
       else
       {
            l = m+1;
       }
       return a.size();
   } while ( l <= r );
}


#endif // SEARCHER_H
