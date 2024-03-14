#include <iostream>
using namespace std;
bool jd(int cnt[], int n)
{
    for (int i = 0;i < n;i++) {
        if (cnt[i] > 0) return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    int* cnt = new int[n];
    int* s = new int[n];
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        s[i] = 0;
        cnt[i] = 0;
    }
    for (int i = 0;i < n;i++) {
        if (a[i] == -1) continue;
        cnt[a[i]]++;
    }
    while (jd(cnt, n)) {
        for (int i = 0;i < n ;i++) {
            if (a[i] == -1) continue;
            if (cnt[i] == 0) {
                cnt[a[i]]--;
                s[a[i]] = s[a[i]] + s[i] + 1;
                cnt[i] = -1;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        cout << s[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}