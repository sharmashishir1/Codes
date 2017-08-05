#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

int main(){
    int i=0,noe1,noe2,noe3;
    struct node *temp,*start1,*temp2,*start2,*temp1,*start3,*temp3;
    temp=(struct node*)malloc(sizeof(struct node));
    start1=temp;
    printf("Enter the no of elements in First linked list");
    scanf("%d",&noe1);
    printf("Enter the %d element",i);
    scanf("%d",&temp->data);
    i++;
    temp2=temp;
    while(i!=noe1){
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the %d element",i);
        scanf("%d",&temp->data);
        i++;
        temp2->next=temp;
        temp2=temp;

    }
temp->next=NULL;

//entering the second linked list
    i=0;
    temp=(struct node*)malloc(sizeof(struct node));
    start2=temp;
    printf("Enter the no of elements in Second linked list");
    scanf("%d",&noe2);
    printf("Enter the %d element",i);
    scanf("%d",&temp->data);
    i++;
    temp2=temp;
    while(i!=noe2){
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the %d element",i);
        scanf("%d",&temp->data);
        i++;
        temp2->next=temp;
        temp2=temp;

    }
temp->next=NULL;

//manipulating data elements

temp=(struct node *)malloc(sizeof(struct node));
start3=temp;
noe3=noe1+noe2;
while(noe3>0)
{
    if((temp2->data)>(temp1->data))
    {
        temp->data=temp1->data;
        temp1=temp1->next;
    }
    else
    {
        temp->data=temp2->data;
        temp2=temp2->next;
    }
    if(noe3==noe1+noe2)  temp3=temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(noe3!=noe1+noe2)  temp3=temp;
    temp3->next=temp;
    noe3--;
}
temp3->next=NULL;


//printing the entered elements

temp=start3;
while(temp!=NULL)
{
    printf("%d \t",temp->data);
    temp=temp->next;
}

return 0;
}
