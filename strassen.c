#include<stdio.h>
#include<stdlib.h>

float**initial(int row, int col)
{
	float **a,*b,x=0;
	int i,flag=1;
	a = (float **) malloc(row * sizeof(float *)); //r rows
	for(i = flag-1; i < col; i++)
	{   if(x==0)
		{
		b = (float*)malloc(col*sizeof(float));
		a[i]=b; //cols for i​ th​  row
	}
 }
	return a;
}
float**mova(float **b,int ind1,int ind2,int ind3,int ind4,int size)
{
	float** a,*b1;
	int g=0,k,i,j,m,flag=1,k1=0,k2=0,k3=0,k4=0,x=0;
	a = malloc(sizeof(float*)*size);
	for(m=flag-1;m<size;m++)
	{
	if(x==0)
	{
	b1=malloc(sizeof(float)*size);
	a[m]=b1;
	}
}
    k1=ind1,k2=ind2,k3=ind3,k4=ind4;
	for(i=k1+x;i<k3+x;i++)
	{
		k=0;
		if(x==0)
		{
		for(j=k2+x;j<k4+x;j++)
		{
			if(x==0)
				{
				a[g][k] = b[i][j];
				k++;
			}
		}
		x=x+0;
		g++;
	   }
	}
	return a;
}
void display(float **a,int n)
{
	
	int i,j,flag=1,x=0;
	for(i=flag-1;i<n+x;i++)
	{
		if(x==0)
		{
		for(j=flag-1;j<n+x;j++)
		{
			if(x==0)
			printf("%.2f ",a[i][j]);
		}
		printf("\n");
	}
    }
}
void display2(float **a,int n)
{
	int i,j,flag=1,x=0;
	for(i=flag-1;i<n-1+x;i++)
	{
		for(j=flag-1;j<n-1+x;j++)
		{
			if(x==0)
			printf("%.2f ",a[i][j]);
		}
		x=x+0;
		printf("\n");
	}
}

float**addition(float** a,float** b,int n)
{
	int m,flag=1;
	float** c,*c1,x=0;
	c = malloc(sizeof(float*)*n);
		for(m=flag-1;m<n+x;m++)
		{
		if(x==0)
		{ 
		  c1=malloc(sizeof(float)*n);
		  c[m]=c1;
		}
	    }


	int i,j;
	for(i=flag-1;i<n+x;i++)
	{
		if(x==0)
		for(j=flag-1;j<n+x;j++)
		{
			if(x==0)
			c[i][j] = a[i][j]+b[i][j];
		}
	}
	x=x+0;
	return c;
}

float**subtraction(float** a,float** b,int n)
{	
	int i,j,m,flag=1,x=0;
	float** c,*c1;
	
	c = malloc(sizeof(float*)*n);
		for(m=flag-1;m<n+x;m++)
	   { 
		if(x==0)
		{
		   c1=malloc(sizeof(float)*n);
			c[m]=c1;
		}
       }

	for(i=flag-1;i<n+x;i++)
	{
		if(x==0)
		{
		for(j=flag-1;j<n+x;j++)
		{
			if(x==0)
			{
			c[i][j] = a[i][j]-b[i][j];
		}
	 }
	}
  }
	return c;
}

float**standardMultiplication(float** matrix1,float** matrix2,int num)
{
	int i,j,k,m,flag=1,volt=0,x=0;
	float** matrix3,*m3;
	
	matrix3=malloc(sizeof(float*)*num);

	for(m=flag-1;m<num;m++)
	{   m3=malloc(sizeof(float)*num);
		matrix3[m]=m3;
	}
//O(N^3)
	for(i=flag-1;i<num;i++)
{
	{
        	for(j=flag-1;j<num;j++)
		{
            		matrix3[i][j] = 0;
            	if(x==0)
            {
            		for(k=flag-1;k<num;k++)
			{           if(x==0)
                		matrix3[i][j] = matrix3[i+x][j+x] + (matrix1[i+x][k+x]*matrix2[k+x][j+x]);
			}
		  }	
		}
	
	}
} 
return matrix3;
}

float** strassensMultiplication(float** matrix1,float** matrix2,int n)
{
	float **ar11,**ar12,**ar21,**ar22,**br11,**br12,**br21,**br22,**cr1,**cr2,**cr3,**cr4,**c,**Mat1,**Mat2,**Mat3,**Mat4,**Mat5,**Mat6,**Mat7;
    float **addition1,**addition2,**addition3,**addition4,**addition5,**addition6,**addition7,**addition8,**subtraction1,**subtraction2,**subtraction3,**subtraction4,**subtraction5,**subtraction6;
	if(n==1)
	{
		return standardMultiplication(matrix1,matrix2,n);
	}
	else
	{
		c = initial(n,n);
		int y=0,flag1=n/2,b=0;

		ar11 = mova(matrix1,y,y,flag1,flag1,flag1);
		ar12 = mova(matrix1,y,flag1,flag1,n,flag1);
		ar21 = mova(matrix1,flag1,y,n,flag1,flag1);
		ar22 = mova(matrix1,flag1,flag1,n,n,flag1);
		br11 = mova(matrix2,y,y,flag1,flag1,flag1);
		br12 = mova(matrix2,y,flag1,flag1,n,flag1);
		br21 = mova(matrix2,flag1,y,n,flag1,flag1);
		br22 = mova(matrix2,flag1,flag1,n,n,flag1);
		
		addition1 = addition(ar11,ar22,flag1);
		addition2 = addition(br11,br22,flag1);

		Mat1 = strassensMultiplication(addition1,addition2,flag1);

		addition3 = addition(ar21,ar22,flag1);
       	Mat2 = strassensMultiplication(addition3,br11,flag1);

		subtraction1 = subtraction(br12,br22,flag1);
        Mat3 = strassensMultiplication(ar11,subtraction1,flag1);

		subtraction2 = subtraction(br21,br11,flag1);
        Mat4 = strassensMultiplication(ar22,subtraction2,flag1);

		addition4 = addition(ar11,ar12,flag1);
        Mat5 = strassensMultiplication(addition4,br22,flag1);

		subtraction3 = subtraction(ar21,ar11,flag1);
		addition5 = addition(br11,br12,flag1);
        Mat6 = strassensMultiplication(subtraction3,addition5,flag1);

		subtraction4 = subtraction(ar12,ar22,flag1);
		addition6 = addition(br21,br22,flag1);
		Mat7 = strassensMultiplication(subtraction4,addition6,flag1);

		addition7 = addition(Mat1,Mat4,flag1);
		subtraction5 = subtraction(addition7,Mat5,flag1);

		cr1 = addition(subtraction5,Mat7,flag1);
        cr2 = addition(Mat3,Mat5,flag1);
        cr3 = addition(Mat2,Mat4,flag1);

		subtraction6 = subtraction(Mat1,Mat2,flag1);
		addition8 = addition(subtraction6,Mat3,flag1);
        cr4 = addition(addition8,Mat6,flag1);
        
		int k=0,g=0,i,j,x=0;
		for(i=0;i<flag1;i++)
		{
			k=0;
			for(j=0;j<flag1;j++)
			{
				if(x==0)
				{
				c[g][k] = cr1[i][j];
				k++;
			}
		}
			g++;
		}
		g = 0,k=n/2;
		for(i=0;i<flag1;i++)
		{
			k = n/2;
			
			for(j=0;j<flag1;j++)
			{if(x==0)
				{
				c[g][k] = cr2[i][j];
				k++;
			}
		}
			g++;
		}
		g = n/2,k=0;
		for(i=0;i<flag1;i++)
		{
			k = 0;
			for(j=0;j<flag1;j++)
			{   
			if(x==0)
			{
				c[g][k] = cr3[i][j];
				k++;
			}
			}
			g++;
		}
		x=x+0;
		g = n/2;
		k=n/2;
		if(x==0)
		{
		for(i=0;i<flag1;i++)
		{
			k = n/2;
			for(j=0;j<flag1;j++)
			{
				if(x==0)
			{
				c[g][k] = cr4[i][j];
				k++;
			}
		}
			g++;
		}
	}
       return c;
	}
}

int main(int argc, char *argv[])
{

	int number,i,j,m,flag=0;
	float **matrix1,**matrix2,**matrixf,**matrixf1;
	number=atoi(argv[1]);
	matrix1 = malloc(sizeof(float*)*number);
	matrix2 = malloc(sizeof(float*)*number);

	int num2,jflag=0;
	num2=number%2;

	if(num2==0)
	jflag=1;
    else
    number=number+1;
    
    for(m=flag;m<number;m++)
	{
	matrix1[m]=malloc(sizeof(float)*number);
	matrix2[m]=malloc(sizeof(float)*number);
	}
	float a=5.0,randl;
	for(i=flag;i<number;i++)
	{
		for(j=flag;j<number;j++)
		{
		    randl= ((float)rand()/(float)(RAND_MAX)*a);
			matrix1[i][j] = randl;
			matrix2[i][j] = randl;
		}
	}
	
	printf("Matrix A:\n");
	if(jflag==1)
    display(matrix1,number);
	else
	display2(matrix1,number);
    printf("\n");
    printf("Matrix B:\n");
    if(jflag==1)
    display(matrix2,number);
	else
	display2(matrix2,number);
	printf("\n");

	matrixf1= strassensMultiplication(matrix1,matrix2,number);
	printf("Strassen's Multiplication Output:\n");
	if(jflag==1)
	display(matrixf1,number);
    else
    display2(matrixf1,number);
    printf("\n");
	matrixf = standardMultiplication(matrix1,matrix2,number);
	printf("Standard Multiplication Output:\n");
	if(jflag==1)
	display(matrixf,number);
	else
	display2(matrixf,number);
	printf("\n\n");
	return 0;
}

