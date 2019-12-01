#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
 
 
struct node *insert(struct node *ptr, int ikey);
int isIdentical(struct node *, struct node *);
 
int main()
{
	struct node *root=NULL,*root1=NULL,*ptr;
	int choice,k,item;
 
	while(1)
	{
		printf("\n");
		printf("1.Insert Tree 1\n");
		printf("2.Insert Tree 2\n");
		printf("3.Check for Identical\n");
		printf("4.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
 
		switch(choice)
		{
 
		case 1:
			printf("\nEnter the key to be inserted : ");
			scanf("%d",&k);
			root = insert(root, k);
			break;
 
        case 2:
			printf("\nEnter the key to be inserted : ");
			scanf("%d",&k);
			root1 = insert(root1, k);
			break;
 
        
 
        case 3:
            printf("\n");
            if(isIdentical(root,root1))
                printf("Tree 1 and 2 are Identical\n");
            else
                printf("Tree 1 and 2 are Not Identical\n");
            printf("\n");
            break;
 
        case 4:
			exit(1);
 
		 default:
			printf("\nWrong choice\n");
 
		}/*End of switch */
	}/*End of while */
 
	return 0;
 
}/*End of main( )*/
 
 
struct node *insert(struct node *ptr, int ikey )
{
	if(ptr==NULL)
	{
		ptr = (struct node *) malloc(sizeof(struct node));
		ptr->info = ikey;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if(ikey < ptr->info)	/*Insertion in left subtree*/
		ptr->lchild = insert(ptr->lchild, ikey);
	else if(ikey > ptr->info)	/*Insertion in right subtree */
		ptr->rchild = insert(ptr->rchild, ikey);
	else
		printf("Duplicate key\n");
	return(ptr);
}/*End of insert( )*/
 
 
int isIdentical( struct node *p1, struct node *p2)
{
	if(p1==NULL && p2==NULL)
		return 1;
	if(p1!=NULL && p2!=NULL && p1->info == p2->info)
		if(isIdentical(p1->lchild, p2->lchild) && isIdentical(p1->rchild, p2->rchild))
			return 1;
	return 0;
}
