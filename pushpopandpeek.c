#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
char Stack[MAX];
char g;
void push();
void pop();
void peek();
void display();
bool isempty();
bool isfull();
int top=-1; 
int main(){
    int ch,m;
do{
printf("Please enter your choice.(1 for push,2 for pop,3 for peek,4 for display the array).\n");
scanf("%d",&ch);
switch(ch){
case 1:
getchar();
push();
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
}
printf("\nDo you want to do more operarion.(1 for yes and 0 for no).\n");
scanf("%d",&m);
}while(m==1);
return 0;
}
void push(){
    printf("Please enter the element:\n");
    scanf("%c",&g);
    if(isfull()==true){
        printf("Stack overflow.");
        exit(0);
    }
    else{
        top++;
        Stack[top]=g;
     printf("The pushed element is %c.\n",Stack[top]);
      
    }
}
void pop(){
    char h;
    if(isempty()==true){
        printf("Stack Underflow.");
        exit(0);
    }
    else{
        h=Stack[top];
        top--;
        printf("The popped element is %c.\n",h);

    }
}
void display(){
   int i;
   for(i=0;i<=top;i++){
   printf("%c",Stack[i]);
    }
     printf("\n");
   
}
void peek(){
    printf("The last element in the stack is %c.\n",Stack[top]);
}
bool isempty(){
if(top==-1){
    return true;
}
else{
    return false;
}
}
bool isfull(){
if(top==MAX-1){
    return true;
}
else{
    return false;
}


}
