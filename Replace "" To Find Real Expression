#include<stdio.h>
#include<stdlib.h>

typedef int dt_t;
int b[100] = {0};
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
node* push(node* top,dt_t x){
    node* p = create_node(x);
    if (top == NULL)
    {
        return p;
    }
    p->next = top;
    return p;   
}

node* pop(node* top){
    if (top == NULL)
    {
        printf("Khong con phan tu");
        return top;
    }
    node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

dt_t top_show(node* top){
    if (top == NULL)
    {
      //  printf("TOP NULL");
        return -1;
    }  
    return top->data;
}

int check(int a[],int n){
    node* top = NULL;
    top = push(top,a[0]);
    for (int i = 1; i < n; i++)
    {
        int temp = top_show(top);
        if ((a[i] > temp) && (temp != -1))
        {
            top = pop(top);
        }else
        {
            top = push(top,a[i]);
        }
    }
    if (top_show(top) == -1)
    {
        return 1;
    }else
    {
        return 0;
    }
}
void try(int a[],int k,int n){
    if (k==n)
    {
        if (check(a,n))
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d",a[i]);
            }
            printf(" ");
        }
    }else
    {
        if (a[k] == 0)
        {
            for (int i = 1; i <= 2; i++)
            {
                a[k] = i;
                try(a,k+1,n);
                a[k] = 0;
            }
        }else
        {
            try(a,k+1,n);
        }
    }  
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    try(a,0,n);
    return 0;
}
