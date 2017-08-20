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

/*
Output:
Test case #1
2 2
3 3

Test case #2
2 2
6 2
9 3
12 4
*/

void solve() {                   // 解题思路同POJ2406
    int ans = 0;
    int len;
    for (int i = 2; i<=plen; i++) {
        len = i - nt[i];
        if (i % len == 0 && i/len > 1) {
            ans = i / len;
            printf("%d %d\n", i, ans);
        }
    }
}

int main() {
	int cnt = 0;
    while (1) {
    		scanf("%d", &plen);
    		scanf("%s", par);
        if (plen == 0) break;
        preNext();
        cnt++;
        printf("Test case #%d\n", cnt);
        solve();
        printf("\n");
    }
    return 0;
}
