/**
 * 昂贵的婚礼
 */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define maxn 105
#define inf 1e9

struct Good {
    int c;
    int l;
} good[maxn];
int M, N;
int e[maxn][maxn];
int dis[maxn];
int book[maxn];

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    }
}

int dijkstra() {
    int v;
    book[0] = 1;
    for (int i = 1; i <= N; i++) {
        dis[i] = good[i].c;
    }
    for (int i = 1; i < N; i++) {
        int min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[v = j];
            }
        }
        book[v] = 1;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] > dis[v] + e[j][v]) {
                dis[j] = dis[v] + e[j][v];
            }
        }
    }
    return dis[1];
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    int v, w;
    cin  >> M >> N;
    init();
    for (int i = 1; i <= N; i++) {
        cin >> good[i].c >> good[i].l >> t;
        while (t --) {
            cin >> v >> w;
            e[i][v] = w;
        }
    }
    int tmp_ans;
    int ans = inf;
    for (int i = good[1].l - M; i <= good[1].l; i++) {
        memset(book, 0, sizeof(book));
        for (int j = 1; j <= N; j++) {
            if (good[j].l < i || good[j].l - i > M) book[j] = 1;
        }
        tmp_ans = dijkstra();
        ans = min(tmp_ans, ans);
    }
    cout << ans << endl;
    return 0;
}
