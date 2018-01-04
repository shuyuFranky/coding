/**
 *  Milking Time
 *  带权区间调度
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define maxn (1000 + 5)

struct space{
    int start;
    int end;
    int w;
} sp[maxn];

int N, M, R;
int opt[maxn];
int p[maxn];

bool mycmp(space a, space b) {
    return a.end < b.end;
}

void init_p() {
    p[0] = 0;
    p[1] = 0;
    for (int j = 2; j <= M; j++) {
        int i = j;
        while (i > 0 && sp[i-1].end > sp[j-1].start) {
            i--;
        }
        p[j] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++) {
        cin >> sp[i].start >> sp[i].end >> sp[i].w;
        sp[i].end += R;
    }
    sort(sp, sp + M, mycmp);
    init_p();
    opt[0] = 0;
    for (int j = 1; j <= M; j++) {
        opt[j] = max(sp[j-1].w + opt[p[j]], opt[j-1]);
    }
    cout << opt[M] << endl;
    return 0;
}
