/**
 * Kruskal
 * 注意：输出不是最小生成树权值和，而是最小生成树中的最大边
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 505
#define maxe (500*500 / 2 + 5)

struct Edge{
    int u;
    int v;
    int l;
} edge[maxe];
int e[maxn][maxn];
int N, E;
int fa[maxn];
int rk[maxn];

bool mycmp(Edge a, Edge b) {
    return a.l < b.l;
}

void init() {
    int t = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            t++;
            edge[t].u = i;
            edge[t].v = j;
            edge[t].l = e[i][j];
        }
    }
    E = t;
    sort(edge + 1, edge + t + 1, mycmp);
}

void Make_set(int x) {
    fa[x] = -1;
    rk[x] = 0;
}

int Find_set(int x) {
    if (fa[x] < 0) return x;
    return fa[x] = Find_set(fa[x]);
}

void Union(int x, int y) {
    int fx = Find_set(x);
    int fy = Find_set(y);
    if (rk[fx] > rk[fy]) {
        fa[fy] = fx;
    } else if (rk[fx] == rk[fy]) {
        rk[fx] ++;
        fa[fy] = fx;
    } else {
        fa[fx] = fy;
    }
}

void Kruskal() {
    int ans = 0;
    for (int i = 1; i <= N; i++) Make_set(i);
    for (int i = 1; i <= E; i++) {
        int fx = Find_set(edge[i].u);
        int fy = Find_set(edge[i].v);
        if (fx == fy) continue;
        ans = ans < edge[i].l ? edge[i].l : ans;
        Union(fx, fy);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T --) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> e[i][j];
            }
        }
        init();
        Kruskal();
    }
    return 0;
}
