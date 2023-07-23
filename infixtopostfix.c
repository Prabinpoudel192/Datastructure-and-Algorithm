#include<stdio.h>
#include<string.h>
#define MAX 23
char infix[MAX];
char postfix[MAX];
char stack[MAX];
int comp(char x);
int top=-1;
char ch;
void infix_to_postfix(char infix[]);
void push(char);
char pop();


int main()
{
    printf("Please enter your infix expression:\n");
    scanf("%[^\n]",infix);
    infix_to_postfix(infix);
    printf("%s \n",postfix);
}
void push(char data)
{
top++;
postfix[top]=data;
}
char pop()
{
    char data=stack[top];
    top--;
    return data;
    }
void infix_to_postfix(char infix[])
{
    int i=0;
    int j=0;
    
    
    while(infix[i]!='\0'){
        ch=infix[i];
        if(ch=='(')
        {
            top++;
            stack[top]=ch;
        }
       else if(ch=='+' || ch=='-'|| ch=='*' || ch=='/' || ch=='^' || ch=='$')
        {
            while(comp(ch)<=comp(stack[top]))
            {

                postfix[j]= pop();
                j++;

            }
            top++;
            stack[top]=ch;
        }
            else if(infix[i]==')'){
                while(stack[top]!='(')
                {
                postfix[j]=pop();
                j++;
                }
                pop();
            }
            else{
                postfix[j]=ch;
                j++;
            }
        
        i++;
    }
    while(top!=-1)
{
    postfix[j]=pop();
    j++;
}
}

int comp(char x)
{
    if(x=='^' || x=='$')
    {
        return 3;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
     else if(x=='+' || x=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
}