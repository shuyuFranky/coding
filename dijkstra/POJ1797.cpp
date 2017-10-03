/**
*   Heavy Transportation
*/

#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 1000

int N, M;
int e[maxn + 5][maxn + 5];
int book[maxn + 5];
int dis[maxn + 5];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int Scenario;
    scanf("%d", &Scenario);
    int s = 0;
    int x, y, w;
    int max = -1;
    int v, mw;
    while (s < Scenario) {
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) e[i][j] = 0;
                else e[i][j] = -1;
            }
        }
        for (int i = 1; i <= M; i++) {
            scanf("%d %d %d", &x, &y, &w);
            e[x][y] = w; 
            e[y][x] = w;            
        }
        for (int i = 1; i <= N; i++) {
            dis[i] = e[1][i];
            book[i] = 0;
        }
        book[1] = 1;
        for (int i = 1; i < N; i++) {
            max = -1;
            for (int j = 1; j <= N; j++) {
                if (book[j] == 0 && max < dis[j]) {
                    max = dis[j];
                    v = j;
                }
            }
            book[v] = 1;
            for (int j = 1; j <= N; j++) {
                if (e[v][j] > 0) {
                    mw = min(dis[v], e[v][j]);
                    if (dis[j] < mw) {
                        dis[j] = mw;
                    }
                }
            }
        }
        printf("Scenario #%d:\n", ++s);
        printf("%d\n\n", dis[N]);
    }
    return 0;
}