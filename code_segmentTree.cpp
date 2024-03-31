#include <iostream>
using namespace std;
int build(int* a, int* s, int lBnd, int rBnd,int p)
{
	if (lBnd + 1 == rBnd) {
		s[p] = a[lBnd];
		return s[p];
	}
	int m = (lBnd + rBnd) / 2;
	int lSum = build(a, s, lBnd, m, 2 * p);
	int rSum = build(a, s, m, rBnd, 2 * p + 1);
	s[p] = lSum + rSum;
	return s[p];
}
int getSum(int* s, int l, int r, int lBnd, int rBnd ,int p) {
	if (l >= rBnd || r <= lBnd) {
		return 0;
	}
	if (l <= lBnd && r >= rBnd) {
		return s[p];
	}
	int m = (lBnd + rBnd) / 2;
	return getSum(s, l, r, lBnd, m, 2 * p) + getSum(s, l, r, m, rBnd, 2 * p + 1);
}
void alter(int* s, int pos, int change, int lBnd, int rBnd, int p)
{
	s[p] += change;
	if (lBnd + 1 == rBnd) return;
	int m = (lBnd + rBnd) / 2;
	if (pos < m) {
		alter(s, pos, change, lBnd, m, 2 * p);
	}
	else {
		alter(s, pos, change, m, rBnd, 2 * p + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n + 3];
	int* s = new int[4 * n + 6];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	build(a, s, 0, n, 1);
	int Q;
	cin >> Q;
	while (Q--) {
		int commend, v1, v2;
		cin >> commend >> v1 >> v2;
		if (commend == 1) {
			//查询
			cout << getSum(s, v1, v2, 0, n, 1) << endl;
		}
		if (commend == 2) {
			//修改
			int prev = a[v1];
			a[v1] = v2;
			int change = v2 - prev;
			alter(s, v1, change, 0, n, 1);
		}
	}
	return 0;
}