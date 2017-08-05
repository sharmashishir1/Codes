#include<stdio.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* newnode(int item)
{
    struct node* tempnode=(struct node*)malloc(sizeof(struct node));
    tempnode->data=item;
    tempnode->left=NULL;
    tempnode->right=NULL;
    return tempnode;
};

void inordertree(struct node *root)
{
    if(root==NULL)
        return;
    inordertree(root->left);
    printf("%d",root->data);
    inordertree(root->right);
}

int heightoftree(struct node*root)
{
    if(root==NULL)
        return 0;
    else if(heightoftree(root->left)>heightoftree(root->right))
        return (1+heightoftree(root->left));
     else
        return (1+heightoftree(root->right));
}

void levelordertraversal(struct node* root, int level)
{
    if(root==NULL)
        return;
    else if(level==1)
    {
        printf("%d",root->data);
        //printf("%d",root->right);
    }
    else if(level>1)
    {
        levelordertraversal(root->left,level-1);
        levelordertraversal(root->right,level-1);
    }
}

int main()
{

    struct node* root=newnode(4);
    root->left=newnode(2);
    root->left->left=newnode(1);
    root->left->right=newnode(3);
    root->right=newnode(6);
    root->right->left=newnode(5);
    root->right->right=newnode(7);
    printf(" Inorder traversal is : ");
    inordertree(root);
    printf("\n");
    printf("\n LevelOrder traversal is : ");
    int treeheight=heightoftree(root);
    int i;
    for(i=1;i<=treeheight;i++)
    {
        levelordertraversal(root,i);
    }

    return 0;

}
