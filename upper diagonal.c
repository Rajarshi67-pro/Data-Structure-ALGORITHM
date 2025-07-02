#include<stdio.h>
#include<stdlib.h>
void convertDiag(int **matrix ,int n)
{
	for(int i=0; i<n ;i++)
	{
		for(int j=0; j<i ;j++)
		{
			matrix[i][j]=0;
			}
		}
	}
	void main()
	{
		int n,i,j;
		printf("enter the order of matrix");
		scanf("%d",&n);
		int **matrix = (int **)malloc(n*sizeof(int *));
		for(i=0;i<n;i++)
		{
		matrix[i]= (int*)malloc(n*sizeof(int));
		}
		printf("enter elements of the matrix :\n");
		for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		{
		scanf("%d",&matrix[i][j]);
		}
	}
	convertDiag(matrix,n);
	printf("the upper triangular matrix is :\n");
	for(i=0; i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		printf("%d",matrix[i][j]);
		}
		printf("\n");
		}
	}			
				
