/**
 * Prim
 * Highways
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 760
#define inf 1e9

struct Node {
    int x;
    int y;
} node[maxn];
int N, M;
double dis[maxn];
int p[maxn];
int book[maxn];
double e[maxn][maxn];

double getDis(int a, int b) {
    int x = node[a].x - node[b].x;
    int y = node[a].y - node[b].y;
    return sqrt((x*x + y*y));
}

void init() {
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
            if (i == j) e[i][j] = 0;
            else e[i][j] = e[j][i] = getDis(i, j);
}

void Prim() {
    int v;
    book[1] = 1;
    for (int i = 1; i <= N; i++) {
        dis[i] = e[1][i];
        p[i] = 1;
    }
    for (int i = 1; i < N; i++) {
        double min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        book[v] = 1;
        if (min != 0) cout << p[v] << " " << v << endl;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] > e[v][j]) {
                dis[j] = e[v][j];
                p[j] = v;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> node[i].x >> node[i].y;
    }
    init();
    cin >> M;
    while (M--) {
        cin >> a >> b;
        e[a][b] = e[b][a] = 0;
    }
    Prim();
    return 0;
}
