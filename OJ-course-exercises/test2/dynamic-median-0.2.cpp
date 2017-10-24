//============================================================================
// Name        : dynamic-median-0.2.cpp
// Author      : yushu
// 22700kB	1632ms	3785 B	G++	
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

#define maxn 5000

struct maxHeap{
    int data[maxn + 5];
    int size;
    maxHeap () {
        memset(data, 0, sizeof(data));
        size = 0;
    }
    int getSize() {
        return size;
    }
    void push(int num) {
        data[size++] = num;
        int i = size - 1;
        int p;
        while (i > 0) {
            p = (i - 1) / 2;
            if (data[p] < data[i]) {
                int tmp = data[p];
                data[p] = data[i];
                data[i] = tmp;
            }
            i = p;
        }
    }
    void pop() {
        size--;
        data[0] = data[size];
        data[size] = 0;
        int i = 0;
        while (i*2 + 1 < size) {
            int lc, rc, child;
            lc = i*2 + 1;
            rc = i*2 + 2;
            if (rc < size) {
                child = data[lc] > data[rc] ? lc : rc;
            } else {
                child = lc;
            }
            if (data[i] < data[child]) {
                int tmp = data[i];
                data[i] = data[child];
                data[child] = tmp;
            }
            i = child;
        }
    }
    int front() {
        return data[0];
    }
};

struct minHeap{
    int data[maxn + 5];
    int size;
    minHeap () {
        memset(data, 0, sizeof(data));
        size = 0;
    }
    int getSize() {
        return size;
    }
    void push(int num) {
        data[size++] = num;
        int i = size - 1;
        int p;
        while (i > 0) {
            p = (i - 1) / 2;
            if (data[p] > data[i]) {
                int tmp = data[p];
                data[p] = data[i];
                data[i] = tmp;
            }
            i = p;
        }
    }
    void pop() {
        size--;
        data[0] = data[size];
        data[size] = 0;
        int i = 0;
        while (i*2 + 1 < size) {
            int lc, rc, child;
            lc = i*2 + 1;
            rc = i*2 + 2;
            if (rc < size) {
                child = data[lc] < data[rc] ? lc : rc;
            } else {
                child = lc;
            }
            if (data[i] > data[child]) {
                int tmp = data[i];
                data[i] = data[child];
                data[child] = tmp;
            }
            i = child;
        }
    }
    int front() {
        return data[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    int T, N;
    cin >> T;
    char op;
    int num;
    while (T--) {
        maxHeap maxh;
        minHeap minh;
        cin >> N;
        while (N--) {
            cin >> op;
            if (op == 'I') {
                cin >> num;
                if (num <= maxh.front()) {
                    maxh.push(num);
                } else {
                    minh.push(num);
                }
                if (maxh.getSize() - minh.getSize() == 2) {
                    int tmp = maxh.front();
                    maxh.pop();
                    minh.push(tmp);
                } else if (maxh.getSize() < minh.getSize()) {
                    int tmp = minh.front();
                    minh.pop();
                    maxh.push(tmp);
                }
            } else if (op == 'D') {
                maxh.pop();
                if (maxh.getSize() < minh.getSize()) {
                    int tmp = minh.front();
                    minh.pop();
                    maxh.push(tmp);
                }
            } else {
                cout << maxh.front() << endl;
            }
        }
    }
    return 0;
}