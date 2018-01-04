/**
 * 食物链
 */

#include <iostream>

using namespace std;

#define maxn 50005

int fa[maxn];
int ate_by[maxn];
int rk[maxn];

int N, K;

void Make_set(int x) {
    fa[x] = -1;
    rk[x] = 0;
    ate_by[x] = 0;
}

int Find_set(int x) {
    if (fa[x] < 0) return x;
    else return fa[x] = Find_set(fa[x]);
}

void Union(int x, int y) {
    int xf = Find_set(x);
    int yf = Find_set(y);
    if (xf == yf) return;
    if (rk[xf] > rk[yf]) {
        fa[yf] = xf;
    } else if (rk[xf] == rk[yf]) {
        rk[xf] ++;
        fa[yf] = xf;
    } else {
        fa[xf] = yf;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) Make_set(i);
    int ans = 0;
    int op, x, y;
    while (K--) {
        cin >> op >> x >> y;
        if (x > N || y > N) {
            ans ++;
            continue;
        }
        if (op == 1) {
            int fx = Find_set(x);
            int fy = Find_set(y);
            if (fx == fy) continue;
            if (ate_by[fx] == ate_by[fy] || ate_by[fx] == 0 || ate_by[fy] == 0) {
                // merge
                if (rk[fx] > rk[fy]) {
                    fa[fy] = fx;
                } else if(rk[fx] == rk[fy]) {
                    rk[fx] ++;
                    fa[fy] = fx;
                } else {
                    fa[fx] = fy;
                }
            } else {
                ans ++;
                continue;
            }
        } else {
            if (x == y) {
                ans ++;
                continue;
            }
            int fx = Find_set(x);
            int fy = Find_set(y);
            if (fx == fy) {
                ans ++;
                continue;
            }
            if (ate_by[fy] != 0 && ate_by[fy] != fx) {
                ans ++;
                continue;
            } else {
                ate_by[fy] = fx;
            }
        }
    }
    cout << ans << endl;
    return 0;
}