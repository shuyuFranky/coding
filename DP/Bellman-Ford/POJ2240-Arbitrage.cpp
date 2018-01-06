/**
* POJ 2240
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

#define maxn 35

struct Edge{
	int u;
	int v;
	double r;
} e[maxn*2];
map<string, int> mp;
int N, M;
double dis[maxn];

void Bellman_Ford() {
	for (int i = 1; i <= N; i++) {
		dis[i] = 0;
	}
	dis[1] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dis[e[j].v] < dis[e[j].u]*e[j].r) {
				dis[e[j].v] = dis[e[j].u]*e[j].r;
			}
		}
	}
	// check Arbitrage
	bool flag = false;
	for (int i = 0; i < M; i++) {
		if (dis[e[i].v] < dis[e[i].u]*e[i].r) {
			cout << "Yes" << endl;
			flag = true;
			break;
		}
	}
	if (!flag) cout << "No" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int t = 0;
	string name;
	string a, b;
	double r;
	while (cin >> N) {
		if (N == 0) break;
		t++;
		cout << "Case " << t << ": ";
		for (int i = 1; i <= N; i++) {
			cin >> name;
			mp[name] = i;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> r >> b;
			e[i].u = mp[a];
			e[i].v = mp[b];
			e[i].r = r;
		}
		Bellman_Ford();
        mp.clear();
	}
	return 0;
}
