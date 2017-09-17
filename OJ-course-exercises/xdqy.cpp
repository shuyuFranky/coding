/**
* 仙岛求药
*/
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

char mymap[22][22];
int m,n;
int xi[4] = {-1,1,0,0};
int yi[4] = {0,0,-1,1};

struct node{
    int ni;
    int nj;
    int step;
    node (int i, int j, int s):ni(i),nj(j),step(s){ }
};

queue<node> q;

void bfs() {
	int ni,nj,step;
    while (!q.empty()) {
    		node tmp = q.front();
        if (mymap[tmp.ni][tmp.nj] == '*') break;
        for (int i = 0; i<4; i++) {
        		ni = tmp.ni + xi[i];
        		nj = tmp.nj + yi[i];
        		step = tmp.step + 1;
        		if(ni > 0 && ni <= m && nj > 0 && nj <= n && mymap[ni][nj] != '#') {
        			q.push(node(ni,nj,step));
        		}
        }
        mymap[tmp.ni][tmp.nj] = '#';
        q.pop();
    }
    if (!q.empty()) {
    		node tmp = q.front();
        cout<<tmp.step<<endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int si = 0, sj = 0;
    while(cin>>m>>n) {
        if (m==0 && n==0) break;
        while(!q.empty()) q.pop();
        for (int i = 1; i<=m; i++) {
            for (int j = 1; j<=n; j++) {
            		cin>>mymap[i][j];
                if (mymap[i][j] == '@') {
                    si = i;
                    sj = j;
                }
            }
        }
        q.push(node(si,sj,0));
        bfs();
    }
    return 0;
}