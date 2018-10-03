#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
int isEmpty();
void push();
void pop();
void peek();
struct Node
{
	int data;
	struct Node* next;
};
struct Node* newNode(int data)
{
	struct Node* stack = (struct Node*) malloc(sizeof(struct Node));
	stack->data = data;
	stack->next = NULL;
	return stack;
}
int main()
{
	int inp,item;
	struct Node* root = NULL;
	do
	{
		printf("Input 1 to push, 2 to pop, 3 to peek, 4 to exit\n");
		scanf("%d",&inp);
		if(inp==1)
		{
			printf("Enter value to push\n");
			scanf("%d",&item);
			push(&root, item);
		}
		else if(inp==2)
		{
			pop(&root);
		}
		else if(inp==3)
		{
			peek(root);
		}
		else
			printf("Wrong input\n");
	}while(inp!=4);
	return 0;
}
int isEmpty(struct Node* root)
{
	return !root;
}
void push(struct Node** root, int data)
{
	struct Node* stack = newNode(data);
	stack->next = *root;
	*root = stack;
}
void pop(struct Node** root)
{
	if(isEmpty(*root))
	{
		printf("Underflow\n");
		return;	
	}
	struct Node* temp = *root;
	*root = (*root)->next;
	printf("%d is popped\n",temp->data);
	free(temp);
}
void peek(struct Node* root)
{
	if(isEmpty(root))
	{
		printf("It's empty dude\n");
		return;
	}
	printf("%d is the top element\n",root->data);
}
