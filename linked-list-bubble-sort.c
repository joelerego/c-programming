#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* The following structure denotes a single
 * node of a linear linked list. It has been
 * type defined to "node"
 */
typedef struct node {
	int data;
	struct node* next;
} node;

/* The following routine creates a list of
 * 100 nodes. It used the rand function of 
 * the stdlib library and limits the number of 
 * digits to 3 for ease of reading.
 */
node* create_list() {
	srand(time(0));
	node* head = malloc(sizeof(node));
	head -> data = 100 + rand()%900;
	head -> next = NULL;
	
	node* ptr = head;
	for(int i=0; i<99; i++) {
		node* new_node = malloc(sizeof(node));
		new_node -> data = 100 + rand()%900;
		ptr -> next = new_node;
		ptr = new_node;
	}
	return head;
}

/* The following routine is very simple. All
 * it does is swap the data of two nodes which
 * are passed as parameter
 */
void swap_nodes(node* a, node* b) 
{
	int temp = a -> data;
	a -> data = b -> data;
	b -> data = temp;
}


/* The following routine using the bubble sorting
 * technique. There are two for loops, the i loop
 * and the j loop. At the end of each ith iteration,
 * the node with the maximum value is bubbled to the
 * top, or the last node of the list.
 */
void bubble_sort(node* head, int size) {
	for(int i=0; i<size; i++) 
	{
		node* n = head;
		for(int j=0; j<size-i; j++) 
		{
			if(n -> data > n -> next -> data) 
			{
				swap_nodes(n, n -> next);
			}
	    if (n->next->next != NULL) n = n -> next;
		}
	}
}

/* The following routine prints the linked list
 * with 5 nodes in each line. This is achieved by
 * using a static count variable, which is reset 
 * everytime it reaches the value 5, and a newline 
 * character is printed
 */
void print_list(node* n) 
{
	static int count = 0;
	if (n != NULL) {
		printf("%d --> ", n -> data);
		count++;
		if (count == 5) 
		{
			count = 0;
			printf("\n");
		}
		print_list(n -> next); 
	}
}

int main() 
{
	node* head = create_list();
	printf("\nThe list before bubble sorting: \n");
	print_list(head);
	bubble_sort(head, 100);
	printf("\nThe list after bubble sorting: \n");
	print_list(head);
	printf("\n");
	return(0);
}
