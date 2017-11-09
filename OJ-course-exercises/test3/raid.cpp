/*
* 最近点对
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define maxn 2000

struct point{
    int type;
    int x;
    int y;
} p[maxn + 5], p1[maxn + 5];

int T, N;

bool compare_X(point a, point b) {
    return a.x < b.x;
}

bool compare_Y(point a, point b) {
    return a.y < b.y;
}

double min(double a, double b) {
    return a < b ? a : b;
}

double getDis(point a, point b) {
    if (a.type != b.type)
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    return 1e30;
}

double part(int l, int r) {
    double ans;
    int i, j, t;
    if (l >= r) return 1e30;
    if (l + 1 == r) {
        return getDis(p[l], p[r]);
    }
    int m = (l + r) / 2;
    ans = min(part(l, m), part(m + 1, r));
    for (i = l, t= 0; i <= r; i++) {
        if (fabs(p[i].x - p[m].x) <= ans) {
            p1[t++] = p[i];
        }
    }
    sort(p1, p1 + t, compare_Y);
    for (i = 0; i < t; i++) {
        for (j = i + 1; j < 12 && j < t && p1[j].y - p1[i].y <= ans; j++) {
            ans = min(ans, getDis(p1[i], p1[j]));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    int i, j;
    double d;
    while (T--) {
        cin >> N;
        for (i = 0; i < N; i++) {
            cin >> p[i].x >> p[i].y;
            p[i].type = 0;
        }
        for (j = 0, i = N; j < N; j++, i++) {
            cin >> p[i].x >> p[i].y;
            p[i].type = 1;
        }
        sort(p, p + 2 * N, compare_X);
        d = part(0, 2*N-1);
        cout << fixed << setprecision(3) << d << endl;
    }
    return 0;
}
