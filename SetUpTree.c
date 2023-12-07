#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node* sibling = parent->firstChild;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;
    }
}

void printTree(Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    printTree(root->nextSibling, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    printTree(root->firstChild, space);
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->firstChild);
    deleteTree(root->nextSibling);
    free(root);
}

int main() {
    Node* root = createNode(1);
    Node* child1 = createNode(2);
    Node* child2 = createNode(3);
    addChild(root, child1);
    addChild(root, child2);
    printTree(root, 0);
    deleteTree(root);
    return 0;
}
