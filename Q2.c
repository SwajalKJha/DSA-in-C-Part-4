/*
Q2. Write a C/C++ program to implement stack data structure using
array. Implement below metioned functions.
a) push b) pop c) peep d) displayStack e)isStackFull
f) isStackEmpty
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int *, int *, int);
int pop(int *, int *);
int peep(int *, int *);
void display(int *);
void isStackFull(int *);
void isStackEmpty(int *);

int main()
{
	int arr[SIZE], top = -1, choice, ele, ret;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = -99;
	}
	while (1)
	{
		printf("\n*************************\n");
		printf(" 1. Push\n 2. Pop\n 3. Peep\n 4. Display\n 5. isStackFull\n 6. isStackEmpty\n 7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter Element to Push: ");
			scanf("%d", &ele);
			push(arr, &top, ele);
			break;
		case 2:
			ret = pop(arr, &top);
			if (ret != -77)
			{
				printf("Poped item = %d\n", ret);
			}
			else
			{
				printf("Nothing to Pop");
			}
			break;
		case 3:
			ret = peep(arr, &top);
			printf("Element on Top is: %d", ret);
			break;
		case 4:
			printf("Stack : ");
			display(arr);
			break;
		case 5:
			isStackFull(&top);
			break;
		case 6:
			isStackEmpty(&top);
			break;
		case 7:
			exit(1);
		default:
			printf("Invalid Choice");
		}
	}
}

void push(int *arr, int *top, int ele)
{
	if (*top == SIZE - 1)
	{
		printf("Stack is Full");
		return;
	}

	*top = *top + 1;
	arr[*top] = ele;
}
int pop(int *arr, int *top)
{
	if (*top == -1)
	{
		printf("Stack is Empty");
		return -77;
	}

	int temp = arr[*top];
	arr[*top] = -99;
	*top = *top - 1;
	return temp;
}
int peep(int *arr, int *top)
{
	return arr[*top];
}
void display(int *arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("| %02d |", arr[i]);
	}
}
void isStackFull(int *top)
{
	if (*top == SIZE - 1)
	{
		printf("Stack is Full");
		return;
	}
	else
	{
		printf("Stack is not Full");
	}
}
void isStackEmpty(int *top)
{
	if (*top == -1)
	{
		printf("Stack is Empty");
		return;
	}
	else
	{
		if (*top == SIZE - 1)
		{
			printf("Stack is Full");
			return;
		}
		else
		{
			printf("Stack is not Empty");
		}
	}
}
