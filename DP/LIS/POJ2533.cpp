#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 1000

int n;
int arr[maxn + 5];
int dplen;
int dp[maxn + 5];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dplen = 1;
    for (int i = 1; i < n; i++) {
        int pos = lower_bound(dp, dp + dplen, arr[i]) - dp;
        dp[pos] = arr[i];
        dplen = max(pos + 1, dplen);
    }
    cout << dplen << endl;
    return 0;
}
