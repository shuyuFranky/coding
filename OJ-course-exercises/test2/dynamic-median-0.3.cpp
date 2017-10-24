//============================================================================
// Name        : dynamic-median-0.3.cpp
// Author      : yushu
// 22700kB	1574ms	1775 B	G++	
//============================================================================

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    int T, N;
    int num;
    char op;
    priority_queue<int> maxHp;
    priority_queue<int, vector<int>, greater<int> > minHp;
    cin >> T;
    while (T--) {
        while (!maxHp.empty()) maxHp.pop();
        while (!minHp.empty()) minHp.pop();
        cin >> N;
        while (N--) {
            cin >> op;
            if (op == 'I' ) {
                cin >> num;
                if (maxHp.empty()) {
                    maxHp.push(num);
                } else {
                    if (num <= maxHp.top()) {
                        maxHp.push(num);
                    } else {
                        minHp.push(num);
                    }
                    if (maxHp.size() - minHp.size() == 2) {
                        int tmp = maxHp.top();
                        maxHp.pop();
                        minHp.push(tmp);
                    } else if (maxHp.size() < minHp.size()) {
                        int tmp = minHp.top();
                        minHp.pop();
                        maxHp.push(tmp);
                    }
                }

            } else if (op == 'D') {
                maxHp.pop();
                if (maxHp.size() < minHp.size()) {
                    int tmp = minHp.top();
                    minHp.pop();
                    maxHp.push(tmp);
                }
            } else {
                cout << maxHp.top() << endl;
            }
        }
    }
    return 0;
}
