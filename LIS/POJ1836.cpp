#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 1000

int n;
double arr[maxn + 5];
double dp[maxn + 5];
int dplen;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int k = 1; k <= n; k ++) {
        dp[0] = arr[0];
        dplen = 1;
        for (int i = 1; i < k; i++) {
            int pos = lower_bound(dp, dp + dplen, arr[i]) - dp;
            dp[pos] = arr[i];
            dplen = max(pos + 1, dplen);
        }
        int len_l = dplen;
        dp[0] = arr[k];
        dplen = 1;
        for (int i = k + 1; i < n; i++) {
            int pos = upper_bound(dp, dp + dplen, arr[i]) - dp;
            dp[pos] = arr[i];
            dplen = max(pos + 1, dplen);
        }
        int len_r = dplen;
        if (ans < len_l + len_r) {
            ans = len_l + len_r;
        }
    }
    cout << n - ans << endl;
    return 0;
}
