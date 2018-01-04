/**
 * Investment
 */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define maxn (450000 + 5)

struct Good {
    int w;
    int v;
} good[15];
int T;
int N, Y, M;
int opt[maxn];

int main() {
    ios::sync_with_stdio(false);
    int ans;
    cin >> T;
    while (T--) {
        cin >> M >> Y;
        ans = M;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> good[i].w >> good[i].v;
            good[i].w /= 1000;
        }
        for (int t = 1; t <= Y; t++) {
            M = ans / 1000;
            memset(opt, 0, sizeof(opt));
            for (int i = 1; i <= N; i++) {
                for (int j = good[i].w; j <= M; j++) {
                    if (good[i].w <= j) {
                        opt[j] = max(opt[j], opt[j-good[i].w] + good[i].v);
                    }
                }
            }
            ans += opt[M];
        }
        cout << ans << endl;
    }
    return 0;
}
