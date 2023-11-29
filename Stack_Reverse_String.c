#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 501
char Stack[MAX];
int top = -1;
void push (char data)
{
    Stack[++top] = data;
}
void pop()
{
    top--;
}
void reverse(char *str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
        push(str[i]);
    for (i = 0; i < strlen(str); i++)
    {
        str[i] = Stack[top];
        pop();
    }
}
int main(){
    char str[MAX];
    fgets(str, MAX, stdin);
    if (strlen(str) > 500){
        printf("2");
        return 0;
    }
    else if (str[strlen(str) - 1] == '\n'&&strlen(str) == 1){
        printf("1");
    }
    reverse(str);
    printf("%s", str);
    return 0;
}
