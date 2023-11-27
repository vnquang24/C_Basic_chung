#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int he_so;
    int so_mu;
    struct node* next;
}node;

node* create_node(int he_so,int so_mu){
    node* p = (node*)malloc(sizeof(node));
    p->he_so = he_so;
    p->so_mu = so_mu;
    p->next = NULL;
    return p;
}
node* push(node* root,int he_so,int so_mu){
    node* p = create_node(he_so,so_mu);
    if (root == NULL)
    {
        return p;
    }
    node* p_run = root;
    for (p_run = root;p_run->next != NULL;p_run=p_run->next)
    {
    }
    p_run->next = p;
    return root;    
}
void print_ll(node* root){
    int cou=0;
     for (node* p_run = root;p_run != NULL;p_run = p_run->next)
     {
        if (p_run->he_so != 0)
        {
            cou++;
        }
     }
     if (cou == 0)
     {
        printf("1 0");
        return;
     }
     else printf("%d ",cou);
     
     for (node* p_run = root;p_run != NULL;p_run = p_run->next)
     {
        printf("%d ",p_run->he_so);
     }
}
node* sum(node* r1,node* r2,int n){
      node* run1 = r1;
      node* run2 = r2;
      node* sum = NULL;
      for(int i=0;i<n;i++){
          if ((run1 != NULL) && (run2 != NULL))
          {
              sum = push(sum,run1->he_so+run2->he_so,i);
          }
          run1 = run1->next;
          run2 = run2->next;
      }
      
      return sum;
}
node* deni(node* r1,node* r2,int n){
      node* run1 = r1;
      node* run2 = r2;
      node* sum = NULL;
      for(int i=0;i<n;i++){
          if ((run1 != NULL) && (run2 != NULL))
          {
              sum = push(sum,run1->he_so-run2->he_so,i);
          }
          run1 = run1->next;
          run2 = run2->next;
      }
      return sum;
}


int main(){
    node* r1 = NULL;
    node* r2 = NULL;
    node* out = NULL;
    int n1,n2;
    scanf("%d",&n1);
    int temp1;
    for (int i = 0; i < n1; i++)
    {
        scanf("%d",&temp1);
        r1 = push(r1,temp1,i);
    }
    scanf("%d",&n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d",&temp1);
        r2 = push(r2,temp1,i);
    }
    int n;
    if (n1>n2)
    {
        n = n1;
        for (int i = 0; i < n1-n2; i++)
        {
            r2 = push(r2,0,i);
        }
    }
    else {
        n = n2;
        for (int i = 0; i < n2-n1; i++)
        {
            r1 = push(r1,0,i);
        }
        
    }
    char check[5];
    scanf("%s",check);
    if (strcmp(check,"plus") == 0)
    {
        out = sum(r1,r2,n); 
    }
    else{
        out = deni(r1,r2,n);
    }
    // print_ll(r1);
    // print_ll(r2);
   // printf("%d",n);
    print_ll(out);
    return 0;   
}