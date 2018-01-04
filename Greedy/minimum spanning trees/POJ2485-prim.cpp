/**
 * Prim
 * 注意：输出不是最小生成树权值和，而是最小生成树中的最大边
 */

#include <iostream>
#include <cstring>

using namespace std;

#define maxn 505
#define inf 1e9

int T, N;
int e[maxn][maxn];
int book[maxn];
int dis[maxn];

void Prim() {
    int v;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        dis[i] = e[1][i];
    }
    memset(book, 0, sizeof(book));
    book[1] = 1;
    for (int i = 1; i < N; i++) {
        int  min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        book[v] = 1;
        ans = ans < dis[v] ? dis[v] : ans;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] > e[v][j]) {
                dis[j] = e[v][j];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> e[i][j];
            }
        }
        Prim();
    }
    return 0;
}
