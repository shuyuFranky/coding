/**
 * MPI Maelstrom
 * Bellman-Ford
 * 注意读入技巧
 */

#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 105
#define inf 1e9

int e[maxn][maxn];
int dis[maxn];
int N;

void bellman_ford() {
    for (int i = 1; i <= N; i++) dis[i] = e[1][i];
    for (int t = 1; t < N; t++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dis[j] > dis[i] + e[i][j]) {
                    dis[j] = dis[i] + e[i][j];
                }
            }
        }
    }
}

int main() {
    char cost[10];
    int ans = 0;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
    		getchar();
        for (int j = 1; j <= i-1; j++) {
            scanf("%s", cost);
            if (cost[0] == 'x') {
                e[i][j] = inf;
                e[j][i] = inf;
            } else {
                sscanf(cost, "%d", &e[i][j]);
                e[j][i] = e[i][j];
            }
        }
    }
    bellman_ford();
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dis[i]); 
    }
    printf("%d\n", ans);
    return 0;
}
