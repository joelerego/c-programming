#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} node;

//Tree Traversals  - inorder(), postorder() and preorder()

void inorder(node* root) {
	if(root != NULL) {
		inorder(root -> left);
		printf("%c ", root -> data);
		inorder(root -> right);
	}
}

void preorder(node* root) {
	if (root != NULL) {
		printf("%c ", root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

void postorder(node* root) {
	if (root != NULL) {
		postorder(root -> left);
		postorder(root -> right);
		printf("%c ", root -> data);
	}
}

node* initialize(char c, node* left, node* right) {
	node* t = malloc(sizeof(node));
	t -> data = c;
	t -> left = left;
	t -> right = right;
	return t;
}

node* create(char a[], int i, int size) {
	if ( i >= size)
		return NULL;
	else 
		return (initialize(a[i], 
		                  create(a, 2*i+1, size), 
		                  create(a, 2*i+2, size)));
}

int main() {
	char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	node* root = create(a, 0, 7);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return (0);
}
