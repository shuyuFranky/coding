//============================================================================
// Name        : discs.cpp
// Author      : yushu
//============================================================================
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define maxn 100000

queue<int> q[2];
vector<int> edge[maxn + 5];
int book[maxn + 5];
int n1, n2, N, D;
int indegree[2][maxn + 5];

void init() {
    int s, e;
    memset(indegree, 0, sizeof(indegree));
    N = n1 + n2;
    for (int i = 0; i <= N; i++) {
    		edge[i].clear();
    }
    for (int i = 1; i <= D; i++) {
        cin >> s >> e;
        edge[e].push_back(s);
        indegree[0][s]++;
        indegree[1][s]++;
    }
}

int min(int x, int y) {
    return x < y ? x : y;
}

int bfs(int start) {
	memset(book, 0, sizeof(book));
	for (int i = 0; i < 2; i++) {
	    while (!q[i].empty()) q[i].pop();
	}
	for (int i = 1; i <= n1; i++) {
	    if (indegree[start][i] == 0) q[0].push(i);
	}
	for (int i = n1 + 1; i <= N; i++) {
	    if (indegree[start][i] == 0) q[1].push(i);
	}
    int curCD = start;
    int ans = 1;
    int v, u;
    int tmpCD;
    while (!q[0].empty() || !q[1].empty()) {
        while (!q[curCD].empty()) {
            v = q[curCD].front();
            for (int i = 0; i < edge[v].size(); i++) {
                u = edge[v][i];
                indegree[start][u]--;
                tmpCD = u < (n1 + 1) ? 0 : 1;
                if (indegree[start][u] < 1 && book[u] == 0) q[tmpCD].push(u);
            }
            q[curCD].pop();
            book[v] = 1;
        }
        curCD = 1 - curCD;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int res = 0;
    while (cin >> n1 >> n2 >> D) {
        if (!n1) break;
        init();
        //cout << bfs(1) << " " << bfs(0) << endl;
        res = min(bfs(0), bfs(1));
        cout << res << endl;
    }
    return 0;
}
