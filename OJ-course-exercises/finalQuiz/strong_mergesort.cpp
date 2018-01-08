/**
 * WA : Don't no why!!!!!!!!
 */
#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 200010

int arr[maxn + 5];
int tmp[maxn + 5];
int ans;
int n;

void mergearr(int l, int r) {
    int i = l;
    int m = (l+r) / 2;
    int j =  m + 1;
    int k = 0;
    int index = i;
    while (i<=m && j<=r) {
        if(arr[i] <= arr[j]) {         // 等于不算逆序数
            tmp[k++] = arr[i++];
            //index ++;
        } else {                      // 当arr[i] > arr[j]时
            while (index <= m && arr[index] <= 2*arr[j]) index ++;
            tmp[k++] = arr[j++];       // 将arr[j]放到arr[i]之前
            if (index <= m) {
                ans += m-index+1;          // 在前半部分中，比arr[i]大的数均比arr[j]大
            }   
        }                           // 即，计算逆序数时应加上这部分
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
    while (scanf("%d", &n)) {
        if (n == 0) break;
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        mergesort(0, n-1);
        printf("%d\n", ans);
    }
    return 0;
}


/**
input :
5
0 7 2 12 40
8
0 8 2 27 8 10 24 42
9
0 5 2 24 20 10 48 42 8
8
0 8 10 24 12 5 12 7
25
0 5 12 9 28 10 42 70 48 45 60 110 12 13 42 60 160 170 36 171 60 105 44 23 72
6
0 9 10 30 36 20
7
0 7 6 15 32 25 30
16
0 2 6 3 20 10 42 21 80 63 60 66 72 117 56 60
27
0 5 4 27 24 25 54 70 56 63 100 33 60 117 14 135 64 136 72 190 60 42 198 46 96 175 1561
0

output:
1
3
6
3
40
0
0
1
26
 */