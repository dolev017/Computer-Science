#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>


/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();

/* Declarations of other functions */

/*--------------------------------------*/
/*-----------Ex2------------------------*/
void freeMatrix(int**, int);
int** newMatrix(int, int);
void insertValue(int**, int, int);
void printMatrix(int**, int, int);
void neighborMaxMin(int**,int*,int*, int, int, int, int);
int** matrixMaxNeighbor(int**, int, int);
/*--------------------------------------*/

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-7 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 7));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			case 7: Ex7(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */
void Ex1()
{

}

/*--------------------------------------*/
void Ex2()
{
	int** matrixA;
	int** matrixB;
	int rows, cols,max,min;

	printf("Enter the number of rows you want:\n");
	scanf_s("%d", &rows);
	printf("Enter the number of collums you want:\n");
	scanf_s("%d", &cols);

	matrixA = newMatrix(rows, cols);

	insertValue(matrixA, rows, cols);
	printf("Value of matrixA\n");
	printMatrix(matrixA, rows, cols);

	matrixB=matrixMaxNeighbor(matrixA, rows, cols);
	printf("Value of matrixB\n");
	printMatrix(matrixB, rows, cols);

	freeMatrix(matrixA, rows);
	freeMatrix(matrixB, rows);	
}

void freeMatrix(int** a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(a[i]);
	free(a);
}


int** newMatrix(int r, int c)
{
	int** a;
	int i;
	
	a = (int*)malloc(r * sizeof(int));
	if (!a)
		return NULL;

	for (i = 0; i < r; i++)
	{
		a[i] = (int*)malloc(c * sizeof(int));
		if (!a[i])
		{
			freeMatrix(a, i);
			return NULL;
		}
	}
	return a;
}

void insertValue(int** a, int r, int c)
{
	int i,j;

	for(i=0;i<r;i++)
		for (j = 0; j < c; j++)
		{
			printf("Enter a value for [%d][%d]", i, j);
			scanf_s("%d", &a[i][j]);
		}
	printf("\n\n");
}

void printMatrix(int** a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			printf("[%d][%d]=%d\n\n", i, j,a[i][j]);
		}
}

void neighborMaxMin(int** a,int* answerMax,int* answerMin, int i, int j, int lastRow, int lastCol)
{
	int min, max;
	min = 0;
	max = 0;
	
	if (!(i == 0))
	{
		if (max < a[i-1][j])
				max = a[i-1][j];
		if (min > a[i-1][j])
				min = a[i-1][j];
	}

	if (!(i == lastRow-1))
	{
		if (max < a[i + 1][j])
				max = a[i + 1][j];
		if (min > a[i + 1][j])
				min = a[i + 1][j];
	}

	if (!(j == 0))
	{
		if (max < a[i][j-1])
				max = a[i][j-1];
		if (min > a[i][j-1])
				min = a[i][j-1];
	}

	if (!(j == lastCol-1))
	{
		if (max < a[i][j + 1])
				max = a[i][j + 1];
		if (min > a[i][j + 1])
				min = a[i][j + 1];
	}

	*answerMax = max;
	*answerMin = min;
}

int** matrixMaxNeighbor(int** a, int r, int c)
{
	int** matrixB;
	int i, j,max,min;

	matrixB = newMatrix(r, c);
	for(i=0;i<r;i++)
		for (j = 0; j < c; j++)
		{
			neighborMaxMin(a, &max, &min, i, j, r, c);
			matrixB[i][j] = max;
		}
	return matrixB;
}
/*--------------------------------------*/

void Ex3()
{

}
/*--------------------------------------*/

void Ex4()
{

}
/*--------------------------------------*/

void Ex5()
{

}
/*--------------------------------------*/

void Ex6()
{

}
/*--------------------------------------*/

void Ex7()
{

}
/*--------------------------------------*/
/* ------------------- */
