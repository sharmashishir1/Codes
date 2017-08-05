#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int capacity;
    int* array;
};


struct stack * createStack(int capacity)
{
    struct stack * stack1=(struct stack *)malloc(sizeof(struct stack));
    stack1->capacity=capacity;
    stack1->top=-1;
    stack1->array=malloc(capacity * sizeof(int));
    return stack1;
};

void push(struct stack * head,int data)
{
    if(head->top==head->capacity)
    {
        printf("Stack is full");
    }
    else
    {
        head->array[++head->top]=data;
        printf("\nInsertion was successful. %d",data);
    }
}

void pop(struct stack* head)
{
    if(head->top==-1)
        printf("Stack is already Empty.");
    else
    {

        head->array[head->top]=NULL;
        head->top--;
        printf("\nitem was successfully removed");
    }

}

printstack(struct stack * head)
{
    int top=head->top;
    while(top!=-1)
    {
        printf("\n Element : %d",head->array[top--]);
    }
}

int main()
{
    struct stack * head=createStack(10);
    push(head,10);
    push(head,20);
    push(head,15);
    push(head,25);
    printstack(head);
    pop(head);
    printstack(head);
    pop(head);
    printstack(head);
    return 0;
}
