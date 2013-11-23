#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXN 104
#define MAXINT 100000000


int main()
{

int a[MAXN+1][MAXN+1];
int d[MAXN+1][MAXN+1];
int path[MAXN+1][MAXN+1];

int i, j, k, m, n, p ;
int best;
int besti, bestj, bestk ;

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w",stdout);
#endif

while (  1  ){

	scanf("%d",&n);
	if (n<0)break;
	scanf("%d",&m);
	for (i = 1; i <= n; i++){
		for (j = 1; j<=n;j++){
			a[i][j] = MAXINT;
			path[i][j] = -1;
		}
		a[i][i] = 0;
	}

	for (i= 1; i<=m;i++)
	{
		scanf("%d %d %d", &j, &k, &p);
		if (p < a[j][k])
		{
			a[j][k] = p;
			a[k][j] = p;
			path[j][k] = k ;
			path[k][j] =  j ;
		}
	}
	
	
	for (i = 1; i <= n; i++){
		for (j = 1; j<=n;j++){
			d[i][j] = a[i][j] ;
		}
	}

     

	for (k = 1; k<=n;k++)
	{ 
		for (i = 1; i<=n; i++)
		{	 
			for (j = 1; j<= n;j ++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}

        
		best = MAXINT;
        besti = -1;
        bestj = -1;
        bestk = -1;


		for (i = 1; i<=n;i++)
		{
			for (j = i + 1; j <= n;j ++)
			{
				if (a[i][j] < MAXINT)
				{
					for (k = 1; k <=n; k++) if (k!=i && k!= j && d[i][k] < MAXINT && d[j][k] < MAXINT)
					{
						if (path[i][k] != j && path[j][k] != i )
						{
							if (a[i][j] + d[i][k] + d[j][k] < best )
							{
								best  = a[i][j] + d[i][k] + d[j][k]; 
								besti = i ;
								bestj = j ;
								bestk = k ;
							}
						}
					}
				}
			}
		}
			


		if (besti < 0 || bestj < 0 || bestk < 0) printf("No solution.\n");
			else {
				while (besti != bestk)
				{
					printf("%d ", besti);
					besti = path[besti][bestk];
				}
				while (besti != bestj)
				{
					printf("%d ", besti);
					besti = path[besti][bestj];
				}
				printf("%d\n", besti);
			}
	}	

    return 0;
}
