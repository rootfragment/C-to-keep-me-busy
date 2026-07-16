#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct task{
	int id;
	char data[25];
	int prio;
	struct task *next;
}task;

task* createtask(task **head,int id, char *data, int prio){
	task *newtask = (task*) malloc(sizeof(task));
	if(newtask == NULL){
		printf("No task allotted.\n");
		exit(1);
	}
	newtask->id = id;
	strncpy(newtask->data,data, sizeof(newtask->data)-1);
	newtask->data[sizeof(newtask->data) - 1] = '\0';
	newtask->prio = prio;
	newtask->next = NULL;
	if (*head == NULL){
		*head = newtask;
	}
	else {
		task *curr;
		curr = *head;
		while (curr->next != NULL){
		curr = curr->next;}
	   curr->next = newtask;
	}
	return newtask;
}

void deletetask(task **head, int id){
	task *curr;
	if(*head == NULL){
		printf("List is empty cannot delete.\n");
		return;
	}
	curr = *head;
	task *prev = NULL;
	while(curr->id != id){
		prev = curr;
		curr = curr->next;
		if (curr == NULL){
			printf("The id is not found. Exiting without deleting\n");
			return;
			}
	}
	if(prev == NULL){
		*head = curr->next;
	}
	else{
		prev->next=curr->next;
	}
	free(curr);
}
void reverse_list(task **head){
	if(*head == NULL || (*head)->next == NULL){
		printf("Cant reverse. Either list empty or has only one entry");
		return;
	}
	task *next,*curr,*prev=NULL;
	curr = *head;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
void print_list(task **head){
	task *curr = *head;
	if(*head == NULL){
		printf("The list is empty nothing to print\n");
		return;
	}
	while(curr != NULL){
		printf("ID\t%d\nPriority\t%d\nData\t%s",curr->id,curr->prio,curr->data);
		curr = curr->next;
	}
}


void find_task(task **head, int id){
	task *curr;
	if(*head == NULL){
		printf("Task list empty.\n");
		return;
	}
	curr = *head;
	while(curr->id != id && curr->next != NULL){
		curr = curr->next;
	}
	if (curr->id == id){
        	printf("ID\t%d\nPriority\t%d\nData\t%s\n", curr->id, curr->prio, curr->data);
    }
    	else{
		printf("Id not found\n");
    }
}

void menu_loop(){
    task *head = NULL;
    int choice, id, prio;
    char data[25];
    while (1){
        printf("\n===== Task Manager =====\n");
        printf("1. Add task\n");
        printf("2. Delete task\n");
        printf("3. Find task\n");
        printf("4. Print all tasks\n");
        printf("5. Reverse list\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1){
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice){
            case 1:
                printf("Enter id: ");
                scanf("%d", &id);
                printf("Enter priority: ");
                scanf("%d", &prio);
                printf("Enter data (max 24 chars): ");
                scanf(" %24s", data);
                createtask(&head, id, data, prio);
                printf("Task added.\n");
                break;
            case 2:
                printf("Enter id to delete: ");
                scanf("%d", &id);
                deletetask(&head, id);
                break;
            case 3:
                printf("Enter id to find: ");
                scanf("%d", &id);
                find_task(&head, id);
                break;
            case 4:
                print_list(&head);
                break;
            case 5:
                reverse_list(&head);
                printf("List reversed.\n");
                break;
            case 6:
                printf("Exiting.\n");
                return;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}

int main(){
    menu_loop();
    return 0;
}
