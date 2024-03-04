#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* a = new int[n + 5];
	int* b = new int[n + 5];
	int maxDigit = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		int temp = a[i];
		int digit = 0;
		while (temp > 0) {
			temp /= 10;
			digit++;
		}
		if (digit > maxDigit) {
			maxDigit = digit;
		}
	}
	int BASE = 1;
	int pos[10];
	for (int d = 0;d < maxDigit;d++) {
		for (int i = 0;i < 10;i++) {
			pos[i] = 0;
		}
		for (int i = 0;i < n;i++) {
			int temp = (a[i] / BASE) % 10;
			for (int j = temp + 1;j <= 9;j++) {
				pos[j]++;
			}
		}
		for (int i = 0;i < n;i++) {
			b[pos[(a[i] / BASE) % 10]] = a[i];
			pos[(a[i] / BASE) % 10]++;
		}
		for (int i = 0;i < n;i++) {
			a[i] = b[i];
		}
		BASE *= 10;
	}
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
	return 0;
}