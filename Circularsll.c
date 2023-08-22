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
struct node *newnode, *head, *temp;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    head = 0;
    int ch, l;
    do
    {
        printf("Please enter what you want to do:\n");
        printf("1 for creating the list.\n");
        printf("2,3 for inserting element in the begning and end of the list.\n");
        printf("4 to insert node at the specified position.\n");
        printf("5 Delete at the begning,6 at The end and 7 at the position.\n");
        printf("8 for displaying the list.\n");
        scanf("%d", &ch);
        switch (ch)
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

        printf("Do you want to do more operation?(1 for yes 2 for no).\n");
        scanf("%d", &l);
    } while (l == 1);
    return 0;
}
void create()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the value:\n");
    scanf("%d", &newnode->data);
    newnode->next = head;

    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
    count++;
}
void Insertbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = temp = newnode;

    printf("Please enter the data:\n");
    scanf("%d", &newnode->data);
    count++;
}
void display()
{
    temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}
void Insertend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the data you want to insert:\n");
    scanf("%d", &newnode->data);
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    count++;
}
void Insertpos()
{

    int a;
    int i = 1;
    printf("Please enter the position:\n");
    scanf("%d", &a);
    if (a > count)
    {
        printf("Invalid position.\n");
        exit(0);
    }
    else
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        if (a == 1)
        {
            Insertbeg();
        }
        else
        {
            temp = head;
            while (a - 1 > i)
            {
                temp = temp->next;
                i++;
            }
            if (temp->next == head)
            {
                Insertend();
            }
            else
            {
                printf("Please enter the data:\n");
                scanf("%d", &newnode->data);
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
    }
    count++;
}
void Delbeg()
{
    struct node *p;
    p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    temp = head;
    head = head->next;
    p->next = head;
    printf("Deleted element is %d.\n", temp->data);
    free(temp);
}
void Delend()
{
    temp = head;
    struct node *prevnode;
    while (temp->next != head)
    {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = head;
    printf("The deleted element is %d.\n", temp->data);
    free(temp);
}
void Delpos()
{
    struct node *nextnode;
    int a;
    int i = 1;
    printf("Please enter the position of node.\n");
    scanf("%d", &a);
    temp = head;
    if (a > count)
    {
        printf("Node postion exceeds the node count.\n");
        exit(0);
    }
    else if(a<=0){
        printf("Invalid Position.\n");
        exit(0);
    }
    else
    {
        while (a - 1 > i)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == head)
        {
            head = head->next;
            printf("Deleted element is %d.\n", temp->data);
            free(temp);
        }
        else
        {
            if (temp->next == head)
            {
                Delend();
            }
            else
            {
                nextnode = temp->next;
                temp->next = nextnode->next;
                printf("The deleted element is %d.\n", nextnode->data);
                free(nextnode);
            }
        }
    }
}
