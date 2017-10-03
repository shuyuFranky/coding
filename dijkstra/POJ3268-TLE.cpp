/**
* Silver Cow Party
* TLE
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 1000
#define inf 999999999

int e[maxn + 5][maxn + 5];
int p[maxn + 5][maxn + 5];
int book[maxn + 5];
int N, M, X;

int main() {
    scanf("%d %d %d", &N, &M, &X);
    int x, y, t;
    int min = inf, max = -1;
    int u;
    int tmp;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d", &x, &y, &t);
        e[x][y] = t;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; i <= N; j++) {
            p[i][j] = e[i][j];
        }
    }
    for (int v = 1; v <= N; v++) {
        memset(book, 0, sizeof(book));
        book[v] = 1; 
        for (int i = 1; i < N; i++) {
            min = inf;
            for (int j = 1; j<=N; j++) {
                if (book[j] == 0 && min > p[v][j]) {
                    min = p[v][j];
                    u = j;
                }
            }
            book[u] = 1;
            for (int j = 1; j <= N; j++) {
                if (e[u][j] < inf) {
                    if (p[v][j] > p[v][u] + e[u][j]) {
                        p[v][j] = p[v][u] + e[u][j]; 
                    }
                }
            }
        }
    }
    max = -1;
    for (int i = 1; i <= N; i++) {
        tmp = p[i][X] + p[X][i];
        if (max < tmp) {
            max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}