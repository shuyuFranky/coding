#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define maxn (1000 + 5)

struct Iland{
	int x, y;
	double sx;
}iland[maxn];
int N, D;
int ans;

double preprocess(int i) {
	double x = iland[i].x;
	double y = iland[i].y;
	return ((double)x + sqrt((double)(abs(D*D - y*y))));
}

bool mycmp(Iland a, Iland b) {
	return (a.sx < b.sx);
}

bool inscope(int i, double pos) {
	double dis = sqrt((double)((iland[i].x - pos)*(iland[i].x - pos) + iland[i].y*iland[i].y));
	return (dis <= D);
}

void solve() {
	double pos = iland[0].sx;
	ans = 1;
	for (int i = 0; i < N; i++) {
		if (!inscope(i, pos)) {
			pos = iland[i].sx; 
			ans ++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int cnt = 0;
	bool flag = false;
	while (cin >> N >> D) {
		if (!(N||D)) break;
		flag = false;
		ans = 0;
		cnt ++;
		cout << "Case " << cnt << ": ";
		for (int i = 0; i < N; i++) {
			cin >> iland[i].x >> iland[i].y;
			if (abs(iland[i].y) > D || D <= 0) {
				flag = true;
			}
			iland[i].sx = preprocess(i);
		}
		if (flag) {
			cout << "-1" << endl;
			continue;
		}
		sort(iland, iland + N, mycmp);
		solve();
		cout << ans << endl;
	}
	return 0;
}
