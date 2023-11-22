#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    char tele[50];
    char add[50];
    struct node* next;
}node;

node* create_node(char x[],char y[],char z[]){
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->name,x);
    strcpy(p->add,z);
    strcpy(p->tele,y);
    p->next = NULL;
    return p;   
}

node* push(node* root,char x[],char y[],char z[]){
    node* p = create_node(x,y,z);
    if (root == NULL)
    {
        return p;
    }
    node* p_run = root;
    for (p_run = root;p_run->next != NULL;p_run = p_run->next){
    };
    p_run->next = p;
    return root;
}

void find(node* root,char x[],int n){
    int k = 0;
    node* p_run = root;
    
    while (p_run != NULL && strcmp(p_run->name,x) != 0 && k<n)
    {
        k++;
        p_run = p_run->next;
    }
    if (p_run != NULL && k<n)
    {
        printf("%d %s %s %s",k,p_run->name,p_run->tele,p_run->add);
    }
    else{
    printf("Not found");
    }
}

void print_ll(node* root){
    for (node* p_run = root;p_run != NULL;p_run = p_run->next){
        printf("%s",p_run->name);
    };
}
void free_list(node* root){
    node* tmp;

    while (root != NULL)
    {
       tmp = root;
       root = root->next;
       free(tmp);
    }
}
int main(){
    int n=0;
    node* root = NULL;
    char key[50];
    char temp1[50];
        char temp2[50];
        char temp3[50];
    char line[150];

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%s %s %s", temp1, temp2, temp3) == 3) {
            root = push(root, temp1, temp2, temp3);
            n++;
        } else if (strcmp(temp1, "#") == 0) {
            break;
        }
    }

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%s", key);
  //  print_ll(root);
    find(root,key,n);  
    free_list(root);
    return 0; 
}