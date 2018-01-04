/**
 * 01 knapsack
 * simple version
 * MLE
 */

#include <iostream>

using namespace std;

#define maxm 12900
#define maxn 3500

struct Good {
    int w;
    int v;
} good[maxn];
int opt[maxn][maxm];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> good[i].w >> good[i].v;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (good[i].w <= j) {
                opt[i][j] = max(opt[i-1][j], opt[i-1][j-good[i].w] + good[i].v);
            } else {
                opt[i][j] = opt[i-1][j];
            }
        }
    }
    cout << opt[N][M] << endl;
    return 0;
}
