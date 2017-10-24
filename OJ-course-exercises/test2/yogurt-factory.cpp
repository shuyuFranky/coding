//============================================================================
// Name        : yogurt-factory.cpp
// Author      : yushu
//============================================================================

#include <iostream>

using namespace std;

int mymin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    long long res = 0;
    int N, S;
    cin >> N >> S;
    int c, y;
    int minP = 5005;
    while (N--) {
        cin >> c >> y;
        minP = mymin(minP + S, c);
        res += minP*y;
    }
    cout << res <<endl;
    return 0;
}