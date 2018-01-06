/**
 * Invitation Cards
 * TLE
 * 熟悉一下用vector实现邻接表
 */

#include <iostream>
#include <vector>

using namespace std;

#define maxn 1000005
#define inf 1e9

struct edge{
    int v;
    int c;
};
vector <edge > e[maxn];
vector <edge> re[maxn];
int N, M, T;
int dis[maxn];
int book[maxn];

int get_sum() {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        res += dis[i];
    }
    return res;
}

void dijkstra() {
    int k;
    for (int i = 1; i <= N; i++) {
        dis[i] = inf;
    }
    for (int i = 0; i < e[1].size(); i++) {
        dis[e[1][i].v] = e[1][i].c;
    }
    dis[1] = 0;
    book[1] = 1;
    for (int i = 1; i < N; i++) {
        int min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[k = j];
            }
        }
        book[k] = 1;
        for (int j = 1; j <= N; j++) {
            //if (!book[j]) {
                for (int t = 0; t < e[j].size(); t++) {
                    if (dis[e[j][t].v] > dis[j] + e[j][t].c) {
                        dis[e[j][t].v] = dis[j] + e[j][t].c;
                    }
                }
            //}
        }
    }
}

void re_dijkstra() {
    int k;
    for (int i = 1; i <= N; i++) {
        dis[i] = inf;
    }
    for (int i = 0; i < re[1].size(); i++) {
        dis[re[1][i].v] = re[1][i].c;
    }
    dis[1] = 0;
    book[1] = 1;
    for (int i = 1; i < N; i++) {
        int min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[k = j];
            }
        }
        book[k] = 1;
        for (int j = 1; j <= N; j++) {
            //if (!book[j]) {
                for (int t = 0; t < re[j].size(); t++) {
                    if (dis[re[j][t].v] > dis[j] + re[j][t].c) {
                        dis[re[j][t].v] = dis[j] + re[j][t].c;
                    }
                }
            //}
        }
    }
}

void reverse_e() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            edge tmp_re;
            tmp_re.v = i;
            tmp_re.c = e[i][j].c;
            re[e[i][j].v].push_back(tmp_re);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    int u, v, w;
    int ans_go = 0;
    int ans_back = 0;
    while (T --) {
        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            cin >> u >> v >> w;
            edge tmp_e, tmp_re;
            tmp_e.v = v;
            tmp_e.c = w;
            tmp_re.v = u;
            tmp_re.c = w;
            e[u].push_back(tmp_e);
            re[v].push_back(tmp_re);
        }
        dijkstra();
        ans_go = get_sum();
        //reverse_e();
        re_dijkstra();
        ans_back = get_sum();
        cout << ans_go + ans_back << endl;
        for (int i = 1; i <= N; i++) {
        		e[i].clear();
        		re[i].clear();
        }
    }
    return 0;
}