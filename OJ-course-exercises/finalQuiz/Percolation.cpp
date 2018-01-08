#include <iostream>
#include <cstring>
using namespace std;

#define maxn 1010

bool flag;
int N, M, T;
int fa[maxn*maxn];
int rk[maxn*maxn];
int xarr[4] = {-1, 1, 0, 0};
int yarr[4] = {0, 0, -1, 1};
bool open[maxn][maxn];

void Make_set(int x) {
    fa[x] = -1;
    rk[x] = 0;
}

int Find_set(int x) {
    if (fa[x] < 0) return x;
    return fa[x] = Find_set(fa[x]);
}

bool check() {
    if (Find_set(1) == Find_set(N*N)) {
        flag = true;
        return true;
    }
    else return false;
}

void Union(int x, int y) {
    int fx = Find_set(x);
    int fy = Find_set(y);
    if (fx == fy) return;
    if (rk[fx] > rk[fy]) {
        fa[fy] = fx;
    } else if (rk[fx] == rk[fy]) {
        rk[fx] ++;
        fa[fy] = fx;
    } else {
        fa[fx] = fy;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    int x, y;
    int x_, y_;
    int ans = -1;
    while (T --) {
        cin >> N >> M;
        flag = false;
        ans = -1;
        memset(open, false, sizeof(open));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                Make_set((i-1)*N + j);
            }
        }
        for (int i = 2; i <= N; i++) fa[i] = 1;
        for (int i = N*(N-1) + 1; i < N*N; i++) fa[i] = N*N;
        for (int i = 1; i <= M; i++) {
            cin >> x >> y;
            if (flag) continue;
            open[x][y] = true;
            for (int j = 0; j < 4; j++) {
                x_ = xarr[j] + x;
                y_ = yarr[j] + y;
                if (open[x_][y_] && x_ >= 1 && x_ << N && y >= 1 && y_ <= N) {
                    Union((x-1)*N + y, (x_-1)*N + y_);
                    if (check() && flag) ans = i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
