#include<stdio.h>
#define max 10
int q[max];

int check_full(int rear){
    return (rear == max-1);
}

int check_empty(int rear,int front){
    return (front == -1 && rear == -1);
}

void print_queue(int rear, int front){
    if(check_empty(rear, front)){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main(){
    int choice, rear, front, number;
    rear = front = -1;

    while(1){
        printf("1.enqueue\n2.dequeue\n3.print\n4.exit\n");
        scanf("%d",&choice);

        if(choice == 1){
            if(check_full(rear)){
                printf("Queue full cant enqueue.\n");
            }
            else if(rear == -1 && front == -1){
                printf("Enter the number: \n");
                scanf("%d",&number);
                rear = front = 0;
                q[rear] = number;
            }
            else{
                printf("Enter the number: \n");
                scanf("%d",&number);
                rear++;
                q[rear] = number;
            }
        }
        else if(choice == 2){
            if(check_empty(rear,front)){
                printf("The queue is empty.\n");
            }
            else{
                if(front == rear){
                    printf("%d dequeued\n", q[front]);
                    front = rear = -1;
                }
                else{
                    printf("%d dequeued\n", q[front]);
                    front++;
                }
            }
        }
        else if(choice == 3){
            print_queue(rear, front);
        }
        else if(choice == 4){
            break;
        }
        else{
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
