#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 400000

int plen;
int nt[maxn + 5];
char par[maxn + 5];

void preNext() {
    int i = -1, j = 0;
    nt[0] = -1;
    while (j < plen) {
        if (i == -1 || par[i] == par[j]) {
            i++, j++;
            nt[j] = i;
        } else {
            i = nt[i];
        }
    }
}

void solve() {
    int len = nt[plen];
    // 这里写法不好，使用了c++新特性，老版本编译器会报错
    int res[len];
    int i = nt[plen];
    int ind = 0;
    while (i > 0) {
        res[ind++] = i;
        i = nt[i];
    }
    for (i = ind - 1; i>=0; i--) {
        printf("%d ", res[i]);
    }
    printf("%d\n", plen);
}

int main() {
    while (~scanf("%s", par)) {
        plen = strlen(par);
        preNext();
        solve();
    }
    return 0;
}