#include<stdio.h>>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode * left;
    struct tnode * right;
};

struct tnode * newnode(int data)
{
    struct tnode * temp=(struct tnode *)malloc (sizeof(struct tnode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void printtree(struct tnode * root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    printf("Element : %d \n",root->data);
    printtree(root->right);
}

morristraversal(struct tnode * root)
{
    if(root==NULL)
        return;
    struct tnode * pre,* current;

    current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
            {
                printf("Element : %d \n",current->data);
                current=current->right;
            }
        else
        {


        pre=current->left;
        while(pre->right!=NULL && pre->right!=current)
            pre=pre->right;

        if(pre->right==NULL)
        {
            pre->right=current;
            current=current->left;
        }
        else
        {
            pre->right=NULL;
            printf("Element : %d \n",current->data);
            current=current->right;
        }
        }
    }


}


int main()
{
    struct tnode *root=newnode(50);
    root->left=newnode(30);
    root->left->left=newnode(10);
    root->left->right=newnode(40);
    root->right=newnode(80);
    root->right->left=newnode(60);
    root->right->right=newnode(100);
    printtree(root);
    printf("\nMorris Traversal : \n");
    morristraversal(root);
    return 0;
}


