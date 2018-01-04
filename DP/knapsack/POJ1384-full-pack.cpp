/**
 * Piggy-Bank
 * 完全背包
 */

#include <iostream>

using namespace std;

#define maxn 505
#define maxm 10005
//const int INF = 1e10;
#define INF 1e9

struct Good {
    int w;
    int v;
} good[maxn];
int T;
int E, F;
int N, M;
int opt[maxm];

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> E >> F;
        M = F - E;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> good[i].v >> good[i].w;
        }
        for (int j = 0; j <= M; j++) {
            opt[j] = INF;
        }
        opt[0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = good[i].w; j <= M; j++) {
                if (good[i].w <= j) {
                    opt[j] = min(opt[j], opt[j-good[i].w] + good[i].v);
                }
            }
        }
        if (opt[M] < INF) {
            cout << "The minimum amount of money in the piggy-bank is " << opt[M] << "." << endl;
        } else {
            cout << "This is impossible." << endl;
        }
    }
    return 0;
}
