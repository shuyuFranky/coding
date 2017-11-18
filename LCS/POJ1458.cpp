#include <iostream>
#include <string>

using namespace std;

#define maxn 20000

string x;
string y;
int dp[maxn + 5][maxn + 5];
int n, m;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> x >> y) {
        n = x.length();
        m = y.length();
        for (int i = 0; i <= n; i++)
        		dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
        		dp[0][j] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i-1] == y[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
