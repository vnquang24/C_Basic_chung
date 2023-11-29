#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addFirst(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void addLast(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* last = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void addAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
void addBefore(Node** head, int data, int key) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    if ((*head)->data == key) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* prev = NULL;
    Node* current = *head;
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        prev->next = newNode;
        newNode->next = current;
    }
}
void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    int n, data;
    int count[100000] = {0}; 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addLast(&head, data);
        count[data]++;
    }
    char command[20];
    while (scanf("%s", command), strcmp(command, "#") != 0) {
        if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &data);
            if (count[data] == 0) {
                addFirst(&head, data);
                count[data]++;
            }
        } else if (strcmp(command, "addlast") == 0) {
            scanf("%d", &data);
            if (count[data] == 0 ) {
                addLast(&head, data);
                count[data]++;
            }
        } else if (strcmp(command, "addbefore") == 0) {
            int key;
            scanf("%d%d", &data, &key);
             if (count[data] == 0) {
                addBefore(&head, data, key);
                 count[data]++;
                 }
        }else if (strcmp(command, "addafter") == 0) {
            int key;
            scanf("%d%d", &data, &key);
            Node* node = head;
            while (node != NULL && node->data != key) {
                node = node->next;
            }
            if (node != NULL) {
                if (count[data] == 0) {
                    addAfter(node, data);
                    count[data]++;
                }
            }
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &data);
            if (count[data] != 0) {
                deleteNode(&head, data);
                count[data]--;
            }
        } else if (strcmp(command, "reverse") == 0) {
            if (count[data] == 0) {
                reverse(&head);
            }
        }
    }
    printList(head);
    return 0;
}
