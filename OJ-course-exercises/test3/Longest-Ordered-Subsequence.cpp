/*
* Longest Ordered Subsequence
* O(n^2)
*/
#include <iostream>

using namespace std;

#define maxn 1000

int N;
int arr[maxn + 5];
int f[maxn + 5];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    f[1] = 1;
    int m;
    int ans = 1;
    for (int i = 2; i <= N; i++) {
        m = 0;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i])
                m = max(f[j], m);
        }
        f[i] = m + 1;
        if (ans < f[i]) {
        		ans = f[i];
        }
    }
    cout << ans << endl;
    return 0;
}
