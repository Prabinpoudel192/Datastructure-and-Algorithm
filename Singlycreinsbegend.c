#include<stdio.h>
#include<stdlib.h>
void create();
void Insertbeg();
void Insertend();
void Insertpos();
void Delbeg();
void Delend();
void Delpos();
void display();
int count=0;
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
        printf("4 to insert element after the specified position.\n");
        printf("5 Delete at the begning,6 at The end and 7 at the position.\n");
        printf("8 for displaying the list.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            count++;
            break;
        case 2:
            Insertbeg();
            count++;
            break;
        case 3:
            Insertend();
            count++;
            break;
        case 4:
        Insertpos();
        count++;
        break;
        case 5:
        Delbeg();
        count--;
        break;
        case 6:
        Delend();
        count--;
        break;
        case 7:
        Delpos();
        count--;
        break;
        case 8:
            display();
            break;
        }

        printf("Do you want to do more operation?(1 for yes 2 for no).\n");
        scanf("%d", &l);
    } while (l != 2);
    return 0;
}
void create()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the value:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void Insertbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = head;
    head = temp = newnode;
    printf("Please enter the data:\n");
    scanf("%d", &newnode->data);
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
void Insertend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the data you want to insert:\n");
    scanf("%d", &newnode->data);
    temp = head;
    while (temp->next!= 0)
    {
        temp = temp->next;
    }
    temp-> next= newnode;
}
void Insertpos()
{
    
    int a;
    int i=1;
    printf("Please enter the position:\n");
    scanf("%d",&a);
    if(a>count){
        printf("Invalid position.\n");
        exit(0);
    }
    else{
        
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Please enter the data:\n");
        scanf("%d",&newnode->data);
        temp=head;
        while(a>i){
           temp=temp->next;
           i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
    }
}
void Delbeg(){
    temp=head;
    head=head->next;
    printf("Deleted element is %d.\n",temp->data);
    free(temp);
}
void Delend(){
    temp=head;
    struct node *prevnode;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=0;
    printf("The deleted element is %d.\n",temp->data);
    free(temp);
}
void Delpos(){
    struct node *nextnode;
    int a;
    int i=1;
    printf("Please enter the position of node.\n");
    scanf("%d",&a);
     temp=head;
     if(a>count){
        printf("Node postion exceeds the node count.\n");
       exit(0);
     }
     else{
        
    while(a-1>i){
        temp=temp->next;
        i++;
    }
    if(temp==head){
    head=head->next;
    printf("Deleted element is %d.\n",temp->data);
    free(temp);

    }
    else{
    nextnode=temp->next;
    temp->next=nextnode->next;
    printf("The deleted element is %d.\n",nextnode->data);
    free(nextnode);
     }
     }
    }

