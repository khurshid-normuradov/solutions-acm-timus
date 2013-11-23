#include <stdio.h>
#include <stdlib.h>


#define MAXN 5000
typedef int bool;
#define true 1
#define false 0


#define MAX_BUFFER_SIZE  1048576
char buffer  [ MAX_BUFFER_SIZE ] ;
int  nBuffer			 ;
int iBuffer				 ;
int getInt()
{
	int result = 0;
	bool negative  = false;
	while (buffer[iBuffer] <= ' ' ) iBuffer ++ ;
	

	if (buffer[iBuffer] == '-')
	{
		negative = true;
		iBuffer++ ;
		while (buffer[iBuffer] <= ' ') iBuffer ++ ;
	}
	else if (buffer[iBuffer] == '+')
	{
		negative = false;
		iBuffer++;
		while (buffer[iBuffer] <=' ') iBuffer++ ;
	}


	while ( buffer [ iBuffer ] >= '0' )
	{
		result = result * 10 + (buffer [ iBuffer ++ ] - '0') ;
	
	}

	if (negative) result = - result ;

	return result;
}	
void getStr(char * s)
{
	int iS = 0;
	while (buffer[iBuffer] <= ' ') iBuffer++;
	while (buffer[iBuffer] > ' ')s[iS++] = buffer[iBuffer++] ;
	s[iS] = '\0';
}

struct TAnswer
{
       int l, r;
       bool p ;
};

int result, bn, x, y, l, n, i, k ;
char s[200];
struct TAnswer a[MAXN+1];
int b[MAXN*2+2];
int c[MAXN*2+2];
//int t[MAXN*2+2];

void quickSort(int left, int right)
{
	
		int k = b [ ( left + right ) / 2];
		int i = left ;
		int j = right ;
		while ( i <= j )
		{
			while ( k > b[i] ) i++;
			while ( k < b[j] ) j--;
			if (i <= j)
			{
				int temp = b [ i ] ;
				b [ i ]  = b [ j ] ;
				b [ j ]  = temp ;
				i ++ ;
				j -- ;
			}
		}

	if ( i    < right )	quickSort ( i     , right ) ;
	if ( left < j  )    quickSort ( left  ,     j ) ;
	
}
//void mergeSort(int l, int r)
//{
//     int k, p1, p2, p3, i;
//     
//	 if ( l < r )
//      {
//              k = ( l + r ) / 2 ;
//              
//			  mergeSort ( l     ,  k  ) ;
//              mergeSort ( k + 1 ,  r  ) ;
//              
//			  p1 = l ;
//              
//			  p2 = k + 1 ;
//              
//			  p3 = l   ;
//              
//			  while ( p1 <= k && p2 <= r )
//              {
//                    if (b[p1] < b[p2]) t[p3++] = b[p1++];
//                    else t[p3++] = b[p2++];
//              }
//              while (p1<=k) t[p3++] = b[p1++];
//              while (p2<=r) t[p3++] = b[p2++];
//              
//              for (i = l; i <= r; i++)b[i] = t[i];
//      }
//}

bool check(int w)
{
     int k,l,r;

     l = 1;
     while (true)
     {
         r = bn;
         while (l<r) 
         {
              k = (l+r)/2;
              if (a[w].l > b[k]) l = k  + 1; else r = k;
         }
         if (c[l] < 0)
         {
                  c[l] = w ;
                  return true ;
         }
         if (a[w].r == a[c[l]].r) return (a[w].p == a[c[l]].p);
         
         if (a[w].r < a[c[l]].r)
         {
                    k = c[l];
                    c[l] = w;
                    w = k;
         }
         a[w].l = a[c[l]].r + 1;
         a[w].p = a[w].p ^ a[c[l]].p;
           
     }
}
int main(int argc, char *argv[])
{
  #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin);
          freopen("output.txt","w", stdout);
  #endif
	
  nBuffer = fread ( buffer, 1, MAX_BUFFER_SIZE, stdin ) ;
  iBuffer = 0 ;
  
  l = 1;
  while (  l >= 0)
  {
        //scanf("%d\n",&l);
	  l = getInt();
        if (l>=0)
        {
            //scanf("%d\n",&n);
			n = getInt();
           for (i = 1; i<=n;i++)
           {
               //scanf("%d %d %s\n", &x, &y, s);
			   x = getInt();
			   y = getInt();
			   getStr(s);
               a[i].l = x;
               a[i].r = y;
               a[i].p = s[0] == 'o'; // odd
               b[i] = x;
               b[i+n] = y+1;
           }        
           
           bn = n * 2;
          // mergeSort(1, bn);
		   quickSort(1,bn);
           k = 0;
           for (i = 1; i<=bn;i++)
           {
               if (i==bn || b[i]!=b[i+1])b[++k] = b[i];
           }
           bn = k;
           for ( i = 1; i<=bn; i++)c[i] = -1;
           result = 0;
           while ( result < n  && check(result + 1 )  ) result++ ;
           printf("%d\n",result);
        }
  }
  
  
  return 0;
}
