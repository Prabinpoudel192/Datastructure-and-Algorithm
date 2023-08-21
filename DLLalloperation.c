#include <stdio.h>
#include <stdlib.h>
void create();
void Insertbeg();
void Insertend();
void Insertpos();
void Delbeg();
void Delend();
void Delpos();
void display();
int count = 0;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *newnode, *temp;
int main()
{
    int k, l;
    head = 0;
    do
    {
        printf("please enter what you want to do.\n");
        printf("1 for adding node in the list.\n");
        printf("2 for inserting the node in the begning.\n");
        printf("3 for inserting node at the end.\n");
        printf("4 for inserting node after the specified position.\n");
        printf("5 for deleting the node at begning.\n");
        printf("6 for deleting the node at the end.\n");
        printf("7 for deleting the node of specified pos.\n");
        printf("8 for displaying the elements of the list.\n");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            create();
            break;
        case 2:
            Insertbeg();
            break;
        case 3:
            Insertend();
            break;
        case 4:
            Insertpos();
            break;
        case 5:
            Delbeg();
            break;
        case 6:
            Delend();
            break;
        case 7:
            Delpos();
            break;
        case 8:
            display();
            break;
        }
        printf("Do you want to do more operation:\n");
        scanf("%d", &l);
    } while (l == 1);
    return 0;
}
void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
    count++;
}
void display()
{
    temp = head;
    while (temp != 0)
    {

        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Insertbeg()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = temp;
    temp->prev = newnode;
    head = newnode;
    count++;
}
void Insertend()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the data you want to insert.\n");
    scanf("%d", &newnode->data);
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
    temp = newnode;
    count++;
}
void Insertpos()
{
    int a;
    int i = 1;
    printf("Please enter the position after which you want to insert the node:\n");
    scanf("%d", &a);
    if (a > count)
    {
        printf("Position exceeds the limit of list.\n");
        exit(0);
    }
    else if (a == 1)
    {
        Insertbeg();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Please enter the data:\n");
        scanf("%d", &newnode->data);
        temp = head;
        while (a > i)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        temp = newnode->next;
        temp->prev = newnode;
        count++;
    }
}
void Delbeg()
{
    head = head->next;
    free(temp);
    temp = head;
    count--;
}
void Delend()
{
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp = temp->prev;
    free(temp->next);
    temp->next = 0;
    count--;
}
void Delpos()
{
    temp = head;
    int a;
    int i = 1;
    printf("Please enter the position of node which you want to delete:\n");
    scanf("%d", &a);
    if (a > count)
    {
        printf("The position exeeds the count of nodes:\n");
        exit(0);
    }
    else if (a == 1)
    {
        Delbeg();
    }
    else
    {

        while (a-1>i)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next==0)
        {
            Delend();
        }
        else
        {
            struct node *a;
            a = temp->next;
            a = a->next;
            a->prev = temp;
            free(temp->next);
            temp->next = a;
            count--;
        }
    }
}
