#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define maxn 1000000

int plen;
char par[maxn + 5];
int nt[maxn + 5];

void preNext() {
    int i = -1, j = 0;
    nt[0] = -1;
    while (j < plen) {
        if (i == -1 || par[i] ==  par[j]) {
            i++, j++;
            nt[j] = i;
        } else {
            i = nt[i];
        }
    }
}

void solve() {                          
    int len = plen - nt[plen];         // 如果有子串a，则a的长度为plen - nt[plen]
    int ans = 0;
    if (plen % len == 0){               // 且plen整除len
    		ans = plen / len;           // 计算重复次数
    		printf("%d\n", ans);           
    } else
        printf("1\n");                  // 至少是1
}

int main() {
    while (~scanf("%s", par)) {
        if (par[0] == '.') break;
        plen = strlen(par);
        preNext();
        solve();
    }
    return 0;
}
