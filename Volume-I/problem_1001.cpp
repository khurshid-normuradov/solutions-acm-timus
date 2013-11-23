/**
*
* @author: Khurshid.Normuradov
* @file  : problem_1001.cpp
* @remark: There is a solution of 1001-th problem.
*/



#include <cstdio>
#include <cmath>

int main()
{
   // maximum number of elements
    const int max_size = 1 << 18; // 2 ^ 18 = 262144
    
    // dynamic array
    double * massiv = new double[ max_size ] ;
    
    // current size
    int size = 0;
    
    // numbers represented as integral.
    long long x;
    
    // read numbers from file, and add square roots to massiv.
    while ( scanf("%lld",&x) == 1 ) {
        massiv[ size ++ ] = sqrt( x + .0 );
    }
   
   
   //print square roots with reverse order.
    while ( size --> 0 ) {
        printf("%.4lf\n", massiv[size] ) ;
    }
    
    
    // release dynamic array
    delete [] massiv;
    
    return 0;
}
