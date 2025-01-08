#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *Left;
 struct node *Right;
};
struct node *root=NULL;
struct node *Insert(struct node *root,int item)
{
 struct node *newNode;
 struct node *ptr=root;
 struct node *ptr1=NULL;
 int flag=0;

//Creation of newnode
 newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data= item;
 newNode->Left=NULL;
 newNode->Right=NULL;
 
 //insertion decision right or left?
 if(root==NULL)
   root=newNode;
 else if(item < ptr->data)
  {
     ptr->Left=Insert(ptr->Left,item);
     return ptr; 
  }
 else if(item > ptr->data)
  {
       ptr->Right=Insert(ptr->Right,item);
      return ptr;
  }
 else
  {
      flag=1;
       printf("Item already exist");
      return ptr;
  }

}

void inorder(struct node *ptr)
{
 if( ptr!=NULL)
{
 inorder(ptr->Left);
 printf("%d ",ptr->data);
 inorder(ptr->Right);
}
}

void preorder(struct node *ptr)
{
 if(ptr != NULL)
  {
 printf("%d ",ptr->data);
 preorder(ptr->Left);
 preorder(ptr->Right);
}
}

void postorder(struct node *ptr)
{
 if(ptr !=NULL)
{
 postorder(ptr->Left);
 postorder(ptr->Right);
 printf("%d ",ptr->data);
}
}


int main()
{
  int a,item;
 printf("1.Insert\n 2.Inorder\n 3.Preorder\n 4.Postorder\n 5.Exit\n");
 while(1){
 printf("Enter the choice : ");
 scanf("%d",&a);
 switch(a)
{
 case 1:
       printf("Enter the item : ");
       scanf("%d",&item);
       root=Insert(root,item);
       break;
 case 2:
        printf("inorder : ");
       inorder(root);
       break;
 case 3:
       printf("preorder : ");
       preorder(root);
       break;
 case 4:
        printf("postorder : ");
        postorder(root);
        break;
 case 5:
        exit(0);       
 default:
        printf("WRONG CHOICE");
}
}
}
