#include<stdio.h>
#include <stdlib.h>

typedef int dt_t;

typedef struct node
{
    dt_t data;
    struct node* next;
} Node;

typedef struct queue
{
    Node* front;
    Node* rear;
} Queue;

Node* create_node(dt_t x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

Queue* create_queue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, dt_t x){
    Node* p = create_node(x);
    if (q->rear == NULL)
    {
        q->front = q->rear = p;
        return;
    }
    q->rear->next = p;
    q->rear = p;
}

void dequeue(Queue* q){
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

dt_t peek(Queue* q){
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }  
    return q->front->data;
}

void display_queue(Queue* q){
    Node* temp = q->front;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue* q = create_queue();
    int n;
    scanf("%d",&n);
    dt_t temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        enqueue(q, temp);
    }
    dequeue(q);
    display_queue(q);
    return 0; 
}