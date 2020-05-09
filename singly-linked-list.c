#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

/* The program performs the followings operations 
 * on a singly linked list: insert_at_start(), 
 * insert_at_end(), insert_at_pos(), delete_at_start(), 
 * delete_at_end(), delete_at_pos(), print_all_nodes()
 */

node* insert_at_start(node* head, int d) {
	node* new_node = malloc(sizeof(node));
	new_node -> data = d;
	new_node -> next = head;
	head = new_node;
	return head;
} 

node* insert_at_end(node* head, int d) {
	node* new_node = malloc(sizeof(node));
	new_node -> data = d;
	new_node -> next = NULL;
	node* last_node = head;
	while ( last_node -> next != NULL) {
		last_node = last_node -> next;
	}
	last_node ->next = new_node;
	return head;
}

node* insert_at_pos(node* head, int d, int pos) {
	if (pos == 0 ) {
		head = insert_at_start(head, d);
	} 
	else {
		node* new_node = malloc(sizeof(node));
		new_node -> data = d;
		node* ptr = head;
		for(int i=0; i < pos-1; i++) {
			ptr = ptr -> next;
		}
		new_node -> next = ptr -> next;
		ptr->next = new_node;
	}
	return head;
}

node* delete_at_start(node* head) {
	head = head -> next;
	return head;
}

node* delete_at_end(node* head) {
	node* ptr = head;
	while (ptr->next->next != NULL) {
		ptr = ptr -> next;
	}
	ptr -> next = NULL;
	return head;
}

node* delete_at_pos(node* head, int pos) {
	if (pos == 0) {
		head = delete_at_start(head);
	}
	else {
		node* ptr = head;
		for(int i = 0; i < pos-1; i++) {
			ptr = ptr -> next;
		}
		ptr -> next = ptr -> next -> next;
	}
	return head;
}

void print_all_nodes(node* n) {
	if (n != NULL) {
		printf("%d ->>> ", n->data);
		print_all_nodes(n->next);
	}
}

int main() {
	node *head = malloc(sizeof(node));
	head->data = 1;
	head->next = NULL;
	head = insert_at_pos(head, 2, 1);
	head = insert_at_pos(head, 3, 2);
	head = insert_at_pos(head, 4, 3);
	head = insert_at_pos(head, 5, 4);
	print_all_nodes(head);
	head = delete_at_pos(head, 4);
	printf("\n");
	print_all_nodes(head);

	return 0;
}
