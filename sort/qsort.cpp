#include <iostream>

using namespace std;

#define maxn 1000

int arr[maxn + 5];

void qSort(int l, int r) {
    if ( l < r ) {
        int x = arr[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && x <= arr[j]){
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }
            while (i<j && x > arr[i]) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = x;
        qsort(l, i-1);
        qsort(i+1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    qSort(0, n-1);
    for (int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
