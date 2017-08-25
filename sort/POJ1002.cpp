#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 10000000

int bucket[maxn + 5] = {0};
char str[200];
int letter[25] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};

int mapstr() {
    int len = strlen(str);
    int res = 0;
    int tmp[10];
    for (int i = 0, j = 0; i<len && j<7; i++) {
        if (str[i] == '-')
            continue;
        if (str[i] >= '0' && str[i] <= '9') {
            tmp[j++] = str[i] - '0';
        } else if (str[i] >= 'A' && str[i] < 'Q') {
            tmp[j++] = letter[str[i] - 'A'];
        } else if (str[i] >= 'R' && str[i] < 'Z') {
            tmp[j++] = letter[str[i] - 'A'];
        } else {
            return -1;
        }
    }
    bool start_zero = true;
    for (int i = 0; i<7; i++) {
        if (start_zero && tmp[i] == 0)
            continue;
        else {
            start_zero = false;
            res = res*10 + tmp[i];
        }
    }
    return res;
}

void myprint() {
    bool isdup = false;
    int prefix;
    int surfix;
    for (int i = 0; i < maxn+5; i++) {
        if (bucket[i] > 1) {
            isdup = true;
            if (i < 10000) {
                printf("000-%.4d ", i);
            } else {
                prefix = i / 10000;
                surfix = i % 10000;
                printf("%.3d-%.4d ", prefix, surfix);
            }
            printf("%d\n", bucket[i]);
        } 
    }
    if (!isdup) {
        printf("No duplicates. \n");        // !!!! f*ck
    }
}

int main() {
    int n;
    int tmp;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        tmp = mapstr();
        if (tmp == -1) continue;
        bucket[tmp] += 1;
    }
    myprint();
    return 0;
}

