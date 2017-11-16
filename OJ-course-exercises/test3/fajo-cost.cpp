#include <iostream>

using namespace std;

#define maxn 100000

int N, M;
int cost[maxn + 5];

bool check(int m) {
    long long tmp_cost = 0;
    int t = 0;
    for (int i = 0; i < N; i++) {
        while (tmp_cost + cost[i] <= m) {
            tmp_cost += cost[i];
            i++;
        }
        t++;
        if (t > M) return false;
        tmp_cost = 0;
        i--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        total_cost += cost[i];
    }
    long long l = 0;
    long long r = total_cost;
    long long res;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}