/**
 * Prim
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

#define maxn 105
#define inf 1e9

struct Node {
    double x;
    double y;
} node[maxn];
int N;
double e[maxn][maxn];
int book[maxn];
double dis[maxn]; 

double getDis(int a, int b) {
    double x = node[a].x - node[b].x;
    double y = node[a].y - node[b].y;
    return sqrt((double)(x*x + y*y));
}

void Prim() {
    double ans = 0;
    int v;
    book[1] = 1;
    for (int i = 1; i <= N; i++) dis[i] = e[1][i];
    for (int i = 1; i < N; i++) {
        double min = inf;
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] < min) {
                min = dis[j];
                v = j;
            }
        }
        book[v] = 1;
        ans += dis[v];
        for (int j = 1; j <= N; j++) {
            if (!book[j] && dis[j] > e[v][j]) {
                dis[j] = e[v][j];
            }
        }
    }
    cout << setprecision(2) << ans << endl;
}

int main() {
    cin >> N;
    double x, y;
    for (int i = 1; i <= N; i++) {
        cin >> node[i].x >> node[i].y;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (i == j) e[i][j] = 0;
            else {
                e[i][j] = e[j][i] = getDis(i, j);
            }
        }
    }
    Prim();
    return 0;
}