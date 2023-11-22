#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char tel[20];
    char email[32];
} phoneAddr_t;

typedef struct node {
    phoneAddr_t data;
    struct node *next;
} node_t;

node_t *createNode(phoneAddr_t data) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

void addNode(node_t **head, phoneAddr_t data) {
    node_t *newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

void moveToFront(node_t **head, node_t *prevNode, node_t *curNode) {
    if (prevNode != NULL) {
        prevNode->next = curNode->next;
        curNode->next = *head;
        *head = curNode;
    }
}

void searchNode(node_t **head, char key[]) {
    node_t *temp = *head;
    node_t *prev = NULL;
    int index = 0;
    while (temp != NULL) {
        if (strcmp(temp->data.name, key) == 0) {
            printf("%d %s %s %s\n", index, temp->data.name, temp->data.tel, temp->data.email);
            moveToFront(head, prev, temp);
            return;
        }
        prev = temp;
        temp = temp->next;
        index++;
    }
    printf("Not found\n");
}

void printList(node_t *head) {
    node_t *temp = head;
    int index = 0;
    while (temp != NULL) {
        printf("%s %s %s\n", temp->data.name, temp->data.tel, temp->data.email);
        temp = temp->next;
        index++;
    }
}

int main() {
    node_t *head = NULL;
    phoneAddr_t data;
    char key[20];

    while (1) {
        scanf("%s", data.name);
        if (strcmp(data.name, "#") == 0) break;
        scanf("%s %s", data.tel, data.email);
        addNode(&head, data);
    }

    scanf("%s", key);
    searchNode(&head, key);
    printList(head);

    // Free memory
    node_t *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
