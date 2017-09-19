/**
*  Til the Cows Come Home
*/

#include <iostream>

using namespace std;

#define MAXN 1000
#define INF 999999

int T, N;
int e[MAXN + 5][MAXN + 5];
int book[MAXN + 5];
int dis[MAXN + 5];

int main() {
    int s1,s2,l;
    int min = INF;
    int u;
    cin>>T>>N;
    for (int i = 1; i<= N; i++) {
        for (int j = 1; j<=N; j++) {
            if(i == j) e[i][j] = 0;
            else e[i][j] = INF;
        }
    }
    for (int i = 1; i<= T; i++) {
        cin>>s1>>s2>>l;
        if (e[s1][s2] > l) {
        		e[s1][s2] = l;
        		e[s2][s1] = l;
        }
    }
    for (int i = 1; i<=N; i++) {
        book[i] = 0;
    }
    book[1] = 1;
    for (int i = 1; i<=N; i++) {
        dis[i] = e[1][i];
    }
    for (int i = 1; i<=N-1; i++) {
        min = INF;
        for (int j = 1; j<=N; j++) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for (int i = 1; i<=N; i++) {
            if (e[u][i] < INF) {
                if (dis[u] + e[u][i] < dis[i]) {
                    dis[i] = dis[u] + e[u][i];
                }
            }
        }
    }
    cout << dis[N] << endl;
    return 0;
}
