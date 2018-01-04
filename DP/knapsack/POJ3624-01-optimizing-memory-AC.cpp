/**
 * 01 knapsack
 * optimizing memory version
 * MLE
 */

#include <iostream>

using namespace std;

#define maxn 3410
#define maxm 12900

struct Good {
    int w;
    int v;
} good[maxn];
int N, M;
int opt[maxm];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> good[i].w >> good[i].v;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= 0; j--) {
            if (good[i].w <= j) {
                opt[j] = max(opt[j], opt[j-good[i].w] + good[i].v); 
            }
        }
    }
    cout << opt[M] << endl;
    return 0;
}