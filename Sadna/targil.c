#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include<math.h>

/* Structs */
typedef struct test
{
	int data;
}Test;

typedef struct node
{
	int data;
	struct node *next;
}Node;

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
Node * createNode(int);
Node * addToFirst(Node *, int);
Node * addToLast(Node *, int);
Char_Node * createCharNode(char);
Char_Node * addCharToFirst(Char_Node *, char);
Char_Node * addCharToLast(Char_Node *, char);
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
	int num, i;
	char data;
	printf("Enter a number of char: ");
	scanf_s("%d", &num);
	Char_Node * list = NULL;
	printf("Enter a char: ");
	list = addCharToFirst(list, scanf_s("%c", &data));
	for (i = 0; i < num-1; i++)
	{
		printf("Enter a char: ");
		list = addCharToLast(list, scanf_s("%c", &data));
	}
	disassemblyList(list);
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

Node * createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
		return;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Node * addToFirst(Node * head, int data)
{
	Node *temp = createNode(data);
	temp->next = head;
	return temp;
}

Node * addToLast(Node *head, int data)
{
	Node *temp = createNode(data);
	Node *p = head;
	if (head == NULL)
		return temp;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
	return head;
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
	Char_Node *temp = createNode(data);
	temp->next = head;
	return temp;
}

Char_Node * addToLast(Char_Node *head, char data)
{
	Char_Node *temp = createNode(data);
	Char_Node *p = head;
	if (head == NULL)
		return temp;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
	return head;
}

void disassemblyList(Char_Node * list)
{
	while (list->next != NULL)
	{
		if (list->data >= 'a' || list->data <= 'z')
		{

		}
	}
}