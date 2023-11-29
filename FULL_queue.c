#include<stdio.h>
#include <stdlib.h>

typedef int dt_t;

typedef struct node
{
    dt_t data;
    struct node* next;
}node;

node* create_node(dt_t x){
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

node* enqueue(node* rear, dt_t x){
    node* p = create_node(x);
    if (rear == NULL)
    {
        return p;
    }
    rear->next = p;
    return p;   
}

node* dequeue(node* front){
    if (front == NULL)
    {
        printf("Queue is empty");
        return NULL;
    }
    node* temp = front;
    front = front->next;
    free(temp);
    return front;
}

dt_t peek(node* front){
    if (front == NULL)
    {
        printf("Queue is empty");
        return -1;
    }  
    return front->data;
}

void display_queue(node* front){
    for (node* p_run = front; p_run != NULL; p_run=p_run->next)
    {
        printf("%d ",p_run->data);
    }
    printf("\n");
}

int main(){
    node* front = NULL;
    node* rear = NULL;
    int n;
    scanf("%d",&n);
    dt_t temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        if (front == NULL) {
            front = enqueue(rear, temp);
            rear = front;
        } else {
            rear = enqueue(rear, temp);
        }
    }
    front = dequeue(front);
    rear = enqueue(rear,10);
    display_queue(front);
    return 0; 
}