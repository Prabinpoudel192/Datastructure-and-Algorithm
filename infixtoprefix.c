#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 30
int top=-1;
void infix_to_prefix();
void push(char);
char pop();
int cmp(char);
bool isempty();
bool isfull();
char prefix[MAX];
char stack[MAX];
char infix[MAX];
char ch;
int main(){
infix_to_prefix();
return 0;
}

void infix_to_prefix(){
int j=0;
printf("Please enter your expression.\n");
scanf("%[^\n]",infix);
int k=strlen(infix)-1;
while(infix[k]!='\0')
{
    ch=infix[k];
    if(ch==')'){
        push(ch);
        }
    else if(ch=='('){
        while(stack[top]!=')'){
        prefix[j]=pop();
        j++;
    }
    pop();
    }
    else if(ch=='^' || ch=='$' || ch=='*' || ch=='/' || ch=='+' || ch=='-')
    {
        while((isempty()==false || stack[top]!=')') && (cmp(ch)<cmp(stack[top])))
        {
           prefix[j]=pop();
           j++;
        }
        push(ch);
    }
    else{
        prefix[j]=ch;
        j++;
    }
    k--;
}

while(stack[top]!='\0')
{
    if(stack[top]!=')')
    {
        prefix[j]=pop();
        j++;
    }
}
j--;
while(prefix[j]!='\0'){
    printf("%c",prefix[j]);
    j--;
}
printf("\n");
}
int cmp(char ch){
if(ch=='^' || ch=='$')
{
    return 4;
}
else if(ch=='*' || ch=='/')
{
    return 3;
}
else if(ch=='+' || ch=='-')
{
    return 2;
}
else {
    return 1;
}
}
char pop(){
    if(isempty()==true){
        printf("Stack underflow!! Terminating the operation.\n");
        exit(0);
    }
    else{
  char data=stack[top];
  top--;
  return data;
    }
}
void push(char ch){
    if(isfull()==true){
        printf("Stack Overflow!! Terminating the operation.\n");
        exit(0);
    }
    else{
    top++;
    stack[top]=ch;
}}
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
