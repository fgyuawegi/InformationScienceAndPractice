#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* next;
};
Node* readData(int N) {
    Node* head;
    bool flag = 0;
    while (N--) {
        int n;
        cin >> n;
        if (flag == 0) {
            Node* A = new Node;
            A->next = NULL;
            A->val = n;
            head = A;
            flag = 1;
            continue;
        }
        Node* A = new Node;
        A->val = n;
        A->next = head;
        head = A;
    }
    return head;
}
int main()
{
    int N;
    cin >> N;
    Node* head = readData(N);
    bool f = 0;
    int now;
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        if (f == 0) {
            now = cur->val;
            f = 1;
            continue;
        }
        if (cur->val < now) {
            now = cur->val;
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}