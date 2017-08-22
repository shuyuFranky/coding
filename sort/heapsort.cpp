#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 100

int arr[maxn + 5];
int N;

void myprint() {
    for (int i = 1; i<= N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sift(int k, int n) {
    int i = k, j = 2*k;                 // i 为当前根节点， j 为左子节点
    while (j<=n) {
        if (j<n && arr[j] < arr[j+1])   // 将j指向较大的子节点，注意检查 j+1 是否越界
            j++;
        if (arr[i] > arr[j])            // 已经是最大值堆了，不再调整，
            break;                      // 自底向上的过程保证了这里break正确
        else {
            swap(arr[i], arr[j]);       // 交换
            i = j;                      // 自顶向下调整
            j = 2*i;
        }
    }
}

/*
*   堆排序函数
*/
void heapsort() {                       
    for (int i = N/2; i>=1; i--)        // 从最后一个非叶子节点开始
        sift(i, N);                     // 自顶向下调整子树为最大值堆
                                        // for 循环自底向上调节整个树为最大值堆
    for (int i = 1; i<N; i++) {         // N-1 次取出最大值
        swap(arr[1], arr[N-i+1]);       // 每次交换后 arr[N-i+1, N]为升序
        sift(1, N-i);                   // 重新调整整棵树
    }
}

int main() {
    scanf("%d", &N);
    arr[0] = 0;
    for (int i = 1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }
    heapsort();
    myprint();
    return 0;
}