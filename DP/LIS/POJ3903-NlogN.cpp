#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define maxn 100000
#define inf 1e8

int N;
int arr[maxn + 5];
int dp[maxn + 5];
int g[maxn + 5];

int main() {
    ios::sync_with_stdio(false);
    while(cin >> N) {
        for(int i = 1; i <= N; i++)
            cin >> arr[i];

        for(int i = 1; i <= N; i++)
            g[i] = inf;

        int ans = 0;
        for(int i = 1; i <= N; i++) {
            int k = lower_bound(g+1, g+N+1, arr[i]) - g;
            dp[i] = k;
            g[k] = arr[i];
            ans = max(ans, k);
        }
        cout << ans << endl;
    }
    return 0;
}