#include <iostream>

using namespace std;

#define maxn 110

struct edge{
	int u;
	int v;
	double ruv;
	double cuv;
} e[maxn*2];

int N;
int M;
int S;
double V;

double dis[maxn];
int all;

void Bellman_Ford() {
	//memset(dis, 0, sizeof(dis));
	dis[S] = V;
	bool flag = false;
	for (int i = 1; i < N; i++) {
		flag = false;
		for (int j = 0; j < all; j++) {
			if (dis[e[j].v] < (dis[e[j].u] - e[j].cuv)*e[j].ruv) {
				dis[e[j].v] = (dis[e[j].u] - e[j].cuv)*e[j].ruv;
				flag = true;
			}
		}
		if (!flag) break;
	}
	// check
	flag = false;
	for (int j = 0; j < all; j++) {
		if (dis[e[j].v] < (dis[e[j].u] - e[j].cuv)*e[j].ruv) {
			flag = true;
			break;
		}
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	cin >> N >> M >> S >> V;
	int a, b;
	double rab, cab, rba, cba;
	all = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> rab >> cab >> rba >> cba;
		e[all].u = a;
		e[all].v = b;
		e[all].ruv = rab;
		e[all++].cuv = cab;
		e[all].u = b;
		e[all].v = a;
		e[all].ruv = rba;
		e[all++].cuv = cba;
	}
	Bellman_Ford();
	return 0;
}