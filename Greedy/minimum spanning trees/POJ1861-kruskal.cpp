/**
 * Kruskal
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 1005
#define maxe 15005

struct Edge {
    int u;
    int v;
    int l;
} e[maxe];
int N, M;
int fa[maxn];
int rk[maxn];
int res[maxe][2];

bool mycmp(Edge a, Edge b) {
    return a.l < b.l;
}

void Make_Set(int x) {
    fa[x] = -1;
    rk[x] = 0;
}

int Find_Set(int x) {
    if (fa[x] < 0) return x;
    return fa[x] = Find_Set(fa[x]);
}

void Union(int x, int y) {
    if (rk[x] > rk[y]) {
        fa[y] = x;
    } else if (rk[x] == rk[y]) {
        rk[x] ++;
        fa[y] = x;
    } else {
        fa[x] = y;
    }
}

void Kruskal() {
    int sum = 0;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= N; i++) Make_Set(i);
    for (int i = 1; i <= M; i++) {
        int fx = Find_Set(e[i].u);
        int fy = Find_Set(e[i].v);
        if (fx == fy) continue;
        sum += e[i].l;
        ans = ans < e[i].l ? e[i].l : ans;
        res[cnt][0] = e[i].u;
        res[cnt][1] = e[i].v;
        cnt ++;
        Union(fx, fy);
    }
    cout << ans << endl;
    cout << sum << endl;
    for (int i = 0; i < cnt; i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> e[i].u >> e[i].v >> e[i].l;
    }
    sort(e + 1, e + M + 1, mycmp);
    Kruskal();
    return 0;
}