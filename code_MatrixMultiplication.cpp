#include <iostream>
using namespace std;
#define MAXN 1000
struct node
{
	int DATA;
	int col;
	int row;
	node* colNext;
	node* rowNext;
};
struct MATRIX
{
	struct node* columns[MAXN];
	struct node* rows[MAXN];
	int colN;
	int rowN;
};
void writeFunc(MATRIX* M, int i, int j, int d)
{
	node* A = new node;
	A->DATA = d;
	A->row = i;
	A->col = j;
	A->colNext = NULL;
	A->rowNext = NULL;
	if (M->rows[i] == NULL) {
		M->rows[i] = A;
	}
	else {
		node* cur = M->rows[i];
		while (cur->rowNext != NULL) {
			cur = cur->rowNext;
		}
		cur->rowNext = A;
	}
	if (M->columns[j] == NULL) {
		M->columns[j] = A;
	}
	else {
		node* cur = M->columns[j];
		while (cur->colNext != NULL) {
			cur = cur->colNext;
		}
		cur->colNext = A;
	}
}
void initMatrix(MATRIX* M)
{
	int m;
	cin >> m;
	while (m--) {
		int i, j, d;
		cin >> i >> j >> d;
		writeFunc(M, i-1, j-1, d);
	}
}
void printMatrix(MATRIX* M)
{
	for (int i = 0;i < M->rowN;i++) {
		for (node* cur = M->rows[i];cur != NULL;cur = cur->rowNext) {
			cout << cur->row+1 << " " << cur->col+1 << " " << cur->DATA << endl;
		}
	}
}
int main()
{
	//初始化矩阵
	int p, q, r;
	cin >> p >> q >> r;
	MATRIX* leftMATRIX = new MATRIX;
	MATRIX* rightMATRIX = new MATRIX;
	leftMATRIX->colN = q;
	leftMATRIX->rowN = p;
	rightMATRIX->colN = r;
	rightMATRIX->rowN = q;
	for (int i = 0;i < MAXN;i++) {
		leftMATRIX->rows[i] = NULL;
		leftMATRIX->columns[i] = NULL;
		rightMATRIX->rows[i] = NULL;
		rightMATRIX->columns[i] = NULL;
	}
	initMatrix(leftMATRIX);
	initMatrix(rightMATRIX);
	//printMatrix1(leftMATRIX);
	//printMatrix(rightMATRIX);
	//return 0;
	//计算
	MATRIX* result = new MATRIX;
	result->colN = rightMATRIX->colN;
	result->rowN = leftMATRIX->rowN;
	for (int i = 0;i < MAXN;i++) {
		result->rows[i] = NULL;
		result->columns[i] = NULL;
	}
	int totalNum = 0;
	for (int i = 0;i < leftMATRIX->rowN;i++) {
		for (int j = 0;j < rightMATRIX->colN;j++) {
			//计算i行j列的值
			int SUM = 0;
			node* leftCur = leftMATRIX->rows[i];
			node* rightCur = rightMATRIX->columns[j];
			while (leftCur != NULL && rightCur != NULL) {
				if (leftCur->col == rightCur->row) {
					SUM += leftCur->DATA * rightCur->DATA;
					leftCur = leftCur->rowNext;
					rightCur = rightCur->colNext;
				}
				else if (leftCur->col > rightCur->row) {
					rightCur = rightCur->colNext;
				}
				else {
					leftCur = leftCur->rowNext;
				}
			}
			if (SUM != 0) {
				totalNum++;
				writeFunc(result, i, j, SUM);
			}
		}
	}
	cout << totalNum << endl;
	printMatrix(result);
	return 0;
}