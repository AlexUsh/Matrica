#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

int main(int argc, char *argv[])
{
	/*Randomly generate an array of m*n, fill it, print the screen.*/
	int i,j,k,m,n;
	srand (time (NULL));

	printf("Enter m and n\n");
	scanf("%d%d%*c", &m, &n);
	printf("\n");
	printf("1:\n");
	int mass[m][n];
    for (i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            {
             mass[i][j]= 0 + rand() % 10;
             printf ("%d ", mass [i][j]);
            }
            printf ("\n");
    }
    printf("\n");
    
/*Swap the first and last lines, deploy them*/    
    /*expandable rows*/
    for(j=0; j<n/2; j++)
    {
    	k = mass[0][j];
    	mass[0][j] = mass[0][n-1-j];
    	mass[0][n-1-j] = k;
    	
    	k = mass[m-1][j];
    	mass[m-1][j] = mass[m-1][n-1-j];
    	mass[m-1][n-1-j] = k;
    }
    /*swap first and last*/
    for (j=0; j<n; j++)
    {
       	k = mass[0][j];
    	mass[0][j] = mass[m-1][j];
    	mass[m-1][j] = k; 
    }
    
    printf("2:\n");
   
    for (i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
    	{
        	printf ("%d ", mass [i][j]);
        }
        printf ("\n");
    }
    printf("\n");
/*Delete the row and column intersection is the smallest element of the array.*/
	/*looking for minimum*/
	int mini = 0;
	int minj = 0;
	int min = mass[0][0];
	for (i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
    	{
        	if(mass[i][j] < min)
        	{
        		min = mass[i][j];
        		mini = i;
        		minj = j;
        	}
        }
    }

    /*delete the line*/
    for (i=mini; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
             mass[i][j]=mass[i+1][j];
        }
    }
    /*the column to delete*/
    for (j=minj; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
             mass[i][j]=mass[i][j+1];
        }
    }
    
    printf("3:\n");
    /*print*/
    for (i=0; i<m-1; i++)
    {
        for(j=0; j<n-1; j++)
    	{
        	printf ("%d ", mass [i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
/*Create a second massive manually 
Formatting: space bar-member end point-the end of the line, point the end of the input*/	
    char str[1024];

	printf("Enter string to fill a matrix. Size should be (x*%d): ", n-1);

	gets(str);
		
	/*determine the size of the array*/
	int m1 = 1;
	int n1 = 1;
	for(i=0; i<strlen(str); i++)
	{
		if(str[i] == ',')
		{
			m1++;
		}
		if(str[i] ==  ' ' && m1==1)
		{
			n1++;
		}
	}
	
	int mass2[m1][n1];
	int _i = 0, _j = 0;
	
	for (i=0; i<m1; i++)
        for(j=0; j<n1; j++)
        	mass2[i][j]=0;
        	
	for(i=0; i<strlen(str); i++)
	{
		if(str[i] == ' ' && str[i]!=',')
		{
			_j++;
		}
		else if(str[i] == ',')
		{
			_i++;
			_j=0;
		}
		else if(str[i] != '.')
		{
			mass2[_i][_j] = mass2[_i][_j]*10 + (int)(str[i]-'0');
		}
	}	
	printf("\n");

 	/*print mass*/
 	printf("A:\n");
    for (i=0; i<m-1; i++)
    {
        for(j=0; j<n-1; j++)
    	{
        	printf ("%d ", mass[i][j]);
        }
        printf ("\n");
    }
	printf ("\n");
	printf("B:\n");
    /*print mass2*/
    for (i=0; i<m1; i++)
    {
        for(j=0; j<n1; j++)
    	{
        	printf ("%d ", mass2[i][j]);
        }
        printf ("\n");
    }
	printf ("\n");
	
	/*the multiplied matrix*/
	int mass3[m-1][n1];
	/*if the form of the matrices agreed*/
	if(n-1==m1)
	{
		/*consider*/
		for(i = 0; i < m-1; i++)
		{
    		for(j = 0; j < n1; j++)
    		{
       			mass3[i][j] = 0;
        		for(k = 0; k < m1; k++)
        		{
			    	mass3[i][j] += mass[i][k] * mass2[k][j];
			    }
    		}
    	}
    	printf("A*B:\n");
    	/*output the result*/
    	for(i = 0; i < m-1; i++)
		{
    		for(j = 0; j < n1; j++)
    		{
    			printf ("%d ", mass3[i][j]);
        	}
        	printf ("\n");
    	}
	}
	else
	{
		printf ("Error! The marix has worng size!\n");
	}

	return 0;
}
