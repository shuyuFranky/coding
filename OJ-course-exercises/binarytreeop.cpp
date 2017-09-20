#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 110;

struct Node {
	int father;
	int left, right;
};

Node node[maxn];
int N, M;

int main() {
	int Tests;
	scanf("%d\n", &Tests);
	while (Tests --) {
		scanf("%d %d\n", &N, &M);
		memset(node, 0, sizeof(node));
		for (int i = 0; i < N; i++) {
			int x, y, z;
			scanf("%d %d %d\n", &x, &y, &z);
			node[x].left = y;
			node[x].right = z;
			if (y != -1) node[y].father = x;
			if (z != -1) node[z].father = x;
		}
		for (int i = 0; i < M; i++) {
			int op, x, y;
			scanf("%d", &op);
			if (op == 1) {
				scanf("%d %d\n", &x, &y);
				int fa1 = node[x].father;
				int fa2 = node[y].father;
				bool flag1_left = false;
				bool flag2_left = false;
				if (node[fa1].left == x) flag1_left = true;
				if (node[fa2].left == y) flag2_left = true;
				if (flag1_left) node[fa1].left = y;
					else node[fa1].right = y;
				if (flag2_left) node[fa2].left = x;
					else node[fa2].right = x;
				node[x].father = fa2;
				node[y].father = fa1;
			}
			if (op == 2) {
				scanf("%d\n", &x);
				int ret = x;
				while (node[ret].left != -1) ret = node[ret].left;
				printf("%d\n", ret);
			}
		}
	}
	return 0;
}