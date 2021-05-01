#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include<math.h>

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();

/* Declarations of other functions */

unsigned int * powerArray(int num);

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-7 : ");
				scanf_s("%d", &select);
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
	unsigned int *p, num, i;
	printf("enter a number greater than 0: ");
	scanf_s("%d", &num);
	p = powerArray(num);
	for (i = 0; i < num; i++)
	{
		printf("%d, ", p[i]);
	}
}
void Ex2()
{

}
void Ex3()
{

}
void Ex4()
{

}
void Ex5()
{

}
void Ex6()
{

}
void Ex7()
{

}
/* ------------------- */

/* Declarations of other functions */

unsigned int * powerArray(int num)
{
	unsigned int * arr;
	int i;
	arr = (int *)malloc(sizeof(int *)* num);
	for (i = 0; i < num; i++)
	{
		arr[i] = pow(2.0, i % 32);
	}
	return arr;
}