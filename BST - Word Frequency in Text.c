#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char dt[21];
    int count;
    struct node* l;
    struct node* r;
}node;

node* find(node* root,char dt[]){
    if (root == NULL)
    {
        return NULL;
    }else if (strcmp(root->dt, dt) == 0)
    {
        return root;
    }else if (strcmp(dt, root->dt) < 0)
    {
       return find(root->l,dt);
    } else
    {
        return find(root->r,dt);
    }
}

node* insert(node* root,char dt[]){
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        strcpy(root->dt,dt);
        root->count = 1;
        root->l = NULL;
        root->r = NULL;
    }else if (strcmp(dt, root->dt) < 0)
    {
        root->l = insert(root->l,dt);
    }else if (strcmp(dt, root->dt) > 0)
    {
        root->r = insert(root->r,dt);
    } else {
        root->count++;
    }
    return root;
}

void preOder(node* root){
    if (root == NULL)
    {
        return;
    }
    preOder(root->l);
    printf("%s %d\n",root->dt, root->count);
    preOder(root->r);
}

int main(){
    
     node* root = NULL;
    char line[1000];
    while(fgets(line, sizeof(line), stdin) != NULL){
        if(line[0] == '\n' || line[0] == '\0') break;
        char* command = strtok(line, " \n");
        while(command != NULL){
            root = insert(root,command);
            command = strtok(NULL, " \n");
        }
    }
    preOder(root);
    return 0;
}
