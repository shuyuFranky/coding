#include <iostream>

using namespace std;

#define maxn 1000

int arr[maxn + 5];
int dp[maxn + 5];       // dp[i] 1~i子序列的最长上升子序列
int N;

int main() {
    int ans;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[1] = 1; // 初始化
    int m = 0; 
    for (int i = 2; i <= N; i++) {
        m = 0;  // 最大值，找以i结尾最长的上升子序列长度
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                m = max(dp[j], m);
            }
        }
        dp[i] = m + 1;
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    cout << ans << endl;
    return 0;
}
