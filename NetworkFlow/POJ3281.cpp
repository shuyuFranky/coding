/**
 * Dining
 * Dinic
 * 建图：
 *      s->食物->牛->牛->饮料->t
 *      每条边的容量都为1
 *  注意：牛要拆点，保证不会有多组食物分到同一头牛
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>

#define N (2005)
#define M (100000)

typedef long long LL;

using namespace std;

struct edge {
  int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

/*
 * When there are multiple test sets, you need to re-initialize before each
 */
void dinic_init(void) {
  num_of_edges = 0;
  memset(head, -1, sizeof(head));
  return;
}

int add_edge(int u, int v, int c1, int c2) {
  int& i=num_of_edges;

  assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
  e[i].v = v;
  e[i].cap = c1;
  e[i].next = head[u];
  head[u] = i++;

  e[i].v = u;
  e[i].cap = c2;
  e[i].next = head[v];
  head[v] = i++;
  return i;
}

void print_graph(int n) {
  for (int u=0; u<n; u++) {
    printf("%d: ", u);
    for (int i=head[u]; i>=0; i=e[i].next) {
      printf("%d(%d)", e[i].v, e[i].cap);
    }
    printf("\n");
  }
  return;
}

/*
 * Find all augmentation paths in the current level graph
 * This is the recursive version
 */
int dfs(int u, int t, int bn) {
  if (u == t) return bn;
  int left = bn;
  for (int &i=cur[u]; i>=0; i=e[i].next) {
    int v = e[i].v;
    int c = e[i].cap;
    if (c > 0 && level[u]+1 == level[v]) {
      int flow = dfs(v, t, min(left, c));
      if (flow > 0) {
        e[i].cap -= flow;
        e[i^1].cap += flow;
        cur[u] = i;
        left -= flow;
        if (!left) break;
      }
    }
  }
  if (left > 0) level[u] = 0;
  return bn - left;
}

bool bfs(int s, int t) {
  memset(level, 0, sizeof(level));
  level[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == t) return true;
    for (int i=head[u]; i>=0; i=e[i].next) {
      int v = e[i].v;
      if (!level[v] && e[i].cap > 0) {
        level[v] = level[u]+1;
        q.push(v);
      }
    }
  }
  return false;
}

LL dinic(int s, int t) {
  LL max_flow = 0;

  while (bfs(s, t)) {
    memcpy(cur, head, sizeof(head));
    max_flow += dfs(s, t, INT_MAX);
  }
  return max_flow;
}

int n, f, d;
int get_id(int type, int i) {
    int id = -1;
    if (type == 1) {
        // food
        id = i;
    } else if (type == 2) {
        // niu-1
        id = f + i;
    } else if (type == 3) {
        // niu-2
        id = f + n + i;
    } else if (type == 4) {
        // drink
        id = f + 2*n + i;
    } else {
        return -1;
    }
    return id;
}

int main() {
  int fn, dn;
  int fi, di;
  dinic_init();
  scanf("%d %d %d", &n, &f, &d);
  for (int i = 1; i <= f; i++) {
      add_edge(0, i, 1, 0);
  }
  for (int i = 1; i <= d; i++) {
      add_edge(get_id(4, i), f + 2*n + d + 1, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
      int niu1 = get_id(2, i);
      int niu2 = get_id(3, i);
      add_edge(niu1, niu2, 1, 0);
      scanf("%d %d", &fn, &dn);
      while (fn --) {
          scanf("%d", &fi);
          add_edge(fi, niu1, 1, 0);
      }
      while (dn --) {
          scanf("%d", &di);
          add_edge(niu2, get_id(4, di), 1, 0);
      }
  }
  int flow = dinic(0, f + 2*n + d + 1);
  printf("%d\n", flow);

  return 0;
}
