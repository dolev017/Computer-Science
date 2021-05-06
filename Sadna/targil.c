#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>

/* Structs */
typedef struct list
{
	int data;
	struct list* next;
}List;

typedef struct char_node
{
	char data;
	struct node *next;
}Char_Node;

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
Char_Node * createCharNode(char);
Char_Node * addCharToFirst(Char_Node *, char);
Char_Node * addCharToLast(Char_Node *, char);
void disassemblyList(Char_Node * list, Char_Node * list_LETTER, Char_Node * list_letter, Char_Node * list_num, Char_Node * list_char);
void print_char_node(Char_Node *);
void freeMatrix(int**, int);
int** newMatrix(int, int);
void insertValue(int**, int, int);
void printMatrix(int**, int, int);
void neighborMaxMin(int**, int*, int*, int, int, int, int);
int** matrixMaxNeighbor(int**, int, int);
List* addnewnode(int data);
List* insert(List* head, int data);
List* makelist(List* head);
void printlist(List* head);
void deleteNode(List** head);
List* creatlist(List** head);
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
	int** matrixA;
	int** matrixB;
	int rows, cols, max, min;

	printf("Enter the number of rows you want:\n");
	scanf_s("%d", &rows);
	printf("Enter the number of collums you want:\n");
	scanf_s("%d", &cols);

	matrixA = newMatrix(rows, cols);

	insertValue(matrixA, rows, cols);
	printf("Value of matrixA\n");
	printMatrix(matrixA, rows, cols);

	matrixB = matrixMaxNeighbor(matrixA, rows, cols);
	printf("Value of matrixB\n");
	printMatrix(matrixB, rows, cols);

	freeMatrix(matrixA, rows);
	freeMatrix(matrixB, rows);
}
void Ex3()
{
	
}
void Ex4()
{
	List* likedlist;
	List* newlikedlist;
	likedlist = NULL;

	likedlist = makelist(likedlist);
	printf("The original list is:\n");
	printlist(likedlist);
	printf("\n");
	newlikedlist = creatlist(&likedlist);
	printf("The new list is:\n");
	printlist(newlikedlist);
	printf("\n");
	printf("The old list is:\n");
	printlist(likedlist);
}
void Ex5()
{
	
}
void Ex6()
{

}
void Ex7()
{
	int num, i;
	char data;
	printf("Enter a number of char: ");
	scanf_s("%d", &num);
	rewind(stdin);
	Char_Node * list = NULL;
	Char_Node * list_LETTER = NULL;
	Char_Node * list_letter = NULL;
	Char_Node * list_num = NULL;
	Char_Node * list_char = NULL;
	printf("Enter a char: ");
	scanf_s("%c", &data);
	rewind(stdin);
	list = createCharNode(data);
	for (i = 0; i < num-1; i++)
	{
		printf("Enter a char: ");
		scanf_s("%c", &data);
		rewind(stdin);
		list = addCharToLast(list, data);
	}
	disassemblyList(list,list_LETTER,list_letter,list_num,list_char);
	print_char_node(list_LETTER);
	print_char_node(list_letter);
	print_char_node(list_num);
	print_char_node(list_char);
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

Char_Node * createCharNode(char data)
{
	Char_Node *temp = (Char_Node *)malloc(sizeof(Char_Node));
	if (temp == NULL)
		return;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Char_Node * addCharToFirst(Char_Node * head, char data)
{
	Char_Node *temp = createCharNode(data);
	temp->next = head;
	return temp;
}

Char_Node * addCharToLast(Char_Node *head, char data)
{
	Char_Node *temp = createCharNode(data);
	Char_Node *p = head;
	if (head == NULL)
		return temp;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
	return head;
}

void disassemblyList(Char_Node * list, Char_Node * list_LETTER, Char_Node * list_letter, Char_Node * list_num, Char_Node * list_char)
{
	char data;
	while (list->next != NULL)
	{
		data = list->data;
		if(data>='A' && data<='Z')
			if (list_LETTER != NULL)
			{
				list_LETTER=createCharNode(data);
			}
			else
			{
				list_LETTER=addCharToLast(list_LETTER, data);
			}
		if (data >= 'a' && data <= 'z')
			if (list_letter != NULL)
			{
				list_letter= createCharNode(data);
			}
			else
			{
				list_letter=addCharToLast(list_letter, data);
			}
		if (data >= '0' && data <= '9')
			if (list_num != NULL)
			{
				list_num= createCharNode(data);
			}
			else
			{
				list_num=addCharToLast(list_num, data);
			}
		if ((data >= ' ' && data <= '/') || (data>='[' && data<='`') || (data>='{' && data))
			if (list_char != NULL)
			{
				list_char= createCharNode(data);
			}
			else
			{
				list_char=addCharToLast(list_char, data);
			}
	}
}

void print_char_node(Char_Node * temp)
{
	while (temp->next != NULL)
	{
		printf("%c, ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	printf("\n");
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
	int i, j;

	for (i = 0; i < r; i++)
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
			printf("[%d][%d]=%d\n\n", i, j, a[i][j]);
		}
}

/* ------------------- */
void neighborMaxMin(int** a, int* answerMax, int* answerMin, int i, int j, int lastRow, int lastCol)
{
	int min, max;
	min = 0;
	max = 0;

	if (!(i == 0))
	{
		if (max < a[i - 1][j])
			max = a[i - 1][j];
		if (min > a[i - 1][j])
			min = a[i - 1][j];
	}

	if (!(i == lastRow - 1))
	{
		if (max < a[i + 1][j])
			max = a[i + 1][j];
		if (min > a[i + 1][j])
			min = a[i + 1][j];
	}

	if (!(j == 0))
	{
		if (max < a[i][j - 1])
			max = a[i][j - 1];
		if (min > a[i][j - 1])
			min = a[i][j - 1];
	}

	if (!(j == lastCol - 1))
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
	int i, j, max, min;

	matrixB = newMatrix(r, c);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			neighborMaxMin(a, &max, &min, i, j, r, c);
			matrixB[i][j] = max;
		}
	return matrixB;
}

List* addnewnode(int data)
{
	List* newnode = (List*)malloc(sizeof(List));
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

List* insert(List* head, int data)
{
	List* newnode = addnewnode(data);
	List* curr = head;
	if (head == NULL)
	{
		//list is empty.
		head = newnode;
	}
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newnode;
	}
	return head;
}

List* makelist(List* head)
{
	int number;
	printf("Enter a number, to stop enter -1\n");
	scanf_s("%d", &number);
	while (number != (-1))
	{
		head = insert(head, number);
		printf("Enter a number, to stop enter -1\n");
		scanf_s("%d", &number);
	}
	return head;
}

void printlist(List* head)
{
	List* curr;
	curr = head;

	if (head == NULL)
		printf("Thelist is empty!\n");

	else
	{
		while (curr != NULL)
		{
			printf("%d\t", curr->data);
			curr = curr->next;
		}
	}
}

void deleteNode(List** head)
{
	List* curr;
	List* delnode;

	curr = *head;
	if (*head == NULL)
	{
		printf("Nothing to delete,the list is empty!!\n");
	}
	else if (curr->next == NULL)
	{
		//only one element in the list.
		delnode = curr;
		*head = NULL;
		free(delnode);
	}
	else
	{
		while ((curr->next)->next != NULL)
		{
			curr = curr->next;
		}
		delnode = curr->next;
		curr->next = curr->next->next;
		free(delnode);
	}
}

List* creatlist(List** head)
{
	List* curr;
	List* newlist;
	List* temp;

	newlist = NULL;

	curr = *head;

	if (curr == NULL)//empty list
	{
		return newlist;
	}

	if (curr->next == NULL)// one element in the list
	{
		newlist = insert(newlist, curr->data);
		*head = NULL;

		deleteNode(&curr);
		return newlist;
	}

	if (curr->data > curr->next->data)// the first element in the list is beger then the secend element
	{
		newlist = insert(newlist, curr->data);
		temp = curr;
		*head = curr->next;
		temp->next = NULL;
		deleteNode(&temp);
		curr = *head;
	}

	while (curr->next)
	{
		temp = curr;
		if (temp->next->next != NULL)
		{
			if (curr->data < curr->next->data)
			{
				temp = temp->next;
				if (temp->data > temp->next->data)
				{
					curr->next = temp->next;
					newlist = insert(newlist, temp->data);
					curr = temp->next;
					temp->next = NULL;
					deleteNode(&temp);
				}
				else
					curr = curr->next;
			}
			else
				curr = curr->next;
		}
		else
		{
			if (curr->data < curr->next->data)// last element is biger the the prev element
			{
				temp = curr;
				temp = temp->next;
				newlist = insert(newlist, temp->data);
				temp->next = NULL;
				deleteNode(&temp);
				curr->next = NULL;
			}
		}
	}
	return newlist;
}