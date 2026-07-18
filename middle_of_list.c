#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* add_node(node **head, int data){
	node* newnode = (node*) malloc(sizeof(node));
	if(newnode == NULL){
		printf("couldnt allocate memory.");
		exit(1);
	}
	newnode->data = data;
	newnode->next = NULL;
	if(*head == NULL){
		*head = newnode;
		return newnode;
	}
	node* curr;
	curr = *head;
	while( curr->next != NULL ){
		curr = curr->next;
	}
	curr->next = newnode;
	return newnode;
}

void middle_node(node *head){
	if(head == NULL){
		printf("List empty.");
		return;
	}
	node *slow,*fast;
	slow = fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = (fast->next)->next;
	}
	printf("%d",slow->data);
	return;
}

void print_list(node *head){
	if(head == NULL){
		printf("List empty.");
		return;
	}
	node *curr = head;
	while(curr != NULL){
		printf("%d",curr->data);
		curr = curr->next;
		if(curr != NULL) printf("-->");
	}
}

void free_list(node **head){
	node *curr = *head;
	node *next;
	while(curr != NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

int main(){
	node *head = NULL;
	int choice, data;

	while(1){
		printf("\n----- Menu -----\n");
		printf("1. Add node\n");
		printf("2. Print list\n");
		printf("3. Find middle node\n");
		printf("4. Exit\n");
		printf("Enter choice: ");

		if(scanf("%d", &choice) != 1){
			printf("Invalid input.\n");
			while(getchar() != '\n');
			continue;
		}

		switch(choice){
			case 1:
				printf("Enter data: ");
				scanf("%d", &data);
				add_node(&head, data);
				break;

			case 2:
				print_list(head);
				printf("\n");
				break;

			case 3:
				middle_node(head);
				printf("\n");
				break;

			case 4:
				free_list(&head);
				printf("Exiting.\n");
				return 0;

			default:
				printf("Invalid choice, try again.\n");
		}
	}

	return 0;
}
