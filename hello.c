#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int top=0;
    int sarray[20];
};

void main()
{
    int choice;
    //creating a stack
    stack *S=(stack*)malloc(sizeof(struct stack));
    printf("please select any one option);
    printf("1. add item");
    printf("2 remove item");
    printf("3 print all items");
    printf("4 edit item");
    while(choice!=4)
    printf("Enter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:{
    int newitem;
    printf("Enter the new item you want to enter in stack");
    scanf("%d",&newitem);
    s->sarray[top]=newitem;
    top++;
    }
        break;
    case 2:{
    top=top--;
    printf("Item was successfully removed.");
    }
        break;
    case 3:
        int i;
        for(i=0;i<s->top;i++)
            printf("%d \t",&s->array[i]);
        break;
    case 4:choice=4;
        break;
    }
}
