#include <iostream>

int abs( int x ) { return x > 0 ? x : -x; }
int min(int x, int y) { return x >y ? y : x ; }

int calc(  int i , int n, int left, int right, int w[ ] ) // w[n] - хато беради :))
{
     if ( i == n ) return abs( left - right);
     int left_side = calc( i + 1, n , left + w[i], right, w );
     int right_side = calc( i + 1, n , left,  right + w[i] ,  w);

    return min( left_side, right_side);
} 


int main()
{
      int w[20];
      int n;
   
      std::cin >> n;
      for(int i = 0; i < n; i++) std::cin >> w[i];

     // бошлангич холда,  i = 0 , left = 0, right = 0  булади.
    std::cout << calc( 0, n, 0, 0, w ) << std::endl;

   return 0;
}
