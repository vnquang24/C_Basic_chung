#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

void InsertNode(Node **root, int key) {
    if (*root == NULL) {
        *root = (Node *)malloc(sizeof(Node));
        (*root)->key = key;
        (*root)->left = (*root)->right = NULL;
    } else if (key < (*root)->key) {
        InsertNode(&(*root)->left, key);
    } else if (key > (*root)->key) {
        InsertNode(&(*root)->right, key);
    }
}

void AddLeft(Node *root, int key) {
    if (root->left == NULL) {
        root->left = (Node *)malloc(sizeof(Node));
        root->left->key = key;
        root->left->left = root->left->right = NULL;
    }
}

void AddRight(Node *root, int key) {
    if (root->right == NULL) {
        root->right = (Node *)malloc(sizeof(Node));
        root->right->key = key;
        root->right->left = root->right->right = NULL;
    }
}

void PreOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node *root) {
    if (root != NULL) {
        InOrder(root->left);
        printf("%d ", root->key);
        InOrder(root->right);
    }
}

void PostOrder(Node *root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->key);
    }
}

void find (Node *root, int key){
    if (root == NULL){
        printf("Not found\n");
        return;
    }
    if (key < root->key){
        find(root->left, key);
    } else if (key > root->key){
        find(root->right, key);
    } else {
        printf("Found\n");
    }
}

void DeleteNode(Node **root, int key) {
    if (*root == NULL){
        printf("Not found\n");
        return;
    }
    if (key < (*root)->key) {
        DeleteNode(&(*root)->left, key);
    } else if (key > (*root)->key) {
        DeleteNode(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            Node *temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            Node *temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            Node *temp = (*root)->right;
            while (temp->left != NULL) temp = temp->left;
            (*root)->key = temp->key;
            DeleteNode(&(*root)->right, temp->key);
        }
    }
}

void FindMinium(Node *root){
    if (root->left == NULL){
        printf("%d\n", root->key);
        return;
    }
    FindMinium(root->left);
}

void CheckBalance(Node* root, int* isBalanced, int* height) {
    if (root == NULL) {
        *isBalanced = 1;
        *height = -1;
        return;
    }
    int isLeftBalanced, isRightBalanced;
    int leftHeight, rightHeight;
    CheckBalance(root->left, &isLeftBalanced, &leftHeight);
    CheckBalance(root->right, &isRightBalanced, &rightHeight);
    *isBalanced = isLeftBalanced && isRightBalanced && abs(leftHeight - rightHeight) <= 1;
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main(){
    Node *root = NULL;
    char command[100];
    while (scanf("%s", command), strcmp(command, "#") != 0) {
        if(strcmp(command, "insert") == 0){
            int key;
            scanf("%d", &key);
            InsertNode(&root, key);
        }
        else if (strcmp(command, "delete") == 0){
            int key;
            scanf("%d", &key);
            DeleteNode(&root, key);
        }
        else if (strcmp(command, "find") == 0){
            int key;
            scanf("%d", &key);
            find(root, key);
        }
        else if (strcmp(command, "preorder") == 0){
            PreOrder(root);
            printf("\n");
        }
        else if (strcmp(command, "inorder") == 0){
            InOrder(root);
            printf("\n");
        }
        else if (strcmp(command, "postorder") == 0){
            PostOrder(root);
            printf("\n");
        }
        else if (strcmp(command, "findMin") == 0){
            FindMinium(root);
        }
        else if (strcmp(command, "checkBalance") == 0){
            int isBalanced, height;
            CheckBalance(root, &isBalanced, &height);
            printf("%d\n", isBalanced);
        }
        else if (strcmp(command, "addLeft") == 0){
            int key, parentKey;
            scanf("%d %d", &key, &parentKey);
            Node *temp = root;
            while (temp != NULL){
                if (temp->key == parentKey){
                    AddLeft(temp, key);
                    break;
                }
                else if (temp->key > parentKey){
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
        }
        else if (strcmp(command, "addRight") == 0){
            int key, parentKey;
            scanf("%d %d", &key, &parentKey);
            Node *temp = root;
            while (temp != NULL){
                if (temp->key == parentKey){
                    AddRight(temp, key);
                    break;
                }
                else if (temp->key > parentKey){
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
        }
        else if (strcmp(command, "makeRoot") == 0){
            int key;
            scanf("%d", &key);
            InsertNode(&root, key);
        }
        else if (strcmp(command, "height") == 0){
            int isBalanced, height;
            CheckBalance(root, &isBalanced, &height);
            printf("%d\n", height);
        }
    }
    return 0;
}
