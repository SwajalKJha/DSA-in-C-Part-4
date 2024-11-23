/*
Q3. Write a C/C++ program to implement queue data structure using
array. Implement below metioned functions.
a) add b) delete c) peep d) displayQueue e)isQueueFull
f) isQueueEmpty
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void enqueue(int *, int *, int *, int);
int dequeue(int *, int *, int *);
int peep(int *, int *);
void display(int *);
void isQueueFull(int *, int *);
void isQueueEmpty(int *, int *);

int main()
{
	int arr[SIZE], front = -1, rear = -1, choice, ele, ret;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = -99;
	}
	while (1)
	{
		printf("\n*************************\n");
		printf(" 1. Enqueue\n 2. Dequeue\n 3. Peep\n 4. Display\n 5. isQueueFull\n 6. isQueueEmpty\n 7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter Element to enqueue: ");
			scanf("%d", &ele);
			enqueue(arr, &front, &rear, ele);
			break;
		case 2:
			ret = dequeue(arr, &front, &rear);
			if (ret != -77)
			{
				printf("Item Dequeued = %d\n", ret);
			}
			else
			{
				printf("Nothing to Dequeue");
			}
			break;
		case 3:
			ret = peep(arr, &front);
			printf("Element on Front is: %d", ret);
			break;
		case 4:
			printf("Queue : ");
			display(arr);
			break;
		case 5:
			isQueueFull(&front, &rear);
			break;
		case 6:
			isQueueEmpty(&front, &rear);
			break;
		case 7:
			exit(1);
		default:
			printf("Invalid Choice");
		}
	}
}

void enqueue(int *arr, int *front, int *rear, int ele)
{
	if (*rear == SIZE - 1)
	{
		printf("Queue is Full\n");
		return;
	}
	*rear = *rear + 1;
	arr[*rear] = ele;
	if (*front == -1)
	{
		*front = 0;
	}
}
int dequeue(int *arr, int *front, int *rear)
{
	if (*front == -1)
	{
		printf("Queue is Empty\n");
		return -77;
	}

	int temp = arr[*front];
	arr[*front] = -99;
	if (*front == *rear)
	{
		*front = *rear = -1;
	}
	else
	{
		*front = *front + 1;
	}
	return temp;
}
int peep(int *arr, int *front)
{
	return arr[*front];
}
void display(int *arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("| %02d |", arr[i]);
	}
}
void isQueueFull(int *front, int *rear)
{
	if ((*rear == SIZE - 1) && (*front == 0))
	{
		printf("Queue is Full");
		return;
	}
	else
	{
		printf("Queue is not Full");
	}
}
void isQueueEmpty(int *front, int *rear)
{
	if (*front == -1)
	{
		printf("Queue is Empty");
		return;
	}
	else
	{
		if (*rear == SIZE - 1)
		{
			printf("Queue is Full");
			return;
		}
		else
		{
			printf("Queue is not Empty");
		}
	}
}
