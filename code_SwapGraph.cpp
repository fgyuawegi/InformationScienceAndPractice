#include <iostream>
using namespace std;

struct node {
	int index;
	node* next;
};

void readNode(int n,node* ADJ[]) {
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		while (num--) {
			int node_index;
			cin >> node_index;
			node* nNode = new node;
			nNode->index = node_index;
			nNode->next = ADJ[i];
			ADJ[i] = nNode;
		}
	}
}

void reverse(int n, node* ADJ[],node* nADJ[],int lenth[]) {
	for (int i = n - 1;i >= 0;i--) {
		for (node* cur = ADJ[i];cur != NULL;cur = cur->next) {
			node* nNode = new node;
			nNode->index = i;
			nNode->next = nADJ[cur->index];
			nADJ[cur->index] = nNode;
			lenth[cur->index]++;
		}
	}
}

void printNode(int n, node* nADJ[], int lenth[]) {
	cout << n << endl;
	for (int i = 0;i < n;i++) {
		cout << lenth[i] << " ";
		for (node* cur = nADJ[i];cur != NULL;cur = cur->next) {
			cout << cur->index;
			if (cur->next != NULL) {
				cout << " ";
			}
		}
		if (i != n - 1) {
			cout << endl;
		}
	}

}

int main()
{
	//初始化
	int n;
	cin >> n;
	node** ADJ = new node * [n + 3];
	node** nADJ = new node * [n + 3];
	int* newListLenth = new int[n + 3];
	for (int i = 0;i < n;i++) {
		nADJ[i] = NULL;
		ADJ[i] = NULL;
		newListLenth[i] = 0;
	}

	readNode(n, ADJ);
	reverse(n, ADJ, nADJ,newListLenth);
	printNode(n, nADJ,newListLenth);

	delete[] ADJ;
	delete[] nADJ;
	delete[] newListLenth;
	return 0;
}