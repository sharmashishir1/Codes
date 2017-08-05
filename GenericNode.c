#include<stdio.h>

struct genericnode
{
void * data;
struct genericnode * next;
};


int main()
{
    struct genericnode * head=(struct genericnode*)malloc (sizeof(struct genericnode));
    int k=12;
    head->data=&k;
    head->next=NULL;
    printf("%d",*(int *)head->data);
    return 0;
}
