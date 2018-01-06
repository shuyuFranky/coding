/**
 * MA:To Europe! To Europe!
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

#define maxn 1005
#define inf 1e9

double dp[maxn];
struct Car {
	int w;
	int s;
} car[maxn];
int N, B, L;

double min(double a, double b) {
	return a < b ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> B >> L >> N) {
		if (B == 0) break;
		L *= 60;
		for (int i = 1; i <= N; i++) {
			cin >> car[i].w >> car[i].s;
		}
		dp[0] = 0;
		for (int i = 1; i <= N; i++) {
			double t = dp[i - 1] + (double)L / (double)car[i].s; // 第 i 辆车自成一组
			int interval_sum = car[i].w;  // 该组总重量
			int min_speed = car[i].s;  // 最慢车的车速
            int k;  // 枚举 [k, i] 为一组
			for (k = i - 1; k > 0 && (interval_sum += car[k].w) <= B; k--) {
				if (car[k].s < min_speed) {
					min_speed = car[k].s;
				}
				t = min(t, dp[k - 1] + (double)L / (double)min_speed);
			}
            dp[i] = t;
		}
		cout << fixed << setprecision(1) << dp[N] << endl;
	}
	return 0;
}
