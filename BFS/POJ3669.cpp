/**
 * Meteor Shower
 * TLE
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    int x;
    int y;
    int t;
};

int M;
int tmap[310][310];

int xbias[4] = {0, 0, 1, -1};
int ybias[4] = {1, -1, 0, 0};

int main() {
    // init
	for(int i = 0; i < 310; i ++)
		fill(tmap[i], tmap[i] + 310, -1);
    int x, y, t;
    int x_, y_;
    queue<node > path;
    bool flag = false;

    // input
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &x, &y, &t);
        if (tmap[x][y] == -1 || t < tmap[x][y]) {
            tmap[x][y] = t;
        }
        for (int j = 0; j < 4; j++) {
            x_ = x + xbias[j];
            y_ = y + ybias[j];
            if (x_ >= 0 && x_ < 310 && y_ >= 0 && y_ < 310) {
                if (tmap[x_][y_] == -1 || t < tmap[x_][y_]) {
                    tmap[x_][y_] = t;
                }
            }
        }
    }

    if(tmap[0][0]==0) {
		printf("-1\n");
		return 0;
    }
    if(tmap[0][0]==-1){
		printf("0\n");
		return 0;
    }

    // BFS
    node tmp;
    tmp.x = 0;
    tmp.y = 0;
    tmp.t = 0;
    path.push(tmp);
    while (!path.empty()) {
        node cur = path.front();
        path.pop();
        if (tmap[cur.x][cur.y] == -1) {
            printf("%d\n", cur.t);
            flag = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            x_ = cur.x + xbias[i];
            y_ = cur.y + ybias[i];
            if (x_ >= 0 && x_ <= 300 && y_ >= 0 && y_ <= 300) {
            		if (cur.t + 1 < tmap[x_][y_] || tmap[x_][y_] == -1) {
            			tmp.x = x_;
            			tmp.y = y_;
            			tmp.t = cur.t + 1;
            			path.push(tmp);
            		}
            }
        }
    }
    if (!flag) printf("-1\n");
    return 0;
}
