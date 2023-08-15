#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int arr[MAX];
int length;
void array();
void insert();
void traversal();
void delete();
int main(){
    int a,k;
    do{
    printf("Please enter what you want to do.(1 for insert element in array,2 for insert element in specified place,3 for deleting the specified element & 4 for printing the elements.)\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        array();
        break;

        case 2:
        insert();
        break;

        case 3:
        delete();
        break;

        case 4:
        traversal();
        break;
    }
    printf("Do you want more operation??(1 for yes and 2 for no).\n");
    scanf("%d",&k);
    }while(k==1);
    return 0;
}
void array(){
    int b,i;
    printf("Please enter the size of array:\n");
    scanf("%d",&b);
    if(b<0 || b>MAX-1)
    {
        printf("Given input exceeds the limit of array.\n");
    }
    else{
    length=b;
    for(i=0;i<b;i++){
        scanf("%d",&arr[i]);
    }}
}
void insert(){
    int b,i;
    
    printf("Please specify the position of array where you want to insert the array.\n");
    scanf("%d",&b);
    if(b<0 || b>length-1){
        printf("Given input exceeds the array limit.\n");
    }
    else{
    for(i=length;i>=b;i--){
        arr[i+1]=arr[i];
        }
    printf("Please enter the element you want to enter:\n");
    scanf("%d",&arr[b]);
    length++;
}}
void traversal(){
    int i;
    for(i=0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void delete(){
    int b;
    printf("Please enter the position of array you want to delete:\n");
    scanf("%d",&b);
    if(b<0 || b>length-1){
        printf("No element found to delete.\n");
    }
    else{
        int i;
        for(i=b;i<length;i++)
        {
        arr[i]=arr[i+1];
        }
        length--;
    }
}
