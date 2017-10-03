/**
* Tram
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100
#define inf 999999

int e[maxn + 5][maxn + 5];
int book[maxn + 5];
int dis[maxn + 5];
int N, A, B;

void dijkstra() {
    int min = inf;
    int v;
    memset(book, 0, sizeof(book));
    book[A] = 1;
    for (int i = 1; i < N; i++) {
        min = inf;
        for (int j = 1; j <= N; j++) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        book[v] = 1;
        for (int j = 1; j <= N; j++) {
            if (e[v][j] < inf && dis[j] > dis[v] + e[v][j]) {
                dis[j] = dis[v] + e[v][j];
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &A, &B);
    int t, p;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &t);
        if (t == 0) continue;
        scanf("%d", &p);
        e[i][p] = 0;
        t--;
        while (t--) {
            scanf("%d", &p);
            e[i][p] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        dis[i] = e[A][i];
    }
    dijkstra();
    if (dis[B] == inf) {
        printf("-1\n");
    } else {
        printf("%d\n", dis[B]);
    }
    return 0;
}