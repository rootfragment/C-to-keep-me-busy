#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;


void enq(node **head, int data){
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

void dq(node **head){
	if(*head == NULL){
		printf("The List is empty.");
		return;
	}
	node *curr;
	curr = *head;
	if(curr->next == NULL){
		*head = NULL;
		free(curr);
	}
	else{
		*head = curr->next;
		free(curr);
	}
	
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
	int choice, val;

	while(1){
		printf("\n--- Queue Menu ---\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter value to enqueue: ");
				scanf("%d", &val);
				enq(&head, val);
				break;
			case 2:
				dq(&head);
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

