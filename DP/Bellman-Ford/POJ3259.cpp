/**
 * Wormholes
 */
#include <iostream>
#include <cstring>
using namespace std;

#define maxn 510
#define maxe 3000
#define inf 1e9

struct edge {
    int u;
    int v;
    int w;
} e[maxe*2];
int dis[maxn];
int N, M, W;
int all;

void Bellman_Ford() {
    for (int i = 0; i <= N; i++) dis[i] = inf;
    dis[1] = 0;
    bool flag = false;
    for (int i = 1; i < N; i++) {
        flag = false;
        for (int j = 0; j < all; j++) {
            if (dis[e[j].v] > dis[e[j].u] + e[j].w) {
                dis[e[j].v] = dis[e[j].u] + e[j].w;
                flag = true;
            }
        }
        if (!flag) break;
    }
    // check 
    flag = false;
    for (int j = 0; j < all; j++) {
        if (dis[e[j].v] > dis[e[j].u] + e[j].w) {
            //dis[e[j].v] = dis[e[j].u] + e[j].w;
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int from, to, w;
    while (T --) {
        cin >> N >> M >> W;
        all = 0;
        for (int i = 0; i < M; i++) {
            cin >> from >> to >> w;
            e[all].u = from;
            e[all].v = to;
            e[all++].w = w;
            e[all].u = to;
            e[all].v = from;
            e[all++].w = w;
        }
        for (int i = 0; i < W; i++) {
            cin >> from >> to >> w;
            e[all].u = from;
            e[all].v = to;
            e[all++].w = 0 - w;
        }
        Bellman_Ford();
    }
    return 0;
}