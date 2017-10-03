/**
* Silver Cow Party
* TLE
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 1000
#define inf 99999999

int e[maxn + 5][maxn + 5];
int N, M, X;

int main() {
    scanf("%d %d %d", &N, &M, &X);
    int x, y, t;
    int max = -1;
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
    // floyd
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (e[i][k] < inf && e[k][j] < inf && e[i][j] > e[i][k] + e[k][j]) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }
    max = -1;
    for (int i = 1; i <= N; i++) {
        tmp = e[i][X] + e[X][i];
        if (max < tmp) {
            max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}