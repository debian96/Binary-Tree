#include <stdio.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node *left;
	struct Node *right;
};

struct Node * newNode(char data){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


struct Node * buildTree(char [],char [], int  , int);
void printInorder(struct Node *);
int search(char [], int, int, char);
int findlength(char []);


int main(){
	char in[100], pre[100];
	int length;

	printf("Enter The Inorder sequence\n");
	gets(in);
	printf("Enter The Preorder sequence\n");
	gets(pre);

	length = findlength(in);
	struct Node *root = buildTree(in,pre,0,length-1);
	printf("The Inorder sequence of BuildTree is:\n");
	printInorder(root);
	printf("\n");

}

int findlength(char in[]){
	int count = 0;
	for (int i = 0; in[i]!=0; ++i)
	{
		count = count+1;
	}
	return count;
}


struct Node * buildTree(char in[], char pre[], int in_start, int in_end){
	static int pre_index = 0;

	if(in_start>in_end)
		return NULL;

	//pick 1st char from preorder which is root
	char element = pre[pre_index];
	pre_index = pre_index+1;

	struct Node *node = newNode(element);

	if(in_start==in_end)
		return node;

	//search the index of the node in Inorder sequence
	int in_index = search(in, in_start, in_end, node->data);
	if (in_index ==-1)
	{
		printf("Inorder sequence Invalid\n");
	}
	

	//build the left tree
	node->left = buildTree(in, pre, in_start, in_index-1);
	//build the right tree
	node->right = buildTree(in, pre, in_index+1, in_end);

	return node;
}


int search(char in[], int in_start, int in_end, char element){

	int result = -1;
	for (int i = in_start; i <=in_end; ++i)
	{
		if (in[i] == element)
			result =i;
		
	}
	return result;
	
}


void printInorder(struct Node *t){
	if(t)
	{
		printInorder(t->left);
		printf("%c  ",t->data);
		printInorder(t->right);
	}
}















