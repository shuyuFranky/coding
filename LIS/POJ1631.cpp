#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 40000

int arr[maxn + 5];
int dp[maxn + 5];
int n;
int dplen;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        dplen = 1;
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            int pos = lower_bound(dp, dp + dplen, arr[i]) - dp;
            dp[pos] = arr[i];
            dplen = max(pos + 1, dplen);
        }
        cout << dplen << endl;
    }
    return 0;
}