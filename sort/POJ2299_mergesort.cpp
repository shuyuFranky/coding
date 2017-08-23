#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 500000

int n;
long long ans;                  // 这里一定要注意，使用long long
int arr[maxn + 5];
int tmp[maxn + 5];

void mergearr(int l, int r) {
    int i = l;
    int m = (l+r) / 2;
    int j = m + 1;
    int k = 0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
            ans += m - i + 1;
        }
    }
    while (i<=m) {
        tmp[k++] = arr[i++];
    }
    while (j<=r) {
        tmp[k++] = arr[j++];
    }
    for (i = l; i<=r; i++) {
        arr[i] = tmp[i-l];
    }
}

void mergesort(int l, int r) {
    if (l < r) {
        int m = (l+r) / 2;
        mergesort(l, m);
        mergesort(m+1, r);
        mergearr(l, r);
    }
}

int main() {
    while(scanf("%d", &n) && n != 0) {
        ans = 0;
        for (int i = 0; i<n; i++) {
            scanf("%d", &arr[i]);
        }
        mergesort(0, n-1);
        printf("%lld\n", ans);
    }
    return 0;
}