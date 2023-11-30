#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char time[50];
    char plate[50];
    struct node* next;
} node;

node* create_node(char time[], char plate[]) {
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->time, time);
    strcpy(p->plate, plate);
    p->next = NULL;
    return p;
}

node* insert_tail(node* root, char time[], char plate[]) {
    node* newNode = create_node(time, plate);
    if (root == NULL) return newNode;
    node* p = root;
    while (p->next != NULL) p = p->next;
    p->next = newNode;
    return root;
}

void list(node* root) {
    for (node* p = root; p != NULL; p = p->next) {
        printf("%s\n", p->plate);
    }
}

node* delete_node(node* root, char plate[]) {
    if (root == NULL) return NULL;
    if (strcmp(root->plate, plate) == 0) {
        node* temp = root->next;
        free(root);
        return temp;
    }
    node* p = root;
    while (p->next != NULL && strcmp(p->next->plate, plate) != 0) p = p->next;
    if (p->next != NULL) {
        node* temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
    return root;
}

int find(node* root, char plate[]) {
    int index = 0;
    for (node* p = root; p != NULL; p = p->next, index++) {
        if (strcmp(p->plate, plate) == 0) return index;
    }
    return -1;
}

int count_bicycle(node* root) {
    int count = 0;
    for (node* p = root; p != NULL; p = p->next) {
        if (p->plate[0] == 'x') count++;
    }
    return count;
}

int has_checkout(node* in, node* out, char plate[]) {
    if (find(in, plate) == -1 && find(out, plate) != -1) return 1;
    return -1;
}

int main() {
    node* in = NULL;
    node* out = NULL;
    char time[50];
    char plate[50];
    char command[50];

    while (scanf("%s", time), strcmp(time, "*") != 0) {
        scanf("%s", plate);
        in = insert_tail(in, time, plate);
    }

    while (scanf("%s", command), strcmp(command, "***") != 0) {
        if (strcmp(command, "list") == 0) {
            list(in);
        } else if (strcmp(command, "in") == 0) {
            scanf("%s %s", time, plate);
            if (find(in, plate) == -1) {
                in = insert_tail(in, time, plate);
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(command, "out") == 0) {
            scanf("%s %s", time, plate);
            if (find(in, plate) != -1) {
                in = delete_node(in, plate);
                out = insert_tail(out, time, plate);
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(command, "find") == 0) {
            scanf("%s", plate);
            printf("%d\n", find(in, plate));
        } else if (strcmp(command, "cnt-bicycle") == 0) {
            printf("%d\n", count_bicycle(in));
        } else if (strcmp(command, "has-checkout") == 0) {
            scanf("%s", plate);
            printf("%d\n", has_checkout(in, out, plate));
        }
    }

    return 0;
}