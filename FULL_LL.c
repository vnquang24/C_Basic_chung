#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int mssv;
    char name[50];
    double score;
    struct node* next;
}node;

node* create_node(int mssv,char name[],double score){
     node* p = (node*)malloc(sizeof(node));
     p->mssv = mssv;
     strcpy(p->name,name);
     p->score = score;
     p->next = NULL;
     return p;
}

node* llInsertHead(node* root,int mssv,char name[],double score) {
  node* pNewNode = create_node(mssv,name,score);
  pNewNode->next = root;
  return (node*)pNewNode;
}

node* llInsertTail(node* root,int mssv,char name[],double score) {
  node* pNewNode = create_node(mssv,name,score);

  if (root == NULL) return (node*)pNewNode;

  node* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

node* llInsertAfter(node* root, node* pAElem,int mssv,char name[],double score) {
  if (pAElem == NULL) return root;

  node* pNewNode = create_node(mssv,name,score);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;
  return root;
}
node* llSeek(node* root, int index) { 
  node* p = NULL;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}
// DELETE
node* llDeleteHead(node* root) {
  if (root == NULL) return NULL;

  node* p = root->next;
  free(root);
  return (node*)p;
}

node* llDeleteTail(node* root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }
  node* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;
  free(p->next);
  p->next = NULL;
  return (node*)root;
}

node* llDeleteAfter(node* root, node* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node* pToDelElem = pA->next;
  pA->next = pA->next->next;
  free(pToDelElem);
  return root;
}

node* llDeleteAll(node* root) {
  node* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}
//TOOL
int llLength(node* root) {
  int count;
  for (count = 0; root != NULL; root = root->next) count++;
  return count;
}

node* LLReverse(node* root) {
  node *cur, *prev;

  for (cur = prev = NULL; root != NULL;) {
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  return root;
}

// node* LLsort(node* root){

// }
void LLprint(node* root){
    node* p_run = root;
    for (p_run = root;p_run != NULL;p_run = p_run->next)
    {
        printf("%d %s %.2lf\n",p_run->mssv,p_run->name,p_run->score);
    }
}
void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
void normalize(char *str) {
    char *src = str, *dst = str;

    // Bỏ qua các dấu cách ở đầu
    while (isspace((unsigned char)*src)) ++src;

    while (*src) {
        // Copy non-space characters
        while (*src && !isspace((unsigned char)*src)) *dst++ = *src++;
        // Skip over space characters
        while (isspace((unsigned char)*src)) ++src;
        // Add a single space if there are more words
        if (*src) *dst++ = ' ';
    }
    // Terminate the string
    *dst = '\0';
}

void LLsort(node** root) {
    int swapped;
    node *ptr1;
    node *lptr = NULL;

    /* Checking for empty list */
    if (*root == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *root;

        while (ptr1->next != lptr) {
            if (ptr1->score > ptr1->next->score) { 
                double temp = ptr1->score;
                ptr1->score = ptr1->next->score;
                ptr1->next->score = temp;

                int temp_mssv = ptr1->mssv;
                ptr1->mssv = ptr1->next->mssv;
                ptr1->next->mssv = temp_mssv;

                char temp_name[50];
                strcpy(temp_name, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, temp_name);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void LLsortByName(node** root) {
    int swapped;
    node *ptr1;
    node *lptr = NULL;

    /* Checking for empty list */
    if (*root == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *root;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->name, ptr1->next->name) > 0) { 
                double temp = ptr1->score;
                ptr1->score = ptr1->next->score;
                ptr1->next->score = temp;

                int temp_mssv = ptr1->mssv;
                ptr1->mssv = ptr1->next->mssv;
                ptr1->next->mssv = temp_mssv;

                char temp_name[50];
                strcpy(temp_name, ptr1->name);
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->next->name, temp_name);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void countSameScore(node* root) {
    // Sắp xếp danh sách theo điểm
    LLsort(&root);

    node *ptr = root;
    while (ptr != NULL) {
        double current_score = ptr->score;
        int count = 0;

        // Đếm số lượng sinh viên có cùng điểm
        while (ptr != NULL && ptr->score == current_score) {
            count++;
            ptr = ptr->next;
        }

        printf("Score %.2lf: %d students\n", current_score, count);
    }
}
node* getTail(node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Hàm phân chia danh sách liên kết dựa trên giá trị của pivot
node* partition(node* head, node* end, node** newHead, node** newEnd) {
    node* pivot = end;
    node *prev = NULL, *cur = head, *tail = pivot;

    // Trong khi vòng lặp hiện tại, chúng ta sẽ di chuyển các nút có giá trị nhỏ hơn pivot
    // vào phía trước danh sách và các nút có giá trị lớn hơn hoặc bằng pivot vào phía sau
    while (cur != pivot) {
        if (cur->score < pivot->score) {
            // Đây là nút đầu tiên có giá trị nhỏ hơn pivot
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else { // Nếu nút hiện tại có giá trị lớn hơn hoặc bằng pivot
            // Di chuyển nút hiện tại đến phía sau pivot
            if (prev)
                prev->next = cur->next;
            node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // Nếu pivot là nút đầu tiên trong danh sách liên kết, thì nó là head mới
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Cập nhật newEnd đến nút cuối cùng của danh sách sau khi phân chia
    (*newEnd) = tail;

    // Trả về nút pivot
    return pivot;
}

// Hàm đệ quy QuickSort
node* quickSortRecur(node* head, node* end) {
    // Cơ sở trường hợp: nếu head bằng NULL hoặc chỉ có một nút trong danh sách liên kết
    if (!head || head == end)
        return head;

    node *newHead = NULL, *newEnd = NULL;

    // Phân chia danh sách liên kết, newHead và newEnd sẽ được cập nhật
    // bởi hàm partition
    node* pivot = partition(head, end, &newHead, &newEnd);

    // Nếu pivot không phải là nút đầu tiên, sắp xếp phần danh sách trước pivot
    if (newHead != pivot) {
        // Lưu lại nút trước pivot để ngắt danh sách
        node* tmp = newHead;
         while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = NULL;

        // Sắp xếp danh sách trước pivot
        newHead = quickSortRecur(newHead, tmp);

        // Thay đổi next của nút cuối cùng của phần danh sách trước pivot để trỏ đến pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    // Sắp xếp danh sách sau pivot
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// Hàm chính để gọi QuickSort
void quickSort(node** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

int main(){
    node* root = NULL;
    //char line[100];
    int mssv;
    char name[50];
    double score;
    char checkEnd[2];
    do {
        scanf("%s", checkEnd); // Đọc MSSV hoặc dấu '#'
        if(strcmp(checkEnd, "#") == 0) break; // Nếu là dấu '#' thì dừng lại
        mssv = atoi(checkEnd); // Chuyển MSSV từ chuỗi sang số
        scanf("%[^0-9] %lf", name, &score); // Đọc tên và điểm
        normalize(name);
        root = llInsertTail(root,mssv,name,score);
       // printf("MSSV: %d, Name: %s, Score: %.1lf\n",mssv,name,score);
    } while(1);
   // getchar(); // Đọc dấu cách cuối cùng
    LLsort(&root);
    LLsortByName(&root);
    countSameScore(root);
    LLprint(root);
    return 0;
}
