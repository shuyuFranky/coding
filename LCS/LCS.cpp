#include <iostream>

using namespace std;

#define maxn 1000

char x[maxn + 5];
char y[maxn + 5];
int c[maxn + 5][maxn + 5];
int b[maxn + 5][maxn + 5];
int n, m;

void LCS() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            } else {
                if (c[i-1][j] > c[i][j-1]) {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 2;
                } else {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 3;
                }
            }
        }
    }
}

void printLCS(int i, int j) {
    if (i == 0 or j == 0) {
        return ;
    }
    if (b[i][j] == 1) {
        printLCS(i-1,j-1);
        cout << x[i];
    } else if (b[i][j] == 2) {
        printLCS(i-1, j);
    } else {
        printLCS(i, j-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int j = 1; j <= m; j++) {
        cin >> y[j];
    }
    LCS();
    cout << c[n][m] << endl;
    printLCS(n, m);
    return 0;
}
