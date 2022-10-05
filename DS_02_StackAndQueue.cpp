#include <stdio.h>
#include<malloc.h>
#include<stack>
#define MAXSIZE 50
typedef struct Stack {
	char data[MAXSIZE];
	int top;
	int size;
};
typedef struct Queue {
	char data[MAXSIZE];
	int front;
	int rear;
};
void InitStack(Stack& s);
void printstack(Stack s);
int push(Stack& s, char a);
int pop(Stack& s, char& a);
void initqueue(Queue& q);
void printqueue(Queue& q);
int inQ(Queue& q, char a);
int outQ(Queue& q, char& a);

int main()
{
	int f1 = 0, f2 = 0;
	Queue q;
	initqueue(q);
	char a = '*';
	while (a != '&')
	{
		scanf_s("%c", &a);
		if (a != '&')
			inQ(q, a);
	}
	//printqueue(q);

	Stack s;
	InitStack(s);
	char b='*';
	while (b != '#')
	{
		scanf_s("%c", &b);
		if (b != '#')
			push(s, b);
	}
	//printstack(s);
	
	do{
		f1=outQ(q, a);
		f2=pop(s, b);
	} while ((a == b)&&((f1!=1)&&(f2!=1)));
	if (f1 && f2)
		printf("True!");
	else
		printf("False!");
}

void InitStack(Stack &s) {
	s.top = -1;
	int init = -1;
	while (init != MAXSIZE - 1)
	{
		init++;
		s.data[init] = '\0';
	}
}
void printstack(Stack s) {
	while (s.top != -1)
	{
		printf("%c ", s.data[s.top]);
		s.top--;
	}
}

int push(Stack& s, char a) {
	if (s.top == MAXSIZE - 1)
	{
		printf("Error!");
		return -1;
	}
	s.top++;
	s.data[s.top] = a;
}

int pop(Stack &s,char &a) {
	if (s.top == -1)
		return 1;
	a = s.data[s.top];
	s.top--;
	return 0;
}
void initqueue(Queue& q) {
	q.front = q.rear = 0;
	while (q.rear != MAXSIZE - 1)
	{
		q.data[q.rear] = '\0';
		q.rear++;
	}
	q.rear = q.front;
}

void printqueue(Queue& q) {
	while (q.front % MAXSIZE != q.rear)
	{
		printf("%c ", q.data[q.front]);
			q.front = (q.front + 1) % MAXSIZE;
	}
}

int inQ(Queue& q, char a) {
	if ((q.rear + 1) % MAXSIZE == q.front)
	{
		printf("Error!");
		return -1;
	}
	q.data[q.rear]=a ;
	q.rear = (q.rear + 1) % MAXSIZE;
}
int outQ(Queue& q, char& a) {
	if (q.front == q.rear)
		return 1;
	a = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	return 0;
}

