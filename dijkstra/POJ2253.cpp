/**
*   Frogger
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 200
#define inf 99999999

double e[maxn + 5][maxn + 5];
double dis[maxn + 5];
int book[maxn + 5];
int N;
struct Stone{
    int x;
    int y;
}stone[maxn + 5];

double getDis(int a, int b) {
    double x = stone[a].x - stone[b].x;
    double y = stone[a].y - stone[b].y;
    return sqrt(x*x + y*y);
}

double max(double a, double b) {
    return a > b ? a : b;
}

int main() {
    int xi, yi;
    int v;
    double len;
    double min = inf * 1.0;
    int t = 0;
    while(scanf("%d", &N)) {
        if (N == 0) break;
        memset(e, 0, sizeof(e));
        memset(dis, 0, sizeof(dis));
        memset(book, 0, sizeof(book));
        for (int i = 1; i <= N; i++) {
        		scanf("%d %d", &xi, &yi);
        		stone[i].x = xi;
            stone[i].y = yi;
        }
        for (int i = 1; i <= N; i++) {
        		for (int j = i; j <= N; j++) {
        			if (i == j) {
        				e[i][j] = 0;
        			} else {
        				e[i][j] = getDis(i ,j);
        				e[j][i] = e[i][j];
        			}
        		}
        }
        for (int i = 1; i <= N; i++) {
        		dis[i] = e[1][i];
        }
        book[1] = 1;
        for (int i = 1; i<=N; i++) { //cout << "LOOP:"  << i << endl;
            min = inf * 1.0;
            for (int j = 1; j<=N; j++) {
                if (book[j] == 0 && dis[j] < min) {
                		min = dis[j];
                		v = j;
                }
            }
            book[v] = 1;
            for (int j = 1; j<=N; j++) {
                len = max(dis[v], e[v][j]);
                if (dis[j] > len) {
                    dis[j] = len;
                }
                //cout << dis[j] << endl;
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++t, dis[2]);
    }

    return 0;
}
