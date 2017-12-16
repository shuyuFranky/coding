#include <iostream>

using namespace std;

#define maxn 100
const int inf = 1e10;

int N;
int dp[maxn + 5][maxn + 5];
int arr[maxn + 5];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = N - 2; i >= 1; i--) {
        for (int j = i + 2; j <= N; j++) {
            dp[i][j] = inf;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    cout << dp[1][N] << endl;
    return 0;
}
