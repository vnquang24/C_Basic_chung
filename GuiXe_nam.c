#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Với đề đơn giản thì chỉ cần 1 char time[] thay cho time_in và time_out

typedef struct phuongtien_s
{
    char time_in[9];
    char time_out[9];
    char plate[13];
    int stt;
} phuongtien_inf;

typedef struct node_s
{
    phuongtien_inf phuongtien_info;
    struct node_s *next;

} node_t, *root_t;

void showDATA(phuongtien_inf phuongtien)
{
    printf("%s", phuongtien.plate);
}

void llPrint(root_t root)
{
    root_t p;
    for (p = root; p != NULL; p = p->next)
    {
        showDATA(p->phuongtien_info);
        printf("\n");
    }
}

root_t createNewNode(phuongtien_inf phuongtien)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->phuongtien_info = phuongtien;
    newNode->next = NULL;

    return newNode;
}

root_t InsertTail(root_t root, phuongtien_inf phuongtien)
{
    node_t *pnewNode = createNewNode(phuongtien);

    if (root == NULL)
    {
        return pnewNode;
    }

    root_t p;
    for (p = root; p->next != NULL; p = p->next)
        ;
    p->next = pnewNode;

    return root;
}

root_t findPT(root_t root, char plate[])
{
    root_t p;
    for (p = root; p != NULL; p = p->next)
    {
        if (strcmp(p->phuongtien_info.plate, plate) == 0)
        {
            return p;
        }
    }

    return NULL;
}

root_t removeNode(root_t root, char plate[])
{
    if (root == NULL)
    {
        return NULL;
    }

    // Phan tu dau
    root_t p = root;
    if (strcmp(p->phuongtien_info.plate, plate) == 0)
    {
        root_t tmp = p;
        p = p->next;
        free(tmp);
        return p;
    }

    for (p = root; p != NULL; p = p->next)
    {
        if (strcmp(p->next->phuongtien_info.plate, plate) == 0)
        {
            root_t prev = p->next;
            p->next = p->next->next;
            free(prev);
            return root;
        }
    }

    return root;
}

/*
int checkPT(root_t root, char plate[])
{
    root_t p;
    int check = 0;
    for (p = root; p != NULL; p = p->next)
    {
        if (strcmp(p->phuongtien_info.plate, plate) == 0)
        {
            check = 1;
            return check;
        }
    }

    return check;
}
*/

int count_bicycle(root_t root)
{
    root_t p;
    int cnt = 0;
    for (p = root; p != NULL; p = p->next)
    {
        if (p->phuongtien_info.plate[0] == 'x')
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    root_t llist = NULL;

    char cmd[100];
    int cnt = -1;
    int in_find;

    while (strcmp(cmd, "*\n") != 0)
    {
        phuongtien_inf pt;

        char time[20];
        char plate[20];
        fgets(cmd, sizeof(cmd), stdin);
        sscanf(cmd, "%s %s", time, plate);

        if (strcmp(cmd, "*\n") != 0)
        {
            strcpy(pt.time_in, time);
            strcpy(pt.plate, plate);
            pt.stt = cnt + 1;
            cnt++;

            llist = InsertTail(llist, pt);
        }
    }

    do
    {
        char line[100];
        char time_tmp[20];
        char plate_tmp[20];

        fgets(cmd, sizeof(cmd), stdin);

        if (strcmp(cmd, "***\n") != 0)
        {
            sscanf(cmd, "%s %s %s", line, time_tmp, plate_tmp);
        }
        else
        {
            break;
        }

        if (strcmp(line, "list") == 0)
        {
            llPrint(llist);
        }
        else if (strcmp(line, "find") == 0)
        {
            // time_tmp sscanf duoc la plate
            root_t p = findPT(llist, time_tmp);
            if (p != NULL)
                printf("%d\n", p->phuongtien_info.stt);
            else
                printf("-1\n");
        }
        else if (strcmp(line, "in") == 0)
        {

            root_t p = findPT(llist, plate_tmp);
            if (p != NULL)
            {
                printf("0\n");
            }
            else
            {
                phuongtien_inf ptIN;
                strcpy(ptIN.time_in, time_tmp);
                strcpy(ptIN.plate, plate_tmp);
                llist = InsertTail(llist, ptIN);
                printf("1\n");
            }
        }
        else if (strcmp(line, "out") == 0)
        {
            root_t p = findPT(llist, plate_tmp);
            if (p != NULL)
            {
                llist = removeNode(llist, plate_tmp);
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if (strcmp(line, "cnt-bicycle") == 0)
        {
            printf("%d\n", count_bicycle(llist));
        }
        else if (strcmp(line, "has-checkout") == 0)
        {
            root_t p = findPT(llist, time_tmp); // time_tmp duoc sscanf thay cho plate_tmp
            if (p == NULL)
            {
                printf("0\n"); // Neu xe da duoc lay ra
            }
            else
            {
                printf("-1\n"); // Xe chua gui or da gui nhung chua duoc lay ra
            }
        }

    } while (1);

    return 0;
}