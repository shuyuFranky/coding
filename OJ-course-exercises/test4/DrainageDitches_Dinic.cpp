#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define maxn (200 + 5)

const int inf = 1e30;

struct Dinic{
    int c;
    int f;
} edge[maxn][maxn];

int V, E;
int Si, Ei, Ci;
int level[maxn];

int min(int a, int b) {
	return a < b ? a : b;
}

bool dinic_bfs() {
    queue<int> q;
    memset(level, 0, sizeof(level));
    level[1] = 1;
    q.push(1);
    int u, v;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (v = 1; v <= V; v++) {
            if (!level[v] && edge[u][v].c > edge[u][v].f) {
            		level[v] = level[u] + 1;
            		q.push(v);
            }
        }
    }
    return (level[V] != 0);
}

int dinic_dfs(int u, int cp) {
    int tmp = cp, t;
    int v;
    if (u == V) {
        return cp;
    }
    for (v = 1; v <= V && tmp; v++) {
        if (level[v] == level[u] + 1 && edge[u][v].c > edge[u][v].f) {
            t = dinic_dfs(v, min(tmp, edge[u][v].c - edge[u][v].f));
            edge[u][v].f += t;
            edge[v][u].f -= t;
            tmp -= t;
        }
    }
    return cp - tmp;
}

int dinic() {
    int sum = 0, tf = 0;
    while (dinic_bfs()) {
        while (tf = dinic_dfs(1, inf))
            sum += tf;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    int ans;
    while (cin >> E >> V) {
        memset(edge, 0, sizeof(edge));
        while (E--) {
            cin >> Si >> Ei >> Ci;
            edge[Si][Ei].c += Ci;
        }
        ans = dinic();
        cout << ans << endl;
    }
    return 0;
}
