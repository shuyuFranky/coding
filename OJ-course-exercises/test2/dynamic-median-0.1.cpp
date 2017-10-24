//============================================================================
// Name        : dynamic-median-0.1.cpp
// Author      : yushu
// 22700kB	1562ms	3785 B	G++	
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

#define maxn 5000

int maxHeap[maxn + 5];
int minHeap[maxn + 5];

int smaxHeap, sminHeap;

void swap(int * hp, int x, int y) {
    int tmp = hp[x];
    hp[x] = hp[y];
    hp[y] = tmp;
}

void insertMaxHeap(int num) {
    maxHeap[smaxHeap++] = num;
    int i = smaxHeap - 1;
    int p;
    while (i > 0) {
        p = (i - 1) / 2;
        if (maxHeap[p] < maxHeap[i]) {
            swap(maxHeap, p, i);
        }
        i = p;
    }
}

void insertMinHeap(int num) {
    minHeap[sminHeap++] = num;
    int i = sminHeap - 1;
    int p;
    while (i > 0) {
        p = (i - 1) / 2;
        if (minHeap[p] > minHeap[i]) {
            swap(minHeap, p, i);
        }
        i = p;
    }
}

void deleteMaxHeap() {
    smaxHeap--;
    maxHeap[0] = maxHeap[smaxHeap];
    maxHeap[smaxHeap] = 0;
    int i = 0;
    int lchild, rchild, child;
    while (i*2 + 1 < smaxHeap) {
        lchild = i*2 + 1;
        rchild = i*2 + 2;
        if (rchild < smaxHeap) {
            child = maxHeap[lchild] > maxHeap[rchild] ? lchild : rchild;
        } else {
            child = lchild;
        }
        if (maxHeap[i] < maxHeap[child]) {
            swap(maxHeap, i, child);
        } else {
            break;
        }
        i = child;
    }
}

void deleteMinHeap() {
    sminHeap--;
    minHeap[0] = minHeap[sminHeap];
    minHeap[sminHeap] = 0;
    int i = 0;
    int lchild, rchild, child;
    while (i*2 + 1 < sminHeap) {
        lchild = i*2 + 1;
        rchild = i*2 + 2;
        if (rchild < sminHeap) {
            child = minHeap[lchild] < minHeap[rchild] ? lchild : rchild;
        } else {
            child = lchild;
        }
        if (minHeap[i] > minHeap[child]) {
            swap(minHeap, i, child);
        } else {
            break;
        }
        i = child;
    }
}

int main(){
    ios::sync_with_stdio(false);
    int T, N;
    char op;
    int num;
    cin >> T;
    while (T--) {
        memset(maxHeap, 0, sizeof(maxHeap));
        memset(minHeap, 0, sizeof(minHeap));
        smaxHeap = 0;
        sminHeap = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> op ;
            if (op == 'I') {
                cin >> num;
                if (num <= maxHeap[0]) {
                    insertMaxHeap(num);
                } else {
                    insertMinHeap(num);
                }
                if (smaxHeap - sminHeap == 2) {
                    insertMinHeap(maxHeap[0]);
                    deleteMaxHeap();
                } else if (smaxHeap < sminHeap) {
                    insertMaxHeap(minHeap[0]);
                    deleteMinHeap();
                }
            } else if (op == 'D') {
                deleteMaxHeap();
                if (smaxHeap < sminHeap) {
                    insertMaxHeap(minHeap[0]);
                    deleteMinHeap();
                }
            } else if (op == 'Q') {
                cout << maxHeap[0] << endl;
            } else {
                cout << "error input " << endl;
                return 0;
            }
        }
    }
    return 0;
}