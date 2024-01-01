#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char data;
    struct node* next;
} node;

node* create_node(char x) {
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

node* push(node* top, char x) {
    node* p = create_node(x);
    if (top == NULL) {
        return p;
    }
    p->next = top;
    return p; 
}

node* pop(node* top) {
    if (top == NULL) {
        printf("Stack het phan tu");
        return NULL;
    }
    node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

char top_show(node* top) {
    if (top == NULL) {
        printf("TOP NULL");
        return -1;
    }  
    return top->data;
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

int Prec(char ch) {
    switch (ch) {
        case '+':
            return 1;
        case '*':
            return 2;
    }
    return -1;
}

void infixToPostfix(char* exp) {
     int i;
    int k = -1;
    node* top = NULL;
    for (i = 0; exp[i]; ++i) {
        if (isOperand(exp[i])) {
            k++;
            exp[k] = exp[i];
        } else if (exp[i] == '+' || exp[i] == '*') {
            while (top != NULL && Prec(exp[i]) < Prec(top_show(top))) {
                k++;
                exp[k] = top_show(top);
                top = pop(top);
            }
            top = push(top, exp[i]);
        }
    }
    while (top != NULL) {
        k++;
        exp[k] = top_show(top);
        top = pop(top);
    }
    k++;
    exp[k] = '\0';
    for (i = 0; exp[i]; ++i){
        printf("%c ", exp[i]);
    }
}

int main() {
    char exp[50];
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}
