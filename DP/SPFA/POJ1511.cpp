/**
 * Invitation Cards
 * SPFA
 */

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

#define maxn 1000010
#define inf 1e9

int u[maxn];
int v[maxn];
int w[maxn];
int first[maxn];
int nt[maxn];
queue<int > q;
int inq[maxn];
int dis[maxn];
int T, N, M;

long long spfa() {
	memset(inq, 0, sizeof(inq));
    for (int i = 1; i <= N; i++) dis[i] = inf;
    dis[1] = 0;
    q.push(1);
    inq[1] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        inq[t] = 0;
        int k = first[t];
        while (k != -1) {
            if (dis[v[k]] > dis[u[k]] + w[k]) {
                dis[v[k]] = dis[u[k]] + w[k];
                if (!inq[v[k]]) {
                    q.push(v[k]);
                    inq[v[k]] = 1;
                }
            }
            k = nt[k];
        }
    }
    long long res = 0;
    for (int i = 1; i <= N; i++) {
        res += dis[i];
    }
    return res;
}

void reverse() {
    int tmp;
    memset(first, -1, sizeof(first));
    memset(nt, 0, sizeof(nt));
    for (int i = 1; i <= M; i++) {
        tmp = u[i];
        u[i] = v[i];
        v[i] = tmp;
        nt[i] = first[u[i]];
        first[u[i]] = i;
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin >> T;
    scanf("%d", &T);
	long long ans = 0;
    while (T --) {
        //cin >> N >> M;
        scanf("%d %d", &N, &M);
    		memset(first, -1, sizeof(first));
        memset(nt, 0, sizeof(nt));
        while (!q.empty()) q.pop();
        for (int i = 1; i <= M; i++) {
            //cin >> u[i] >> v[i] >> w[i];
            scanf("%d %d %d", &u[i], &v[i], &w[i]);
        		nt[i] = first[u[i]];
            first[u[i]] = i;
        }
        ans = spfa();
        reverse();
        ans += spfa();
        //cout << (ans_go + ans_back) << endl;
        printf("%lld\n", ans);
    }
    return 0;
}
