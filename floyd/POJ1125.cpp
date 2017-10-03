/**
* Stockbroker Grapevin
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100
#define inf 99999999

int e[maxn + 5][maxn + 5];
int N;
int book[maxn + 5];

int main() {
    int n;
    int p, t;
    bool isdisjoint = false;
    int min = inf;
    int max = -1;
    while (scanf("%d", &N)) {
        if (N == 0) break;
        isdisjoint = false;
        memset(book, 0, sizeof(book));
        book[1] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) e[i][j] = 0;
                else e[i][j] = inf;
            }
        }
        for (int i = 1; i <= N; i++) {
            scanf("%d", &n);
            while(n--) {
                scanf("%d %d", &p, &t);
                e[i][p] = t;
                book[p] = 1;
            }
        }
        // floyd
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (e[i][k] < inf && e[k][j] < inf && e[i][j] > e[i][k] + e[k][j]) {
                        e[i][j] = e[i][k] + e[k][j];
                    }
                }
            }
        }
        min = inf;
        for (int i = 1; i <= N; i++) {
            max = -1;
            for (int j = 1; j <= N; j++) {
                if (max < e[i][j]) {
                    max = e[i][j];
                }
            }
            if (min > max) {
                min = max;
                p = i;
            }
        }
        // check disjoint
        for (int i = 1; i <= N; i++) {
            if (book[i] == 0 && i != p) {
                printf("disjoint\n");
                isdisjoint = true;
                break;
            }
        }
        if (!isdisjoint) printf("%d %d\n", p, min);
    }
    return 0;
}
