/**
 * 完全背包
 * WA : 数很大，超过 unsign long long
 */

#include <iostream>
using namespace std;
#define maxn 100

int N, K;
int opt[maxn + 5][10 * maxn + 5];

int main() {
    cin >> N >> K;
    opt[0][0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int k = 0; k <= N; k += i) {
            for (int j = N; j >= k; j--) {
                opt[i][j] += opt[i-1][j-k];
            }
        }
    }
    cout << opt[K][N] << endl;
    return 0;
}


//-----------------------------------------------------------
/**
 * 完全背包 + 大数加法
 * AC
 */

#include <iostream>
using namespace std;
#define maxn 100
#define LIMIT_ULL 100000000000000000

int N, K;
unsigned long long opt[maxn + 5][10*maxn + 5][2];

int main() {
    cin >> N >> K;
    opt[0][0][1] = 1;
    for (int i = 1; i <= K; i++) {
        for (int k = 0; k <= N; k += i) {
            for (int j = N; j >= k; j--) {
                opt[i][j][0] += opt[i-1][j-k][0];
                opt[i][j][1] += opt[i-1][j-k][1];
                opt[i][j][0] += opt[i][j][1] / LIMIT_ULL;
                opt[i][j][1] = opt[i][j][1] % LIMIT_ULL;
            }
        }
    }
    if (opt[K][N][0]) {
        cout << opt[K][N][0];
    }
    cout << opt[K][N][1] << endl;
    return 0;
}

