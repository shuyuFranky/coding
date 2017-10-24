//============================================================================
// Name        : butterfly.cpp
// Author      : yushu
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define maxn 1000


int e[maxn + 5][maxn + 5];
int n, m;
bool book[maxn + 5];
int state[maxn + 5];
bool suc;
queue <int > q;

bool bfs(int v) {
	if (book[v] == 1) return true;
	book[v] = 1;
	if (state[v] == 0) state[v] = 1;
	for (int i = 0; i < n; i++) {
		if (e[v][i] == 1) {
			if (state[i] == 0) {
				state[i] = 3 - state[v];
			} else {
				if (state[i] == state[v]) {
					return false;
				}
			}
			if (book[i] == 0) q.push(i);

		} else if (e[v][i] == 2) {
			if (state[i] == 0) {
				state[i] = state[v];
			} else {
				if (state[i] != state[v]) {
					return false;
				}
			}
			if (book[i] == 0) q.push(i);
		}
	}
	return true;
}

int main() {
	int a, b, c;
	while(~scanf("%d %d", &n, &m)) {
		suc = true;
		memset(e, 0, sizeof(e));
		memset(book, 0, sizeof(book));
		memset(state, 0, sizeof(state));
		while (!q.empty()) q.pop();
		for (int i = 0; i<m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			e[a][b] = 2 - c;
			e[b][a] = 2 - c;
		}
		for (int i = 0; i<n; i++){
			q.push(i);
			while (!q.empty()) {
				if (!bfs(q.front())) {
					suc = false;
					break;
				}
				q.pop();
			}
			if (!suc) break;
		}
		if (suc) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}