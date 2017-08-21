#include <iostream>

using namespace std;

#define maxn 50000

struct cow{
    int id;
    int fv;
    int sv;
}p[maxn + 5];

int N, K;

void qSort(int l, int r) {
    if (l < r) {
        cow x = p[l];
        int i = l, j = r;
        while (i < j) {
            while (i<j && x.fv >= p[j].fv) {
                j--;
            }
            if (i<j) {
                p[i++] = p[j];
            }
            while (i<j && x.fv < p[i].fv) {
                i++;
            }
            if (i<j) {
                p[j--] = p[i];
            }
        }
        p[i] = x;
        qSort(l, i-1);
        qSort(i+1, r);
    }
}

void solve() {
    int mx = p[0].sv;
    int res = p[0].id;
    for (int i = 1; i < K; i++) {
        if (mx < p[i].sv) {
            mx = p[i].sv;
            res = p[i].id;
        }
    }
    printf("%d\n", res);
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &p[i].fv, &p[i].sv);
        p[i].id = i+1;
    }
    qSort(0, N-1);
    solve();
    return 0;
}