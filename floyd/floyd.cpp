/**
*
*/
#include <iostream>

using namespace std;

#define maxn 1000
#define inf 99999999

int e[maxn + 5][maxn + 5];

int main() {
    int n, m;
    int x, y, w;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        e[x][y] = w;
    }
    // 核心算法
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (e[i][k] < inf && e[k][j] < inf && e[i][j] > e[i][k] + e[k][j]) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
    // 输出结果
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cout << i << " " << j << " " << e[i][j] << " " <<endl;
        }
    return 0;
}