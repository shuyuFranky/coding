#include <iostream>

using namespace std;

#define MAXN 1000
#define INF 999999

int main() {
    int i,j,v,u;
    int s1,s2,l;
    int min = INF;
    int N,M;
    int e[MAXN + 5][MAXN + 5];
    int dis[MAXN + 5];
    int book[MAXN + 5];
    cin>>N>>M;
    // 初试化边
    for (i = 1; i<=N; i++)
        for (j = 1; j<=N; j++)
            if (i == j) e[i][j] = 0;
            else e[i][j] = INF;
    // 初始化book数组
    for (i = 1; i<=N; i++)
        book[i] = 0;
    book[1] = 1;
    // 读入边
    for (i = 1; i<=M; i++) {
        cin>>s1>>s2>>l;
        e[s1][s2] = l;
    }
    // 初始化dis数组
    for (i = 1; i<=N; i++) {
    		dis[i] = e[1][i];
    }
    // 核心算法
    for (i = 1; i<=N-1; i++) {
        // 在dis数组中找到距离1最近的点
        min = INF;
        for (j = 1; j<=N; j++) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for (v = 1; v<=N; v++) {
            if (e[u][v] < INF) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
    }
    for (i = 1; i<=N; i++) {
        cout << dis[i] << endl;
    }
    return 0;
}
