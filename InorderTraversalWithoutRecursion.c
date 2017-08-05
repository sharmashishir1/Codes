#include<stdio.h>
#include<stdlib.h>

 struct tnode
{
    int data;
   struct tnode * left;
   struct tnode * right;
};

//stack definitions
struct snode
{
    struct tnode * data;
    struct snode * next;
};

struct tstack
{
    struct snode * top;
};

struct tstack * createStack()
{
    struct tstack * temp=(struct tstack *)malloc(sizeof(struct tstack));
    temp->top==NULL;
    return temp;
}

 struct snode * newsnode(struct tnode * ttemp)
 {
     struct snode *temp=(struct snode *)malloc(sizeof(struct snode));
     temp->data=ttemp;
     temp->next=NULL;
     return temp;
}

void pushitem(struct tstack * stackp,struct tnode * temp)
{
    //case for first element
    if(stackp->top==NULL)
    {
        stackp->top=newsnode(temp);
        //stackp->top->data=temp;
        return ;
    }
    else
    {
        struct snode * tempsnode=newsnode(temp);
        //tempsnode->data=temp;
        tempsnode->next=stackp->top;
        stackp->top=tempsnode;
    }
}


void popitem(struct tstack * toptstack)
{
    struct snode *temp=toptstack->top;
    toptstack->top=toptstack->top->next;
    free(temp);
}


struct tnode * newtnode(int data)
{
    struct tnode * temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void printtree(struct tnode * root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    printf("%d \t",root->data);
    printtree(root->right);
}

int main()
{
    struct tnode *root=newtnode(50);
    root->left=newtnode(30);
    root->left->left=newtnode(10);
    root->left->right=newtnode(40);
    root->right=newtnode(80);
    root->right->left=newtnode(60);
    root->right->right=newtnode(100);
    printtree(root);
    printf("\nPrinting data without recursion using stack\n");
   //code begins
    struct tstack * treestack=createStack();
    struct tnode* current=root;
    while(current!=NULL)
    {
        pushitem(treestack,current);
        current=current->left;
        while(current==NULL && treestack->top!=NULL)
        {
            printf("Element : %d \n",treestack->top->data->data);
            current=treestack->top->data->right;
            popitem(treestack);

            //printf("Element : %d \n",treestack->top->data->data);
        }

    }
    return 0;
}

