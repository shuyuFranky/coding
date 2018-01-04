/**
 * Prim
 */

#include <iostream>
#include <cstring>
using namespace std;

#define maxn 105
#define inf 1e9

int N, Q;
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

void Prim() {
    int ans = 0;
    int v;
    book[1] = 1;
    for (int i = 1; i <= N; i++) dis[i] = e[1][i];
    for (int i = 1; i < N; i++) {
        int min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        book[v] = 1;
        ans += dis[v];
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] > e[v][j]) {
                dis[j] = e[v][j];
            }
        }
    }
    cout << ans << endl;
}

int main() {
	int x, y;
    init();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> e[i][j];
        }
    }
    cin >> Q;
    while (Q--) {
        cin >> x >> y;
        e[x][y] = e[y][x] = 0;
    }
    Prim();
    return 0;
}
