/**
 * Ubiquitous Religions
 */

#include <iostream>

using namespace std;

#define maxn 50005

int fa[maxn];
int rk[maxn];
int cnt;
int N, M;

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
    if (fx == fy) return;
    cnt --;
    if (rk[fx] > rk[fy]) {
        fa[fy] = fx;
    } else if (rk[fx] == rk[fy]){
        rk[fx] ++;
        fa[fy] = fx;
    } else {
        fa[fx] = fy;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int x, y;
    int t = 0;
    while(cin >> N >> M) {
        if (N == 0) break;
        t++;
        cnt = N;
        for (int i = 1; i <= N; i++) Make_set(i);
        while (M --) {
            cin >> x >> y;
            Union(x, y);
        }
        cout << "Case " << t << ": " << cnt << endl;
    }
    return 0;
}
