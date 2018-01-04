#include <iostream>

using namespace std;

#define maxn 30005

int fa[maxn];
int Rank[maxn];
int num[maxn];
int N, M;

void make_set(int x) {
    fa[x] = -1;
    Rank[x] = 0;
    num[x] = 1;
}

int find(int x) {
    if (fa[x] < 0) return x;
    else {
        return fa[x] = find(fa[x]);
    }
}

void merge(int x, int y) {
    int xfa = find(x);
    int yfa = find(y);
    if (xfa == yfa) return;
    if (Rank[xfa] > Rank[yfa]) {
        fa[yfa] = xfa;
        num[xfa] += num[yfa];
    } else if (Rank[xfa] == Rank[yfa]) {
        Rank[xfa] ++;
        fa[yfa] = xfa;
        num[xfa] += num[yfa];
    } else {
        fa[xfa] = yfa;
        num[yfa] += num[xfa];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    int x, y;
    while (cin >> N >> M) {
        if (N == 0) break;
        for(int i = 0; i < N; i++) make_set(i);
        while (M--) {
            cin >> T;
            T--;
            cin >> x;
            while (T--) {
                cin >> y;
                merge(x, y);
            }
        }
        cout << num[find(0)] << endl;
    }
    return 0;
}
