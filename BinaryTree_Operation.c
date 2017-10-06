#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node * newNode(int data){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}



void printInorder(struct Node *);
void printPreorder(struct Node *);
void printPostorder(struct Node *);
int size(struct Node *);
int height(struct Node *);
int countLeaveNodes(struct Node *);
int countFullNodes(struct Node *);
int width(struct Node *,int);
int getWidth(struct Node *,int );








int main(){


	struct Node *root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(50);
	root->left->left = newNode(10);
	root->left->right = newNode(22);
	root->left->left->left = newNode(4);
	root->left->left->right = newNode(12);
	root->left->right->left = newNode(18);
	root->left->right->right = newNode(24);
	root->right->left = newNode(35);
	root->right->right = newNode(70);
	root->right->left->left = newNode(31);
	root->right->left->right = newNode(44);
	root->right->right->left = newNode(66);
	root->right->right->right= newNode(90);





	int choice,s,h,l,f,w;

	while(1){

		printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
                printf("\n 1.Inorder Traversal     \n");
                printf("\n 2.Preorder Traversal    \n");
                printf("\n 3.Postorder Traversal   \n");
                printf("\n 4.Size Of Tree   \n");
                printf("\n 5.Height Of Tree    \n");
                printf("\n 6.Total No Of Leave Nodes  \n");
                printf("\n 7.Total No Of Non Leave Nodes    \n");
                printf("\n 8.Total No Of Full Nodes    \n");
                printf("\n 9.Total Width Of Tree    \n");


         
                printf("\n 10.Exit       \n");
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");

		switch(choice)
		{
			case 1:
				printInorder(root);
				break;
			case 2:
				printPreorder(root);
				break;
			case 3:
				printPostorder(root);
				break;
			case 4:
				s = size(root);
				printf("Size Of Tree:-\t%d\n",s);
				break;
			case 5:
				h = height(root);
				printf("Height Of Tree:-\t%d\n",h);
				break;
			case 6:
				l = countLeaveNodes(root);
				printf("Total No Of Leave Nodes:-\t%d\n",l);
				break;
			case 7:
				printf("Total No Of Non Leave Nodes:-\t%d\n",s-l);
				break;
			case 8:
				f = countFullNodes(root);
				printf("Total No Of Full Nodes:-\t%d\n",f);
				break;
			case 9:
				w = width(root,height(root));
				printf("Total Width Of Tree:-\t%d\n",w);
				break;
            case 10:
                exit(0);
                break;
            default:
                printf("\n Wrong Choice:\n");
                break;
		}
	}
}




void printInorder(struct Node *t){
	if(t)
	{
		printInorder(t->left);
		printf("%d\t",t->data);
		printInorder(t->right);
	}
}

void printPreorder(struct Node *t){
	if (t)
	{
		
		printf("%d\t",t->data);
		printPreorder(t->left);
		printPreorder(t->right);
	}
}

void printPostorder(struct Node *t){
	if (t)
	{
		
		printPostorder(t->left);
		printPostorder(t->right);
		printf("%d\t",t->data);
	}
}

int size(struct Node *t){
	if(t==NULL){
		return 0;
	}else{
		return 1+(size(t->left)+size(t->right));
	}
}

int height(struct Node *t){
	if (!t)
	{
		return 0;
	}else if(!t->left && !t->right){
		return 0;
	}else{
		int a = height(t->left);
		int b = height(t->right);
		return 1+((a>b)?a:b);
	}
}

int countLeaveNodes(struct Node *t){
	if (!t)
	{
		return 0;
	}else if(!t->left && !t->right){
		return 1;
	}else{
		return countLeaveNodes(t->left)+countLeaveNodes(t->right);
	}
}

int countFullNodes(struct Node *t){
	if (!t)
	{
		return 0;
	}else if(!t->left && !t->right){
		return 0;
	}else{
		return countFullNodes(t->left)+countFullNodes(t->right)+((t->left!=NULL && t->right!=NULL)?1:0);
	}
}

int width(struct Node *t,int h){
	int max_width = 0;
	int width;


	for (int i = 1; i <=h+1; ++i)
	{
		width = getWidth(t,i);
		if (width>max_width)
			max_width = width;
	}
	return max_width;
}

int getWidth(struct Node *t,int l){
	if (t==NULL)
	{
		return 0;
	}else if(l==1){
		return 1;
	}else if(l>1){
		return (getWidth(t->left,l-1) + getWidth(t->right,l-1));
	}
}





