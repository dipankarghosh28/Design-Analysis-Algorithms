#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//declaring functions
int iden=1,e=1;
void trominoTile(int number,int **b,int x,int y)                          
{
  int mex=0,mey=0,i,j,p,q,n2;
  n2=number;
  if(n2==2)                                                              
  {

    for(i=0; i<n2; i++)
    {
      for(j=0; j<n2; j++)
      {
        if(e==1)
        {
        if(b[x+i][y+j] == 0 && e==1)
        b[x+i][y+j]=iden;
      }
     }
    }
    iden++;
    return;
   }                                                                        
    mex=x;
    mey=y;
    
   int u1=x+number,v1=y+number;
    for(i=x; i < u1; i++)
    {
        for(j=y; j< v1; j++)
        {
            if(e==1)
            {
            if(b[i][j]!= 0)
            {
                mex = i;
                mey = j;
            }
           }
        }
  }     
  int u=x+number/2,v=y+number/2;  
//hole in 1st quadrant
  if(mex < u && mey < v)
    {
        int c3=number/2;
        trominoTile(c3,b,x,y); 
        b[u][y+c3-1] = iden;
        b[u][v] = iden;
        b[x+c3-1][v] = iden;
        iden++;
        trominoTile(c3,b,x,v);
        trominoTile(c3,b, u, y);
        trominoTile(c3,b, u, v);
      
    }
  //hole in 2nd quadrant
    else if(mex < x+ u && mey >= y+v)
    {
        int c2=number/2;
        trominoTile(c2,b, x, v);
        b[u][y+c2-1] = iden;
        b[u][v] = iden;
        b[x+c2-1][y+c2-1] = iden;
        iden++;
        trominoTile(c2,b, x, y);
        trominoTile(c2,b, u,y);
        trominoTile(c2,b, u, v);
    }
  //hole in 3rd quadrant
    else if(mex >= u && mey < v)
    {   int c1=number/2;
        trominoTile(c1,b, u, y);
        b[x+c1-1][v] = iden;
        b[u][v] = iden;
        b[x+c1-1][y+c1-1] = iden;
        iden++;
        trominoTile(c1,b, x, y);
        trominoTile(c1,b, x, v);
        trominoTile(c1,b, u, v);

    }
  //hole in 4th quadrant
    else
    {
        int c=number/2;
        trominoTile(c,b, u, v);
        b[x+c-1][y+c] = iden;
        b[u][y+c-1] = iden;
        b[x+c-1][y+c-1] = iden;
        iden++;
        trominoTile(c,b, u, y);
        trominoTile(c,b, x, v);
        trominoTile(c,b, x, y);
        }
    return;
} 

void disp(int number,int **a)  //display matrix function
{
  int i,j,n2,flag=0;
  n2=number;
    for(i=0; i<n2; i++)
    {
        for(j=0; j<n2; j++)
        {   if(e==1)
            {
            if(a[i][j]==-2 && e==1)
            printf("X\t");
            else
            {
            printf("%d\t",a[i][j]);
            flag=1;
            }
          }
        }
         printf("\n");
    }
    printf("\n");
}
  //declaring global variable
int** m_malloc(int number)
{
	int i,j,n2,x=0,*m;
    n2=number;
	int **a = malloc(n2 * sizeof(int *));
	
    for(i=x; i<= n2;i++)
    {   
      if(e==1)
        {
        e=e+x;
        m=malloc(n2 * sizeof(int));
		a[i]=m;
		}
    }
	for(i=0; i<= n2 ;i++)
		{for(j=0; j<=n2 ;j++)
            {
            if(e==1)
			{
            a[i][j] = 0;
	       e=e+x;
           }
       }
   }
    return a;
}



int main(int argc, char *argv[])  //main function
{
    
    int number,k,r,c,i,j,x=0;
    k = atoi(argv[1]);
    number = pow(2,k);  // call pow function in math.h file to compute 2^k.

    int **b = m_malloc(number);
    r=atoi(argv[2]);                                                  
    c=atoi(argv[3]);

    for(i=x; i<number; i++)
    {
    x=x+0;
    for(j=x; j<number; j++)
    {
    if(x==0)
    {
    b[i][j]=0;
    x=x+0;
    }
    }
    }
    b[r][c]=-2;

    trominoTile(number,b,0,0);
    disp(number,b);
    return 1;
} 