#include <iostream>

using namespace std;

#define maxn 5000

int N;
char arr[maxn + 5];
//char rev_arr[maxn + 5];
int dp[2][maxn + 5];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    cin >> N;
    for (int i = 0, j = N - 1; i < N; i++, j--) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1, t = N; j <= N; j++, t--) {
            if (arr[i - 1] == arr[t - 1]) {
                dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
            } else {
                dp[i%2][j] = max(dp[i%2][j-1], dp[(i-1)%2][j]);
            }
        }
    }
    cout << N - dp[N%2][N] << endl;
    return 0;
}