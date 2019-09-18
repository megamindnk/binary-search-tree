#include<stdio.h>
#include<stdlib.h>
typedef struct tree //create a structure to store tree and addresses
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
return root;//returns root address
}
void preorder(tree *root)//prints the tree in parent-left-right order
{
	printf("%d->",root->data);

	if(root->left)
		preorder(root->left);
		
	if(root->right)
		preorder(root->right);
}
void inorder(tree *root)//prints the tree in left-parent-right order
{

	if(root->left)	
		inorder(root->left);
		
	printf("%d->",root->data);
		
	if(root->right)
		inorder(root->right);
}
void postorder(tree *root)//prints the tree in left-right-parent order
{

	if(root->left)	
		postorder(root->left);
	if(root->right)
		postorder(root->right);
	printf("%d->",root->data);
	
}
struct tree * search(int key,tree * root)
{	
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
} 
int count(tree *temp)
{
	if( temp!=NULL )
	{
		if( (temp->right!=NULL)  && (temp->left!=NULL) )//for leaf nodes
			nlcount++;

		if( (temp->right==NULL) || (temp->left==NULL) )//for non-leafnodes
			lcount++;

	count(temp->left);
	count(temp->right);

	}
}
void mirror(struct tree *root)
{
	/*this function basically swaps the addresses of right and left nodes recursively thus creating a mirror BST*/
	if(root!=NULL)
	{
		struct tree *temp;//create a variable to store addresses
		
		mirror(root->left);//move till leaf nodes
		mirror(root->right);
	
		temp=root->left;//swap addresses
		root->left=root->right;
		root->right=temp;
	}
}


void main()
{
	char dchoice;
	int ch,key,flag;
	while(1)
	{
		printf("\n-----------------enter choice----------------");
		printf("\n 1.create");
		printf("\n 2.display");
		printf("\n 3.search");
		printf("\n 4.count the number of nodes");
		printf("\n 5.mirror the BST");
		printf("\n 6.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create();
				break;
			case 2:printf("\nin which order u want to display");
				fflush(stdin);
				printf("\n\t a.post order\n\t b.inorder\n\t c.postorder\n");
				scanf(" %c",&dchoice);//dont forget to add a space before %c otherwise it will generate a bug
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
				break;
			case 4:count(root);
				printf("\nthe number of leaf nodes are :- %d",lcount);
				printf("\nthe number of non leaf nodes are :-%d",nlcount);
				printf("\nthe total count is :-%d",nlcount+lcount);
				break;
			case 5: mirror(root);
				printf("\nmirrored successfully");
				break;
			case 6:exit(0);
		}
	}
}
			

				
