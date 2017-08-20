#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 10000

char par[maxn + 5];
char ori[maxn*100 + 5];

int nt[maxn + 5];

int plen;
int olen;

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

void preBetterNext() {
    int i = -1, j = 0;
    nt[0] = -1;
    while (j < plen) {
        if (i == -1 || par[i] == par[j]) {
            i++, j++;
            if (j == plen || par[i] != par[j]){
                nt[j] = i;
            } else {
                nt[j] = nt[i];
            }
        } else {
            i = nt[i];
        }
    }
}

void KMP() {
    int p = 0, o = 0;
    int cnt = 0;
    while (o < olen) {
        if (p == -1 || par[p] == ori[o]) {
            p++, o++;
            if (p == plen) {
                cnt++;
                p = nt[p];
            }
        } else {
            p = nt[p];
        }
    }
    if (p == plen)
        cnt++;
    printf("%d\n", cnt);
}

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
        scanf("%s", par);
        scanf("%s", ori);
        plen = strlen(par);
        olen = strlen(ori);
        preNext();
        KMP();
	}
    return 0;
}
