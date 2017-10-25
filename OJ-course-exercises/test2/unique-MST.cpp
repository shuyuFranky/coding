//============================================================================
// Name        : unique-MST.cpp
// Author      : yushu
//============================================================================
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define maxn 1000
#define inf 9999999

struct edge{
    int v;
    int u;
};

int e[maxn + 5][maxn + 5];
int book[maxn + 5];
int dis[maxn + 5];
int start[maxn + 5];
queue<edge > q;
int ans;
int n, m;
bool uq = true;

bool Full() {
    for (int i = 0; i < n; i++) {
        if (book[i] == 0) return false;
    }
    return true;
}

int prim(bool adde) {
    book[0] = 1;
    int i, j;
    int min = inf;
    int v, u;
    int res = 0;
    for (i = 0; i < n; i++) {
        min = inf;
        for (j = 0; j < n; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        if (min == inf) return res;
        book[v] = 1;
        res += min;
        edge ce;
        ce.u = start[v];
        ce.v = v;
        if (adde) q.push(ce);
        for (u = 0; u < n; u++) {
             if (!book[u] && e[v][u] < dis[u]) {
                 dis[u] = e[v][u];
                 start[u] = v;
             }
        }
    }
    return res;
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            e[i][j] = inf;
        }
    }
    memset(book, 0, sizeof(book));
    while (!q.empty()) q.pop();
    uq = true;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    int u, v, w;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            if (e[u-1][v-1] > w) {
                e[u-1][v-1] = w;
                e[v-1][u-1] = w;
            }
        }
        for (int i = 0; i < n; i++) {
            dis[i] = e[0][i];
            start[i] = 0;
        }
        ans = prim(true);
        while (!q.empty()) {
            edge re = q.front();
            w = e[re.v][re.u];
            e[re.v][re.u] = inf;
            e[re.u][re.v] = inf;
            for (int i = 0; i < n; i++) {
                dis[i] = e[0][i];
                start[i] = 0;
            }
            memset(book, 0, sizeof(book));
            int tmp = prim(false);
            if (tmp == ans && Full()) {
                uq = false;
                break;
            }
            q.pop();
            e[re.v][re.u] = w;
            e[re.u][re.v] = w;
        }
        if (uq) cout << ans << endl;
        else {
        		//cout << ans << endl;
        		cout << "Not Unique!" <<endl;
        }
    }
    return 0;
}
