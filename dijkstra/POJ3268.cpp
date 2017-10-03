/**
* Silver Cow Party
* two dijkstra
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 1000
#define inf 99999999

int eGo[maxn + 5][maxn + 5];
int eBack[maxn + 5][maxn + 5];
int goBook[maxn + 5];
int backBook[maxn + 5];
int goDis[maxn + 5];
int backDis[maxn + 5];
int N, M, X;

void goDijkstra() {
    int min = inf;
    int v;
    memset(goBook, 0, sizeof(goBook));
    goBook[X] = 1;
    for (int i = 1; i < N; i++) {
        min = inf;
        for (int j = 1; j <= N; j++) {
            if (goBook[j] == 0 && min > goDis[j]) {
                min = goDis[j];
                v = j;
            }
        }
        goBook[v] = 1;
        for (int j = 1; j <= N; j++) {
            if (eGo[v][j] < inf && goDis[j] > goDis[v] + eGo[v][j]) {
                goDis[j] = goDis[v] + eGo[v][j];
            }
        }
    }
}

void backDijkstra() {
    int min = inf;
    int v;
    memset(backBook, 0, sizeof(backBook));
    backBook[X] = 1;
    for (int i = 1; i < N; i++) {
        min = inf;
        for (int j = 1; j <= N; j++) {
            if (backBook[j] == 0 && min > backDis[j]) {
                min = backDis[j];
                v = j;
            }
        }
        backBook[v] = 1;
        for (int j = 1; j <= N; j++) {
            if (eBack[v][j] < inf && backDis[j] > backDis[v] + eBack[v][j]) {
                backDis[j] = backDis[v] + eBack[v][j];
            }
        }
    }
}

int main() {
    int x, y, t;
    int max = -1;
    int tmp = 0;
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                eGo[i][j] = 0;
                eBack[i][j] = 0;
            } else {
                eGo[i][j] = inf;
                eBack[i][j] = inf;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d", &x, &y, &t);
        eGo[y][x] = t;
        eBack[x][y] = t;
    }
    for (int i = 1; i <= N; i++) {
        goDis[i] = eGo[X][i];
        backDis[i] = eBack[X][i];
    }
    goDijkstra();
    backDijkstra();
    for (int i = 1; i <= N; i++) {
        tmp = goDis[i] + backDis[i];
        if (max < tmp) {
            max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}