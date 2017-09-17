/**
* 棋盘问题
*/
#include <iostream>

using namespace std;

char map[10][10];
int n, k;
int ans = 0;
int col[10];


void dfs(int ci, int lqz) {
    for (int j = 1; j<=n; j++) {
        if (map[ci][j] == '#' && col[j] == 0) {
            col[j] = 1;
            if (lqz == 1) {
                ans ++;
            }
            for (int i = ci + 1; i<=n-lqz+2; i++)
                dfs(i, lqz-1);
            col[j] = 0;
        }
    }
}

int main() {
    while (cin>>n>>k) {
        if (n == -1 && k == -1) break;
        ans = 0;
        for (int i = 1; i<= n; i++)
            for (int j = 1; j<=n; j++)
                cin>>map[i][j];
        for (int i = 0; i<10; i++)
            col[i] = 0;
        for (int i = 1; i<=n-k+1; i++)
            dfs(i, k);
        cout<<ans<<endl;
    }
    return 0;
}
