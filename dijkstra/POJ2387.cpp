/**
*  Til the Cows Come Home
*/

#include <iostream>

using namespace std;

#define MAXN 1000
#define INF 999999              // 要足够大

int T, N;
int e[MAXN + 5][MAXN + 5];
int book[MAXN + 5];
int dis[MAXN + 5];

int main() {
    int s1,s2,l;
    int min = INF;
    int u;
    cin>>T>>N;                          // 注意这里输入顺序
    // 初始化边
    for (int i = 1; i<= N; i++) {
        for (int j = 1; j<=N; j++) {
            if(i == j) e[i][j] = 0;
            else e[i][j] = INF;
        }
    }
    // 读入数据
    for (int i = 1; i<= T; i++) {
        cin>>s1>>s2>>l;
        if (e[s1][s2] > l) {        // 有重边
        		e[s1][s2] = l;      // 每条边为双向边
        		e[s2][s1] = l;
        }
    }
    // 初始化标记数组
    for (int i = 1; i<=N; i++) {
        book[i] = 0;
    }
    book[1] = 1;
    // 初始化每个点到源点的距离
    for (int i = 1; i<=N; i++) {
        dis[i] = e[1][i];
    }
    // dijkstra 核心算法
    for (int i = 1; i<=N-1; i++) {
        min = INF;                      // 这里用到INF，所以之前定义INF要足够大
        for (int j = 1; j<=N; j++) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for (int v = 1; v<=N; v++) {
            if (!book[v] && e[u][v] < INF) {            // 对以点u为起点的边，做松弛操作
                if (dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
    }
    cout << dis[N] << endl;
    return 0;
}
