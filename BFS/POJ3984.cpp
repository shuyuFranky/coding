#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct node{
    int x;
    int y;
}path[7][7];

int map[7][7];

int xarr[4] = {-1, 1, 0, 0};
int yarr[4] = {0, 0, -1, 1};

void printPath() {
    int pathx[26];
    int pathy[26];
    int i = 5, j = 5;
    int cnt = 0;
    while (1) {
        if (i == 1 && j == 1)break;
        pathx[cnt] = path[i][j].x;
        pathy[cnt] = path[i][j].y;
        i = pathx[cnt];
        j = pathy[cnt];
        cnt++;
    }
    cnt--;
    for (; cnt >= 0; cnt--) {
        printf("(%d, %d)\n", pathx[cnt] - 1, pathy[cnt] - 1);
    }
    printf("(4, 4)\n");
}

int main() {
    queue<node> nq;
    node tmp;
    int x, y;
    bool endFlag = false;
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            scanf("%d", &map[i][j]);
            path[i][j].x = -1;
            path[i][j].y = -1;
        }
    }
    map[1][1] = -1;
    tmp.x = 1;
    tmp.y = 1;
    nq.push(tmp);
    // BFS
    while (!nq.empty() && !endFlag) {
        tmp = nq.front();
        nq.pop();
        for (int i = 0; i < 4; i++) {
            x = tmp.x + xarr[i];
            y = tmp.y + yarr[i];
            if (x < 1 || x > 5 || y < 1 || y > 5) continue;
            if (x == 5 && y == 5) {
                path[x][y].x = tmp.x;
                path[x][y].y = tmp.y;
                printPath();
                endFlag = true;
                break;
            } else if (map[x][y] == 0) {
                node newNode;
                newNode.x = x;
                newNode.y = y;
                nq.push(newNode);
                path[x][y].x = tmp.x;
                path[x][y].y = tmp.y;
                map[x][y] = 1;
            }
        }
    }
    if (!endFlag) {
        printf("error\n");
    }
    return 0;
}
