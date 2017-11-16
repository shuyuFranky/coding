#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 100
#define INF 9999999

int a[maxn + 5][maxn + 5];
int dp[maxn + 5][maxn + 5];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
                dp[i][j] = -INF;
            }
        }
        for(int i = 0; i <= m; i++)
            dp[0][i] = 0;

        dp[1][1] = a[1][1];

        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= m; j++) {
                for(int k = 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
                }
            }
        }
        int ans = -INF;
        for(int i = 1; i <= m; i++)
        {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
