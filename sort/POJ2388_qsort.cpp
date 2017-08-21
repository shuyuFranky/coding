/*
*   POJ 2388 
*   Qsort
*   Tab
*/

#include <iostream>

using namespace std;

#define maxn 10000

int arr[maxn + 5];

void qSort(int l, int r) {
    if (l < r) {
        int i = l, j = r;
        int x = arr[l];
        while (i < j) {
            while (i < j && arr[j] >= x) {
                j--;
            }
            if (i<j) {
                arr[i++] = arr[j];
            }
            while (i<j && arr[i] < x) {
                i++;
            }
            if (i<j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = x;
        qSort(l, i-1);
        qSort(i+1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qSort(0, n-1);
    printf("%d\n", arr[n/2]);
    return 0;
}