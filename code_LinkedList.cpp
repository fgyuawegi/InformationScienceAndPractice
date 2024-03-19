#include <iostream>
using namespace std;
struct node {
    int index;
    node* next;
};
node* readFunc(int M) {
    node* head=NULL;
    node* tail=NULL;
    bool flag = 0;
    while (M--) {
        int n;
        cin >> n;
        if (flag == 0) {
            node* A = new node;
            A->next = NULL;
            A->index = n;
            head = A;
            tail = A;
            flag = 1;
            continue;
        }
        node* A = new node;
        A->index = n;
        A->next = NULL;
        tail->next = A;
        tail = A;
    }
    return head;
}
void insertFunc(node** head,int idx,int n)
{
    node* cur = *head, * prev = NULL;
            for (int i = 0; i < idx; i++) {
                prev = cur;
                cur = cur->next;
            }
            if (prev == NULL) {
                node* A = new node;
                A->index = n;
                A->next = cur;
                *head = A;
            }
            else {
                node* A = new node;
                A->index = n;
                prev->next = A;
                A->next = cur;
            }
}
void deletleFunc(node** head,int idx)
{
    node* cur = *head, * prev = NULL;
            for (int i = 0; i < idx; i++) {
                prev = cur;
                cur = cur->next;
            }
            if (prev == NULL) {
                *head = cur->next;
                delete cur;
            }
            else {
                prev->next = cur->next;
            }
}
int main()
{
    int M, N;
    cin >> M >> N;
    node* head = readFunc(M);
    for (int i = 0; i < N; i++) {
        bool f;
        cin >> f;
        //插入 
        if (f == 1) {
            int idx, n;
            cin >> idx >> n;
            insertFunc(&head,idx,n);
        }
        //删除
        if (f == 0) {
            int idx;
            cin >> idx;
            deletleFunc(&head,idx);
        }
    }
    for (node* cur = head; cur != NULL; cur = cur->next) {
        cout << cur->index;
        if (cur->next != NULL) {
            cout << " ";
        }
    }
    return 0;
}
