/*
*	MLE on POJ, AC on OJ
* 	Memory optimizing see LCS/POJ1159.cpp
*/

#include <iostream>
#include <string>

using namespace std;

#define maxn (5000 + 5)

int dp[maxn][maxn];
int N;
string ori;
string rori;

void LCS() {
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= N; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(ori[i-1] == rori[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
}

int main() {
    cin >> N;
    cin >> ori;
    rori.assign(ori.rbegin(), ori.rend());
    LCS();
    cout << (N - dp[N][N]) << endl;
    return 0;
}
