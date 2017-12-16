/*
* Arbitrage
* Bellman-Ford
*/

#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

#define maxn 40
#define inf 1e30

struct Edge{
    int u, v;
    double w;
}edge[maxn*maxn];
map<string, int> mp;
int N, M;
double dist[maxn];

bool bellman_ford(int s) {
    bool hasNegCircle = false;
    for (int i = 1; i <= N; i++) {
        dist[i] = 0;
    }
    dist[s] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if(dist[edge[j].v] < dist[edge[j].u] * edge[j].w) {
                dist[edge[j].v] = dist[edge[j].u] * edge[j].w;
            }
        }
    }
    for (int j = 1; j <= M; j++) {
        if(dist[edge[j].v] < dist[edge[j].u] * edge[j].w) {
            hasNegCircle = true;
            break;
        }
    }
    return hasNegCircle;
}

int main() {
    ios::sync_with_stdio(false);
    string ss, s1, s2;
    double w;
    bool flag = false;
    int caseNum = 0;
    while (cin >> N) {
        if (N == 0) break;
        cout << "Case " << ++caseNum << ": ";
        mp.clear();
        flag = false;
        for (int i = 1; i <= N; i++) {
            cin >> ss;
            mp[ss] = i;
        }
        cin >> M;
        for (int i = 1; i <= M; i++) {
            cin >> s1 >> w >> s2;
            edge[i].u = mp[s1];
            edge[i].v = mp[s2];
            edge[i].w = w;
        }
        for (int i = 1; i <= N; i++) {
            flag = bellman_ford(i);
            if (flag) break;
        }
        if (!flag) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
