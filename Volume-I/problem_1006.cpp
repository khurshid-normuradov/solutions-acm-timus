#include <stdio.h>
#include <iostream>
#include<string.h>
#include<vector>



#define LU 218
#define LD 192
#define RU 191
#define RD 217
#define HR 196
#define VR 179
#define DT 46
#define AN 100





unsigned char ts[20][51];
int xs[2000],ys[2000],as[2000], ds[2000];
int cn = 0;
	

/**
 *read()
 */
void read()
{
    int i;
    for (i = 0 ; i < 20; i++)std::cin >> ts[i];
}
	
/**
*print
*/
void print(){
int i,j;

printf("%d\n",cn);

for ( i = cn-1; i >= 0; i--){
	printf("%d %d %d\n", xs[i], ys[i], as[i]);
	
}
}	

/**
*check()
*/	
bool check(int x, int y, int a)
{
	int i;
	bool OK ;
	if ( a < 2 )return false;
	if ( ( x < 0 ) || ( x + a > 50 ) ) return false;
	if ( ( y < 0 ) || ( y + a > 20 ) ) return false;
	
	if( ( ts[ y    ][ x ]!= LU && ts[ y   ][ x ]!= AN) || ( ts[ y    ][ x+a-1 ]!= RU && ts[ y    ][ x+a-1 ]!= AN) ||
	    ( ts[ y+a-1][ x ]!= LD && ts[y+a-1][ x ]!= AN) || ( ts[ y+a-1][ x+a-1 ]!= RD && ts[ y+a-1][ x+a-1 ]!= AN)) return false;
	
	for (i = 1; i < a - 1;i++){
		if (ts[ y     ][ x+i   ] != HR && ts[ y     ][ x+i   ] != AN ) return false;
		if (ts[ y+a-1 ][ x+i   ] != HR && ts[ y+a-1 ][ x+i   ] != AN ) return false;
		if (ts[ y+i   ][ x     ] != VR && ts[ y+i   ][ x     ] != AN ) return false;
		if (ts[ y+i   ][ x+a-1 ] != VR && ts[ y+i   ][ x+a-1 ] != AN ) return false;
	}    
	OK = ( ts[ y ][ x ] == LU )|| ( ts[ y ][ x+a-1 ] == RU ) || ( ts[ y + a - 1 ][ x ] == LD ) || ( ts[ y + a - 1 ][ x + a - 1 ] == RD);
	for (i = 1; i < a - 1;i++){
		OK = OK || ( ts[ y ][ x + i ] == HR ) || ( ts[ y + a - 1 ][ x + i ] == HR ) || 
		           ( ts[ y + i ][ x ] == VR ) || ( ts[ y + i ][ x + a - 1 ] == VR ) ; 
	}
	
	return OK;
}	



void exchange( int x, int y, int a )
{
	int i;
	for (i = 0; i < a;i++){
		ts[ y         ][ x + i     ] = AN ;
		ts[ y + a - 1 ][ x + i     ] = AN ;
		ts[ y + i     ][ x         ] = AN ;
		ts[ y + i     ][ x + a - 1 ] = AN ;
	}
}





void solve(int depth)
{
	bool OK = false;
	int i,j,a, ki,kj,k;
	for ( i = 0; i< 20;  i++)
	{
		
	
		for ( j = 0; j < 50; j++)
		{
			ki = 20 - i;
			kj = 50 - j;
			k = (ki< kj) ? ki : kj;
			for ( a = k; a >= 2 ; a--)
			{
				if ( check( j, i, a ) ) 
				{
					OK = true;
					ys[ cn ] = i;
					xs[ cn ] = j;
					as[ cn ] = a;
					ds[ cn ] = depth;
					cn++;
					exchange(j, i, a);
					break ;
	 			}
			}
			//if (OK) break;
		}
	 	if(OK)break;	
	 }	
	if (OK)solve(1+depth);		
}


int main()
{

	read();
	solve(0);
	print();

}
