#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void add_to_ass(node **head, int data){
	node* newnode = (node*)malloc(sizeof(node));
	if(newnode == NULL){
		printf("Couldnt allocate memory.\n");
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
	if(*head == NULL){
		*head = newnode;
		return;
	}
	node *curr;
	curr = *head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = newnode;
}

void pop_ass(node **head){
	if(*head == NULL){
		printf("stack empty.\n");
		return;
	}
	if((*head)->next == NULL){
		free(*head);
		*head = NULL;
		return;
	}
	node *curr, *prev;
	curr = prev = *head;
	while(curr->next != NULL){
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	free(curr);
}

void print(node *head){
	if(head == NULL){
		printf("List is empty.\n");
		return;
	}
	node *curr = head;
	while(curr != NULL){
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}


int main(){
	node *head = NULL;
	int choice, value;

	while(1){
		printf("\n1. Add\n2. Pop \n3. Print\n4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter value to add: ");
				scanf("%d", &value);
				add_to_ass(&head, value);
				break;
			case 2:
				pop_ass(&head);
				break;
			case 3:
				print(head);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}

	return 0;
}

