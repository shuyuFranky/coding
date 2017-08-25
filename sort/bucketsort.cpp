#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 1000

int n;
int bucket[maxn + 5] = {0};

void myprint() {
    for (int i = 0; i < maxn+5; i++) {
        while (bucket[i] > 0) {
            printf("%d ", i);
            bucket[i]--;
            i--;
        }
    }
    printf("\n");
}

int main() {
    int tmp;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        scanf("%d", &tmp);
        bucket[tmp]++;
    }
    myprint();
    return 0;
}
