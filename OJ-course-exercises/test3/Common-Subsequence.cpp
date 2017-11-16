/*
* Common Subsequence
*/

#include <iostream>
#include <cstring>

using namespace std;

#define maxn 20000

string x, y;
int n, m;
int c[maxn][maxn];

void LCS() {
    for (int i = 0; i <= n; i++)
        c[i][0] = 0;
    for (int j = 0; j <= m; j++)
        c[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else {
                if (c[i-1][j] > c[i][j-1]) {
                    c[i][j] = c[i-1][j];
                } else {
                    c[i][j] = c[i][j-1];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> x >> y) {
        n = x.length();
        m = y.length();
        LCS();
        cout << c[n][m] << endl;
    }
    return 0;
}
