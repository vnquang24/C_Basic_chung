#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* addLeft(Node* root, int id, int parentId) {
    if (root == NULL) return NULL;
    if (root->id == parentId) {
        if (root->left == NULL) {
            root->left = makeNode(id);
        }
        return root;
    }
    addLeft(root->left, id, parentId);
    addLeft(root->right, id, parentId);
    return root;
}

Node* addRight(Node* root, int id, int parentId) {
    if (root == NULL) return NULL;
    if (root->id == parentId) {
        if (root->right == NULL) {
            root->right = makeNode(id);
        }
        return root;
    }
    addRight(root->left, id, parentId);
    addRight(root->right, id, parentId);
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->id);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->id);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->id);
    }
}

int main() {
    Node* root = NULL;
    char command[100];
    while(scanf("%s", command), strcmp(command, "*") != 0){
        if (strcmp(command, "MakeRoot") == 0){
            int id;
            scanf("%d", &id);
            root = makeNode(id);
        }
        else if (strcmp(command, "AddLeft") == 0){
            int id, parentId;
            scanf("%d %d", &id, &parentId);
            addLeft(root, id, parentId);
        }
        else if (strcmp(command, "AddRight") == 0){
            int id, parentId;
            scanf("%d %d", &id, &parentId);
            addRight(root, id, parentId);
        }
        else if (strcmp(command, "PreOrder") == 0){
            preOrder(root);
            printf("\n");
        }
        else if (strcmp(command, "InOrder") == 0){
            inOrder(root);
            printf("\n");
        }
        else if (strcmp(command, "PostOrder") == 0){
            postOrder(root);
            printf("\n");
        }
    }
    return 0;
}
