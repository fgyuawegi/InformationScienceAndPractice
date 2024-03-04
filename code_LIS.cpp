#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* a = new int[n + 5];
	int* l = new int[n + 5];
	int* p = new int[n + 5];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	l[0] = 1;
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (l[j] > max && a[i] > a[j]) max = l[j];
		}
		l[i] = max + 1;
	}
	int t = l[0];
	for (int i = 1; i < n; i++) {
		if (l[i] > t) {
			t = l[i];
		}
	}
	cout << t << endl;
	int t1 = t;
	int now = 99999999;
	for (int i = n - 1; i >= 0; i--) {
		if ((l[i] == t) && (a[i] < now)) {
			t--;
			now = a[i];
			p[t] = a[i];
		}
	}
	for (int i = 0; i < t1; i++) {
		if (i == t1 - 1) {
			cout << p[i];
			return 0;
		}
		cout << p[i] << " ";
	}

}