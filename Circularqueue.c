#include<stdio.h>
#include<stdlib.h>
#define MAX 4
char queue[MAX];
int rear=-1;
int front=-1;
void enqueue(char);
void dequeue();
void peek();
void display();
int main()
{
    enqueue('5');
    enqueue('6');
    enqueue('7');
    enqueue('8');
    peek();
    display();
    dequeue();
    peek();
    dequeue();
    enqueue('4');
    peek();
    display();
    return 0;
}
void enqueue(char data)
{
    if(rear==-1 && front==-1){
        rear++;
        front++;
        queue[rear]=data;
        printf("The element enqueued is %c\n",queue[rear]);
    }
    else if(((rear+1)%(MAX))==front)
    {
        printf("The queue is full.\n");
        exit(0);
    }
    else
    {
        rear=(rear+1)%(MAX);
        queue[rear]=data;
        printf("The element enqueued is %c\n",queue[rear]);
    }
   
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("The queue is empty.\n");
        exit(0);
    }
    else if(front==rear){
        printf("The deqeued element is %c.\n",queue[front]);
        front=-1;
        rear=-1;

    }
    else{
        printf("The dequeued element is %c.\n",queue[front]);
        front=(front+1)%MAX;
        
    }}
    void peek()
    {
        printf("The element at the end is %c\n",queue[rear]);
    }
    void display(){
        printf("The remaining elements in the queue are:\n");
        int a=front;
        int b=rear;
        while(a!=b){
        printf("%c ",queue[a]);
        a=(a+1)%MAX;
      }
      printf("%c",queue[a]);
      printf("\n");
    }

