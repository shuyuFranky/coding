#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 1000

int arr[maxn + 5];
int tmp[maxn + 5];
int n;

void myprint() {
    for (int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergearr(int l, int r) {
    int i = l;
    int mid = (l+r) / 2;
    int j = mid + 1;
    int k = 0;
    while (i<=mid && j<=r) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i<=mid) {
        tmp[k++] = arr[i++];
    }    
    while (j<=r) {
        tmp[k++] = arr[j++];
    }
    for (i = l; i<=r; i++) {
        arr[i] = tmp[i-l];
    }
}

void mergesort(int s, int e) {
    if (s < e) {
        int m = (s+e) / 2;
        mergesort(s, m);
        mergesort(m+1, e);
        mergearr(s, e);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(0, n-1);
    myprint();
    return 0;
}