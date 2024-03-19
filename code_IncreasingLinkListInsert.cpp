#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* next;
};
Node* readFunc(int M) {
    Node* head=NULL;
    Node* tail=NULL;
    bool flag = 0;
    while (M--) {
        int n;
        cin >> n;
        if (flag == 0) {
            Node* A = new Node;
            A->next = NULL;
            A->val = n;
            head = A;
            tail = A;
            flag = 1;
            continue;
        }
        Node* A = new Node;
        A->val = n;
        A->next = NULL;
        tail->next = A;
        tail = A;
    }
    return head;
}
int main()
{
    int M,N;
    cin >> M>>N;
    Node* head = readFunc(M);
    Node* cur=head;
    Node* prev=NULL;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        for(;cur!=NULL;prev=cur,cur=cur->next){
            if(cur->val>n){
                if(prev==NULL){
                    Node* A=new Node;
                    A->val=n;
                    A->next=cur;
                    head=A;
                    break;
                }
                Node* A=new Node;
                A->val=n;
                A->next=cur;
                prev->next=A;
                break;
            }
        }
        if(cur==NULL){
            Node* A=new Node;
            A->val=n;
            A->next=cur;
            prev->next=A;
            break;
        }
    }
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        cout << cur->val;
        if (cur->next != NULL) {
            cout << " ";
        }
    }
    return 0;
}