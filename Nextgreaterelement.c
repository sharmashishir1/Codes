#include<stdio.h>
#include<stdlib.h>

struct Tstack
{
    int top;
    int capacity;
    int *stackarr;
};

struct Tstack* createStack(int capacity)
{
    struct Tstack * tempstack=(struct Tstack*)malloc(sizeof(struct Tstack));
    tempstack->top=-1;
    tempstack->capacity=capacity;
    tempstack->stackarr=(int *)malloc(capacity * sizeof(int));
    return tempstack;
}

void pushitem(struct Tstack* tstack, int data)
{
    //overflow condition check
    if(tstack->top==tstack->capacity)
        return;
    tstack->stackarr[++tstack->top]=data;
}


void popitem(struct Tstack* tstack)
{
    //condition for empty stack
    if(tstack->top==tstack->capacity-1)
        return;
     tstack->stackarr[tstack->top--];
}

int main()
{
    int arr[]={5,2,9,7,15,4,1};
    int noe=sizeof(arr)/sizeof(int);
    struct Tstack * mystack=createStack(noe);
    pushitem(mystack,arr[0]);
    int i;
    for( i=1;i<noe;i++)
    {
        if(mystack->stackarr[mystack->top]<arr[i])
        {
            while(mystack->stackarr[mystack->top]<arr[i])
          {
                printf("Max element for  %d is %d\n",mystack->stackarr[mystack->top],arr[i]);
                if(mystack->top==-1)
                    break;
                popitem(mystack);
          }

        }
        pushitem(mystack,arr[i]);

    }
    while(mystack->top!=-1)
    {
        printf("Max element for  %d is -1(NULL)\n",mystack->stackarr[mystack->top]);
        popitem(mystack);
    }
    return 0;
}
