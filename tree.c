#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *right,*left;
}tree;
tree *temp,*newnode,*parent,*root=NULL;
tree* create()
{
	int i,n;
	printf("how many tree node u want");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(tree * )malloc(sizeof(tree));
		printf("\nenter data no. %d:-",i+1);
		scanf("%d",&newnode->data);
		newnode->right=newnode->left=NULL;
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			temp=root;
			while(temp)
			{	
				parent=temp;
				if(newnode->data > temp->data)
				{
					temp=temp->right;
	
				}
				else
				{
				temp=temp->left;
				}
			}
			if(parent->data > newnode->data )
				parent->left=newnode;
			else
				parent->right=newnode;
		}
	printf("\n%d node inserted",i+1);
	}
return root;
}
void preorder(tree *root)
{
	printf("%d->",root->data);

	if(root->left)
		preorder(root->left);
		
	if(root->right)
		preorder(root->right);
}
void inorder(tree *root)
{

	if(root->left)	
		preorder(root->left);
		
	printf("%d->",root->data);
		
	if(root->right)
		preorder(root->right);
}
void postorder(tree *root)
{

	if(root->left)	
		preorder(root->left);
	if(root->right)
		preorder(root->right);
	printf("%d->",root->data);
	
}
struct node * search(int key,tree * root)
{	

	//int flag=0;	
	
	if( root!=NULL)
	{
		if(root->data==key)
		{
			printf("%d element present",root->data);
		}
		else if(root->data < key)
		return	search(key,root->right);
		else 
		return	search(key,root->left);
		
	}
	else
	{
		printf("\n Element not fount");	
	}
		
		

	//return flag;
} 				
void main()
{
	char dchoice;
	int ch,key,flag;
	while(1)
	{
		printf("\nenter choice");
		printf("\n1. create");
		printf("\n2.display");
		printf("\n3.search");
		printf("\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create();
				break;
			case 2:printf("\nin which order u want to display");
				fflush(stdin);
				printf("\n\t a.post order\n\t b.inorder\n\t c.postorder\n");
				scanf(" %c",&dchoice);
				switch(dchoice)
				{
					case 'a':preorder(root);
						break;
					case 'b': inorder(root);
						break;
					case 'c': postorder(root);
						break;					
				}
				break;
			case 3:printf("enter the element  to be searched:-");
				scanf("%d",&key);
				search(key,root);
				
				/*flag=search(key,root);
				if(flag!=1)
				printf("elemnet not found");*/
				break;
			case 4:exit(0);
		}
	}
}
			

				
