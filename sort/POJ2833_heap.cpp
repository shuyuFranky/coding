#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 1000
#define heapSize 15

int g, l;
long long n;
int arr[maxn + 5];
int g_minheap[heapSize];
int l_maxheap[heapSize];

void qsort(int l, int r) {
    if (l<r) {
        int i = l, j = r;
        int x = arr[i];
        while (i<j) {
            while(i<j && x > arr[j]){
                j--;
            }
            if (i<j) {
                arr[i++] = arr[j];
            }
            while (i<j && x <= arr[i]) {
                i++;
            }
            if (i<j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = x;
        qsort(l, i-1);
        qsort(i+1, r);
    }
}

void sift_min(int k, int n) {
    int i = k, j = 2*k;
    while (j <= n) {
        if (j < n && g_minheap[j] > g_minheap[j+1])
            j++;
        if (g_minheap[i] <= g_minheap[j])
            break;
        else {
            swap(g_minheap[i],g_minheap[j]);
            i = j;
            j = 2*i;
        }
    }
}

void sift_max(int k, int n) {
    int i = k, j = 2*k;
    while (j <= n) {
        if (j < n && l_maxheap[j] < l_maxheap[j+1])
            j++;
        if (l_maxheap[i] >= l_maxheap[j])
            break;
        else {
            swap(l_maxheap[i], l_maxheap[j]);
            i = j;
            j = 2*i;
        }
    }
}

int main() {
    long long ans = 0;                          // 注意：累加器一定要用 long long
    double res = 0;
    while (1) {
        ans = 0;
        scanf("%d %d %lld", &g, &l, &n);
        if (g < 1) break;
        int tmp = 0;                            // 中间过程用int处理
        for (int i = 0; i<g+l; i++) {
            scanf("%d", &arr[i]);
        }
        qsort(0, g+l-1);
        for (int i = 0; i<=g; i++){
            g_minheap[i+1] = arr[g-i-1];
        }
        for (int i = g+1; i<=g+l; i++){
            l_maxheap[i-g] = arr[i-1];
        }
        int c_g_min = g_minheap[1];
        int c_l_max = l_maxheap[1];
        for (int i = g+l; i<n; i++) {
            scanf("%d", &tmp);
            if (tmp > c_g_min) {
            		ans += c_g_min;
                g_minheap[1] = tmp;
                sift_min(1, g);
                c_g_min = g_minheap[1];
            } else if (tmp < c_l_max){
            		ans += c_l_max;
                l_maxheap[1] = tmp;
                sift_max(1, l);
                c_l_max = l_maxheap[1];
            } else {
                ans += tmp;
            }
        }
        res = double(ans) / (n - g - l);        // 最后结果转回 double
        printf("%.6lf\n", res);
    }
    return 0;
}
