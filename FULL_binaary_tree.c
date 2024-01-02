#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int dt;
    struct node* l;
    struct node* r;
} node;

node* nodes[100001];

node* create_node(int dt) {
    node* p = (node*)malloc(sizeof(node));
    p->dt = dt;
    p->l = NULL;
    p->r = NULL;
    return p;
}

node* addL(node* root, int u, int v) {
    node* p = nodes[u];
    node* q = nodes[v];
    if (p != NULL && q != NULL && q->l == NULL) {
        q->l = p;
    }
    return root;
}

node* addR(node* root, int u, int v) {
    node* p = nodes[u];
    node* q = nodes[v];
    if (p != NULL && q != NULL && q->r == NULL) {
        q->r = p;
    }
    return root;
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int hL = height(root->l);
    int hR = height(root->r);
    return (hL > hR ? hL : hR) + 1;
}

int isBalanced(node* root) {
    if (root == NULL) {
        return 1;
    }
    int hL = height(root->l);
    int hR = height(root->r);
    return abs(hL - hR) <= 1 && isBalanced(root->l) && isBalanced(root->r);
}

int main() {
    node* root = NULL;
    char command[10];
    int u, v;

    while (scanf("%s", command) && command[0] != '*') {
        if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = nodes[u] = create_node(u);
        } else if (strcmp(command, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            nodes[u] = create_node(u);
            root = addL(root, u, v);
        } else if (strcmp(command, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            nodes[u] = create_node(u);
            root = addR(root, u, v);
        }
    }
    printf("%d %d", isBalanced(root), height(root));
    return 0;
}