#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 1000

int arr[maxn + 5];
int tmp[maxn + 5];
int len;
int ans;

void mergearr(int l, int r) {
    int i = l;
    int m = (l+r) / 2;
    int j =  m + 1;
    int k = 0;
    while (i<=m && j<=r) {
        if(arr[i] <= arr[j]) {                      // 等于不算逆序数
            tmp[k++] = arr[i++];
        } else {                                    // 当arr[i] > arr[j]时
            tmp[k++] = arr[j++];                    // 将arr[j]放到arr[i]之前
            ans += m-i+1;                           // 在前半部分中，比arr[i]大的数均比arr[j]大
        }                                           // 即，计算逆序数时应加上这部分
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
    int n;
    int t = 0;
    scanf("%d", &n);
    while (t<n) {
        t++;
        printf("Scenario #%d:\n", t);
        ans = 0;
        scanf("%d", &len);
        for (int i = 0; i<len; i++) {
            scanf("%d", &arr[i]);
        }
        mergesort(0, len-1);
        printf("%d\n", ans);
        printf("\n");
    }
    return 0;
}
