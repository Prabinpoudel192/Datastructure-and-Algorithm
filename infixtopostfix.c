#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 30
void push(char);
char pop();
int cmp(char);
void infix_to_postfix();
bool isempty();
bool isfull();
char Stack[MAX];
char Infix[MAX];
char postfix[MAX];
char ch;
int top=-1;
int main()
{

    infix_to_postfix();
    return 0;

}
void push(char data){
    if(isfull()== true){
        printf("Stack overflow.\n");
        exit(0);
    }
    else{
    top++;
    Stack[top]=data;
    }}
char pop(){
    if(isempty()== true){
        printf("Stack Underflow.\n");
        exit(0);
    }
    else{
  char data=Stack[top];
    top--;
    return data;
}}
void infix_to_postfix(){
  printf("Please enter your expression:\n");
  scanf("%[^\n]",Infix);
    int i=0;
    int j=0;

while(Infix[i]!='\0')
{
    ch=Infix[i];
    if(ch=='(')
    {
        push(ch);
    }
    else if(ch==')'){
      while(Stack[top]!='(')
      {
        postfix[j]=pop();
        j++;
      }
      pop();

    }
    else if(ch=='^' || ch=='$' || ch=='*' || ch=='/' || ch=='+' || ch=='-')
    {
            while((isempty()==false || Stack[top]=='(') && cmp(ch)<=cmp(Stack[top]))
            {
                postfix[j]=pop();
                j++;
            }
            push(ch);
        }
        else{
            postfix[j]=ch;
            j++;
        }


    i++;
}
while(Stack[top]!='\0')
{
    if(Stack[top]!='('){
    postfix[j]=pop();
    j++;
    }
}
printf("The postfix expression is: %s\n",postfix);
}
int cmp(char ch)
{
if(ch=='^' || ch=='$')
{
    return 3;
}
else if(ch=='*' || ch=='/')
{
    return 2;
}
else if(ch=='+' || ch=='-'){
    return 1;
}
    else{
        return 0;
    }
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
