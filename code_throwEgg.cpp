#include <iostream>
#include <cmath>
#define MAXK 8
#define MAXN 205
using namespace std;
int p(int LEN[MAXK][MAXN], int k, int s)
{
	if (LEN[k][s] != -1) {
		return LEN[k][s];
	}
	if (k == 1) {
		LEN[k][s] = s;
		return s;
	}
	if (s == 1) {
		LEN[k][s] = 1;
		return 1;
	}
	if (s == 0) {
		LEN[k][s] = 0;
		return 0;
	}
	LEN[k][s] = p(LEN, k - 1, s - 1) + p(LEN, k, s - 1) + 1;
	return LEN[k][s];
}
int standard(int K, int N) {//这个函数是我找的leetcode题解，用于验证答案正确性
	if (K == 1 || N == 1 || N == 2)     return N;

	int* dp = (int*)malloc((K + 1) * sizeof(int));
	for (int i = 1; i <= K; i++)    dp[i] = 1;

	int m = 2; // 从第二步开始计算
	while (true) {
		for (int k = K; k > 1; k--)    dp[k] = dp[k] + dp[k - 1] + 1;
		// 从后向前计算，以免 k-1 位置过早被新值覆盖，导致后续计算错误。
		//相当于还带有m-1，dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1，形式上省略了

		if (dp[K] >= N)   return m;  // 判断是否满足条件
		else {
			dp[1] = m;  // 覆盖首位值
			m++;  // 进入下一步
		}
	}
}

int main()
{
	int LEN[MAXK][MAXN];
	for (int i = 0;i < MAXK;i++) {
		for (int j = 0;j < MAXN;j++) {
			LEN[i][j] = -1;
		}
	}
	p(LEN, 5, 200);
	int N;
	cin >> N;
	while (N--) {
		int k, n;
		cin >> k >> n;
		for (int s = 1;s < MAXN;s++) {
			if (LEN[k][s] >= n) {
				if (s == standard(k,n)) cout << s;
				else cout << "wrong";
				break;
			}
		}
		if (N != 1) {
			cout << endl;
		}
	}
	return 0;
}
