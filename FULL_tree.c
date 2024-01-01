#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int dt;
    struct node* lmc;
    struct node* rsl;
}node;

node* create_node(int dt){
    node* p = (node*)malloc(sizeof(node));
    p->dt = dt;
    p->lmc = NULL;
    p->rsl = NULL;
    return p;
}
node* find(node* root,int dt){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->dt == dt)
    {
        return root;
    }
    node* p = root->lmc;
    while (p != NULL)
    {
        node* found = find(p,dt);
        if (found != NULL)
        {
            return found;
        }
        p=p->rsl;
    }
    return NULL;
}

node* add(node* root,int u, int v){
    if (root == NULL)
    {
        return root;
    }
    node* p = find(root,u);
    node* q = find(root,v);
    if (p != NULL || q == NULL) {
        return root;
    }
    node* new_node = create_node(u);
    if (q->lmc == NULL) {
        q->lmc = new_node;
    } else {
        node* rsib = q->lmc;
        while (rsib->rsl != NULL)
        {
            rsib = rsib->rsl;
        }
        rsib->rsl = new_node;
    }
    return root;             
}

int height(node* root){
    if (root == NULL)
    {
        return 0;
    }
    int h, max_h = 0;
    node* p = root->lmc;
    while (p != NULL)
    {
        h = height(p);
        if (h > max_h)
        {
            max_h = h;
        }
        p = p->rsl;
    }
    return max_h+1;    
}
int depth(node* root,int u,int lv){
    if (root == NULL)
    {
        return 0;
    }
    if (root->dt == u)
    {
        return lv;
    }
    int depth1 = 0;
    node* p = root->lmc;
    while (p != NULL)
    {
        depth1 = depth(p,u,lv+1);
        if (depth1 != 0)
        {
            return depth1;
        }
        p = p->rsl;
    }
    return 0;
}
void postO(node* root){
    if (root == NULL)
    {
        return;
    }
    node* p = root->lmc;
    while (p != NULL)
    {
        postO(p);
        p = p->rsl;
    }
        printf("%d ",root->dt);
}
void preO(node* root){
    if (root == NULL)
    {
        return;
    }
            printf("%d ",root->dt);
    node* p = root->lmc;
    while (p != NULL)
    {
        preO(p);
        p = p->rsl;
    }
}
void inO(node* root){
    if (root == NULL)
    {
        return;
    }
    node* p = root->lmc;
    inO(p);
    printf("%d ",root->dt);
    if (p != NULL)
    {
        p = p->rsl;
    }
    while (p != NULL)
    {
        inO(p);
        p = p->rsl;
    }
}

void freeTree(node *r){
	if(r == NULL) return;
	
	node *p = r->lmc;
	while( p != NULL){
		freeTree(p);
		p = p->rsl;
	}
	free(r);
}

int main(){
    char command[20];
    node* root = NULL;
    int u, v;
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = create_node(u);
        } else if (strcmp(command, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            root = add(root,u, v);
        } else if (strcmp(command, "Height") == 0) {
            scanf("%d", &u);
            printf("%d\n",height(find(root,u)));
        } else if (strcmp(command, "Depth") == 0) {
            scanf("%d", &u);
            printf("%d\n",depth(root,u,1));
        } else if (strcmp(command, "PreOrder") == 0) {
            preO(root);
            printf("\n");
        } else if (strcmp(command, "InOrder") == 0) {
            inO(root);
            printf("\n");
        } else if (strcmp(command, "PostOrder") == 0) {
            postO(root);
            printf("\n");
        } else if (strcmp(command, "*") == 0) {
            break;
        }
    }
}