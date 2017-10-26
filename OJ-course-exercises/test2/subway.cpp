//============================================================================
// Name        : subway.cpp
// Author      : yushu
//============================================================================
#include <cstdio>  
#include <cmath>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
int const MAX = 405;  
int const INF = 100000000.0;  
  
struct Node  
{  
    double u, v;  
}nd[MAX];  
  
double dis[MAX], e[MAX][MAX];  
bool vis[MAX];  
int cnt;  
  
double get_dis(double x1, double y1, double x2, double y2)  
{  
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));  
}  
  
void Dijkstra(int v0)  
{  
    for(int i = 0; i < cnt; i++)  
        dis[i] = e[v0][i];  
    dis[v0] = 0;  
    vis[v0] = true;  
    for(int i = 0; i < cnt - 1; i++)  
    {  
        double mi = INF;  
        int u = v0;  
        for(int j = 0; j < cnt; j++)  
        {  
            if(!vis[j] && mi > dis[j])  
            {  
                u = j;  
                mi = dis[j];  
            }  
        }  
        vis[u] = true;  
        for(int k = 0; k < cnt; k++)  
            if(!vis[k] && dis[k] > dis[u] + e[u][k])  
                dis[k] = dis[u] + e[u][k];  
    }  
}  
  
int main()  
{  
    memset(vis, false, sizeof(vis));  
    memset(e, 0, sizeof(e));  
    scanf("%lf %lf %lf %lf", &nd[0].u, &nd[0].v, &nd[1].u, &nd[1].v);  
    double u, v;  
    int tmp = 2;  
    cnt = 2;  
    while(scanf("%lf %lf", &u, &v) != EOF)  
    {  
        if(u == -1.0 && v == -1.0)  
        {  
            for(int i = tmp; i < cnt - 1; i++)  
            {  
                double get = get_dis(nd[i].u, nd[i].v, nd[i + 1].u, nd[i + 1].v) / 40000.0;  
                e[i][i + 1] = e[i + 1][i] = get;  
            }  
            tmp = cnt;  
            continue;  
        }  
        nd[cnt].u = u;  
        nd[cnt++].v = v;  
    }  
    for(int i = 0; i < cnt; i++)  
        for(int j = i + 1; j < cnt; j++)  
            if(e[i][j] == 0)  
                e[i][j] = e[j][i] = get_dis(nd[i].u, nd[i].v, nd[j].u, nd[j].v) / 10000.0;  
    Dijkstra(0);  
    printf("%d\n", (int)(dis[1] * 60.0 + 0.5));  
}  
