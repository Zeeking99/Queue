#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE],rear= -1;
const int front = 0;
	
void peek();
int isempty();
int isfull();
void enqueue(int);
int dequeue();
void display();
void lefttraverse();
void righttraverse();

int main()
{
	int option,number;

	printf("A QUEUE OF 5 ELEMENTS IS CREATED\n");
	printf("\n----------SELECT ANY OF THE OPTIONS----------\n");
	printf("1. PEEK\n");
	printf("2. ENQUEUE\n");
	printf("3. DEQUEUE\n");
	printf("4. DISPLAY\n");
	printf("5. EXIT\n");

	do
	{
		printf("ENTER AN OPTION: ");
		scanf(" %d", &option);

		switch(option)
		{
			case 1:
				peek();
			break;
			
			case 2:
				printf("Enter the number you want to insert: ");
				scanf("%d", &number);
	
				enqueue(number);				
			break;

			case 3: 
				number = dequeue();
				printf("The number deleted from the queue is: %d\n",number);
			break;
			
			case 4:
				display();
			break;
	
			case 5:
				printf("----------THANK YOU----------\n");
				exit(0);
			
			default:
				printf("ENTER A VALID OPTION\n");
		}
	}while(1);

	return 0;
}

void peek()
{
	if(isempty())
	{
		printf("THE QUEUE IS EMPTY\n");
		return;
	}

	printf("\nThe first element is: %d\n",queue[front]);
	return;
}

int isempty()
{
	if(rear == -1)
		return 1;
	else
		return 0;
}

int isfull()
{
	if(rear == SIZE-1)
		return 1;
	else
		return 0;
}

void enqueue(int n)
{
	if(isfull())
	{
		printf("THE QUEUE IS FULL\n");
		return;
	}

	queue[++rear] = n;	
}

int dequeue()
{
	int n;
	
	if(isempty())
	{
		printf("THE QUEUE IS EMPTY\n");
		return 0;
	}

	n = queue[front];
	lefttraverse();

	return n;
}

void display()
{
	int i;

	putchar('\n');

	for(i=0;i<=rear;i++)
		printf("\t%d",queue[i]);

	printf("\n\n");

	return;
}

/*
void righttraverse()
{
	int i,temp = rear+1;

	for(i=rear; i>=0 && temp>=1; i--,temp--)
	{
		queue[temp] = queue[i];
		queue[i] = 0;
	}
	
	rear++;

	return;
}
*/

void lefttraverse()
{
	int i = front ,temp;

	for(temp=front+1; front <= rear && i < rear; temp++,i++)
	{
		queue[i] = queue[temp];
		queue[temp] = 0;
	}

	rear--;

	return;
}	
