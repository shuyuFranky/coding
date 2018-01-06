/**
 * MPI Maelstrom
 * 注意读入技巧
 */

#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 105
#define inf 1e9

int e[maxn][maxn];
int book[maxn];
int dis[maxn];
int N;

void dijkstra() {
    int v;
    for (int i = 1; i <= N; i++) {
        dis[i] = e[1][i];
    }
    book[1] = 1;
    for (int i = 1; i < N; i++) {
        int min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[v = j];
            }
        }
        book[v] = 1;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] > dis[v] + e[v][j]) {
                dis[j] = dis[v] + e[v][j];
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
    dijkstra();
    for (int i = 1; i <= N; i++) {
    	ans = max(ans, dis[i]); 
    }
    printf("%d\n", ans);
    return 0;
}
