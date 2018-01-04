/**
 * Prim
 */

#include <iostream>
#include <cstring>
using namespace std;

#define maxn 30
#define inf 1e9

int e[maxn][maxn];
int book[maxn];
int dis[maxn];

int N;
int T;

void init() {
    memset(book, 0, sizeof(book));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    }
}

void Prim() {
    int v;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        dis[i] = e[1][i];
    }
    book[1] = 1;
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
    char c;
    int l;
    while (cin >> N) {
        if (N == 0) break;
        init();
        for (int i = 1; i < N; i++) {
            cin >> c >> T;
            for (int j = 0; j < T; j++) {
                cin >> c >> l;
                if (e[i][c - 'A' + 1] > l) {
                    e[i][c - 'A' + 1] = l;
                    e[c - 'A' + 1][i] = l;
                }
            }
        }
        Prim();
    }
    return 0;
}
