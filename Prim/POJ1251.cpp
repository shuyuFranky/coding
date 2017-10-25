#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX=30;
const int INF=200;
int graph[MAX][MAX] ;
bool visited[MAX];
int prim(int n)
{
    int lowCost[MAX] ;
    for(int i = 1 ; i <= n ; ++i)
    {
        lowCost[i] = graph[1][i] ;
    }
    memset(visited,false,sizeof(visited)) ;
    visited[1] = true ;
    lowCost[0] = INF ;
    int sum = 0 ;
    for(int i = 1 ; i < n ; ++i)
    {
        int index = 0 ;
        for(int j = 1 ; j <= n ; ++j)
        {
            if(!visited[j] && lowCost[index]>lowCost[j])
            {
                index = j ;
            }
        }
        if(index == 0)
            break ;
        sum += lowCost[index] ;
        visited[index] = true ;
        for(int j = 1 ; j <= n ; ++j)
        {
            if(!visited[j] && lowCost[j]>graph[index][j])
            {
                lowCost[j] = graph[index][j] ;
            }
        }
    }
    return sum ;
}
void init()
{
    for(int i = 0 ; i < MAX ; ++i)
        for(int j = 0 ; j < MAX ; ++j)
            graph[i][j] = INF ;
}
int main()
{
    int k, dis, n;
    char x, y;
    while(cin >> n && n){
        init();
        for(int i=1;i<n;i++){
            cin >> x >> k;
            while(k--){
                cin >> y >> dis;
                int a=x-'A'+1;
                int b=y-'A'+1;
                if(graph[a][b]>dis)
                    graph[a][b]=graph[b][a]=dis;
            }
        }
        cout << prim(n) << endl;
    }
    return 0;
}
