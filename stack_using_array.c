#include<stdio.h>
#define limit 10
int stack[10];
int top = -1;

int full_check(int top){
	if(top == limit -1){
		return 1;
	}else{
		return 0;
	}
}


int check_empty(int top){
	if(top == -1){
		return 1;
	}else{
		return 0;
	}
}


void print_stack(int stack[],int top){
	int i;
	if(top == -1){
		printf("The stack is empty.\n");
	}
	for(i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	}
}


int push(int stack[], int top, int number){
	if(full_check(top)){
		printf("Buffer overflow. Cannot push.");
		return top;
	}
	else{
		top++;
		stack[top] = number;
		return top;
	}
}

void topreveal(int stack[],int top){
	if(check_empty(top)){
		printf("Empty stack.");
	}
	printf("Top element is: %d",stack[top]);
}

int pop(int stack[], int top){
	if(check_empty(top)){
		printf("Buffer Underflow. Cannot pop.\n");
		return top;
	}
	else{
		printf("%d : poped",stack[top]);
		top--;
		return top;		
	}
}

int main(){
	int choice, value;

	while(1){
		printf("\n1. Push\n2. Pop\n3. Print stack\n4. Show top\n5. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &value);
				top = push(stack, top, value);
				break;
			case 2:
				top = pop(stack, top);
				break;
			case 3:
				print_stack(stack, top);
				break;
			case 4:
				topreveal(stack, top);
				break;
			case 5:
				printf("Exiting.\n");
				return 0;
			default:
				printf("Invalid choice.\n");
		}
	}

	return 0;
}
	


