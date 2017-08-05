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


int searchforindex(int inorder[], int elem, int start, int end)
{

	int i;
	for(i=start;i<=end; i++){
		if(inorder[i]== elem)
			return i;
	}
	return -1;
}

struct tnode * createTree(int inorder[], int preorder[],int startindex, int endindex)
{
    static int preindex=0;
    if(startindex>endindex)
        return NULL;
    struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=preorder[preindex++];
    if(startindex==endindex)
    {
        temp->left=NULL;
        temp->right=NULL;
       return temp;
    }

    int index=searchforindex(inorder,temp->data,startindex,endindex);
    temp->left=createTree(inorder,preorder,startindex,index-1);
    temp->right=createTree(inorder,preorder,index+1,endindex);
    return temp;
}



int main()
{
//    struct tnode *root=newnode(50);
//    root->left=newnode(30);
//    root->left->left=newnode(10);
//    root->left->right=newnode(40);
//    root->right=newnode(80);
//    root->right->left=newnode(60);
//    root->right->right=newnode(100);
//    printtree(root);
    printf("\nTree from in and pree traversals : \n");
    int inorder[]={10, 12, 20, 30, 37, 40, 45};
    int preorder[]={30, 20, 10, 12, 40, 37, 45};
    struct tnode * root2=createTree(inorder,preorder,0,6);
    printtree(root2);
   // morristraversal(root);
    return 0;
}


