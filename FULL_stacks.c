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
        printf("TOP NULL");
        return -1;
    }  
    return top->data;
}

void display_st(node* top){
    for (node* p_run = top;p_run != NULL;p_run=p_run->next)
    {
        printf("%d ",p_run->data);
    }
    printf("\n");
}
// node* addLargeNumbers(node* num1, node* num2) {
//     node* result = NULL;
//     int carry = 0;

//     while (num1 != NULL || num2 != NULL || carry != 0) {
//         int sum = carry;
//         if (num1 != NULL) {
//             sum += num1->data;
//             num1 = num1->next;
//         }
//         if (num2 != NULL) {
//             sum += num2->data;
//             num2 = num2->next;
//         }

//         carry = sum / 10;
//         sum = sum % 10;

//         result = push(result, sum);
//     }

//     return result;
// }
int main(){
    node* top = NULL;
    int n;
    scanf("%d",&n);
    dt_t temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        top = push(top,temp);
    }
    top = pop(top);
   // top_show(top);
    // node* num1 = NULL;
    // node* num2 = NULL;
    // char c;

    // printf("Enter first number: ");
    // while ((c = getchar()) != '\n' && c != EOF) {
    //     num1 = push(num1, c - '0');
    // }

    // printf("Enter second number: ");
    // while ((c = getchar()) != '\n' && c != EOF) {
    //     num2 = push(num2, c - '0');
    // }

    // node* result = addLargeNumbers(num1, num2);

    // printf("Sum: ");
    //display_st(result);
    display_st(top);
     return 0; 
}