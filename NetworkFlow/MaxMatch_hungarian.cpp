/*
 * hungarian algo for maximum_matching
 * 适用问题：
 * 最大匹配数：最大匹配的匹配边的数目
 * 最小点覆盖数：选取最少的点，使任意一条边至少有一个端点被选择
 * 最大独立数：选取最多的点，使任意所选两点均不相连
 * 最小路径覆盖数：对于一个 DAG（有向无环图），选取最少条路径，使得每个顶点属于且仅属于一条路径。路径长可以为 0（即单个点）。
 * 
 * 定理1：最大匹配数 = 最小点覆盖数（这是 Konig 定理）
 * 定理2：最大匹配数 = 最大独立数
 * 定理3：最小路径覆盖数 = 顶点数 - 最大匹配数
 */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > lnklst;
vector<int> l, r;
vector<bool> visited;

/* make all vectors one element bigger in case the index starts from 1 instead of 0 */
void init(int n1, int n2) {
  lnklst.clear(); lnklst.resize(n1+1);
  l.clear(); l.resize(n1+1,-1);
  r.clear(); r.resize(n2+1,-1);
  return;
}

void add_edge(int u, int v) {
  lnklst[u].push_back(v);
  return;
}

bool dfs(int u) {
  for (int i=0; i<lnklst[u].size(); i++) {
    int v = lnklst[u][i];
    if (visited[v]) continue;
    visited[v] = true;
    if (r[v] < 0 || dfs(r[v])) {
      l[u] = v;
      r[v] = u;
      return true;
    }
  }
  return false;
}

int greedy_match(int n1) {
  int match = 0;
  for (int u=0; u<n1; u++) {
    if (l[u] < 0) {
      for (int i=0; i<lnklst[u].size(); i++) {
        int v = lnklst[u][i];
        if (r[v] < 0) {
          l[u] = v;
          r[v] = u;
          match++;
          break;
        }
      }
    }
  }
  return match;
}

int hungarian(void) {
  int n1 = l.size();
  int n2 = r.size();
  int match = greedy_match(n1);
  for (int u=0; u<n1; u++) {
    if (l[u] < 0) {
      visited.clear();
      visited.resize(n2);
      if (dfs(u)) {
        match++;
      }
    }
  }
  return match;
}


int main() {
  //freopen("path_cover.dat", "r", stdin);
  int n, m;
  while (cin >> m >> n) {
    init(n, n);
    for (int i=0; i<m; i++) {
      int u, v;
      cin >> u >> v;
      add_edge(u, v);
    }
    int max_match = hungarian();
    cout << n-max_match << endl;
  }
  return 0;
}