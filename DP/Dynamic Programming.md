#### Dynamic Programming

> - 背包问题
>
> > 1. 01背包
> >
> > ```c++
> > for (int i = 1; i <= N; i++) {
> > 	for (int j = 0; j <= M; j++) {
> >     	if (good[i].w <= j) {
> >         	opt[i][j] = max(opt[i-1][j], opt[i-1][j-good[i].w] + good[i].v);
> >         } else {
> >         	opt[i][j] = opt[i-1][j];
> >         }
> >     }
> > }
> > ```
> >
> > 2. 空间优化
> >
> > ```c++
> > for (int i = 1; i <= N; i++) {
> > 	for (int j = M; j >= 0; j--) {
> >     	if (good[i].w <= j) {
> >         	opt[j] = max(opt[j], opt[j-good[i].w] + good[i].v); 
> >         }
> >     }
> > }
> > ```
> >
> > 3. 完全背包
> >
> > ```c++
> > for (int i = 1; i <= N; i++) {
> > 	for (int j = good[i].w; j <= M; j++) {
> >     	if (good[i].w <= j) {
> >         	opt[j] = min(opt[j], opt[j-good[i].w] + good[i].v);
> >         }
> >     }
> > }
> > ```
>
> - 带权区间调度
>
> > 1. 活动按结束时间排序；
> > 2. 计算 $p[i], i \in \{1\dots n\}$ ，$p[i]$ 为活动 $i$ 之前与第 $i$ 个活动兼容的最后一个活动； 
> > 3. 递推式：$opt[j] = max(space[j-1].w + opt[p[j]],\quad opt[j-1])$ 
>
> - LCS
>
> > 最长公共子序列
> >
> > - 最长公共子序列问题也有最优子结构性质。
> >
> > > 记:
> > >
> > > ​	Xi=﹤x1，⋯，xi﹥即X序列的前i个字符 (1≤i≤m)（前缀）
> > >
> > > ​	Yj=﹤y1，⋯，yj﹥即Y序列的前j个字符 (1≤j≤n)（前缀）
> >
> > > 假定Z=﹤z1，⋯，zk﹥∈LCS(X , Y)。
> > >
> > > - 若**xm=yn**（最后一个字符相同），则不难用反证法证明：该字符必是X与Y的任一最长公共子序列Z（设长度为k）的最后一个字符，即有zk = xm = yn 且显然有Zk-1∈LCS(Xm-1 , Yn-1)即Z的前缀**Zk-1是Xm-1与Yn-1的最长公共子序列**。此时，问题化归成求Xm-1与Yn-1的LCS（*LCS(X , Y)的长度等于LCS(Xm-1 , Yn-1*)的长度加1）。
> > > - 若**xm≠yn**，则亦不难用反证法证明：要么Z∈LCS(Xm-1, Y)，要么Z∈LCS(X , Yn-1)。由于zk≠xm与zk≠yn其中至少有一个必成立，若zk≠xm则有Z∈LCS(Xm-1 , Y)，类似的，若zk≠yn 则有Z∈LCS(X , Yn-1)。此时，问题化归成求Xm-1与Y的LCS及X与Yn-1的LCS。LCS(X , Y)的长度为：max{LCS(Xm-1 , Y)的长度, LCS(X , Yn-1)的长度}。
> >
> > - 递推方程：
> >
> > $$
> > c[i, j] = \begin{equation}
> > \begin{cases}
> > 0 \qquad \qquad \qquad \qquad \qquad \qquad \qquad if\quad (i == 0 || j == 0)\\
> > c[i - 1, j - 1] + 1\qquad \qquad \quad if\quad (i,j > 0\&\&x[i] == y[j]) \\
> > max\{c[i-1, j], c[i, j-1]\} \quad if\quad (i,j > 0\&\&x[i] != y[j])
> > \end{cases}
> > \end{equation}
> > $$
> >
> > ```c++
> > void LCS() {
> >     for (int i = 1; i <= n; i++) {
> >         for (int j = 1; j <= m; j++) {
> >             if (x[i] == y[j]) {
> >                 c[i][j] = c[i-1][j-1] + 1;
> >                 b[i][j] = 1;
> >             } else {
> >                 if (c[i-1][j] > c[i][j-1]) {
> >                     c[i][j] = c[i-1][j];
> >                     b[i][j] = 2;
> >                 } else {
> >                     c[i][j] = c[i][j-1];
> >                     b[i][j] = 3;
> >                 }
> >             }
> >         }
> >     }
> > }
> > ```
>
> - LIS
>
> > 最长上升子序列
> >
> > - $O(N^{2})$ 解法
> >
> > > 用dp[i]表示子序列 1\~ i的最长上升序列数目；
> > >
> > > 则对于每个i，枚举1~i，找出最长上升序列
> > >
> > > ```c++
> > > // 初始化
> > > for (int i = 1; i <= N; i++) dp[i] = 1; 
> > > ans = 0;
> > > for (int i = 2; i <= N; i++) {
> > >     // 找以i结尾最长的上升子序列长度
> > >     for (int j = 1; j < i; j++) {
> > >         if (arr[j] < arr[i]) {
> > >             dp[i] = max(dp[j] + 1, dp[i]);
> > >         }
> > >     }
> > >   	ans = max(ans, dp[i]);
> > > }
> > > ```
> >
> > - $O(Nlog(N))$ 解法：贪心 + 二分查找
> >
> > >  用dp[i]表示子序列 1\~ i的最长上升序列数目；
> > >
> > > 用g[i]表示长度为i的子序列最后一位的最下值；
> > >
> > > > 贪心的思想：长度相同子序列，末尾值越小越可能获得更长的序列；
> > > >
> > > > 二分查找：用lower_bound()函数获取第一个大于arr[i]的位置，并用arr[i]替换；
> > >
> > > ```c++
> > > #include<algorithm>
> > > int N;
> > > int arr[maxn + 5];
> > > int dp[maxn + 5];
> > > int g[maxn + 5];
> > >
> > > int main() {
> > >     ios::sync_with_stdio(false);
> > >     while(cin >> N) {
> > >         for(int i = 1; i <= N; i++)
> > >             cin >> arr[i];
> > >
> > >         for(int i = 1; i <= N; i++)
> > >             g[i] = inf;
> > >
> > >         int ans = 0;
> > >         for(int i = 1; i <= N; i++) {
> > >             // 二分查找下届
> > >             int k = lower_bound(g+1,g+N+1,arr[i])-g;
> > >             dp[i] = k;
> > >             g[k] = arr[i];
> > >             ans = max(ans, k);
> > >         }
> > >         cout << ans << endl;
> > >     }
> > >     return 0;
> > > }
> > > ```
> > >
> > > 
>
> - 带负权的最短路（Bellman Ford）
>
> > 1. 可以解决带负权值的 **单汇点** 最短路问题；
> > 2. 判断负环；
> >
> > - Bellman-Ford 算法描述：
> >
> > > 1. 创建源顶点 v 到图中所有顶点的距离的集合 dist[]，为图中的所有顶点指定一个距离值，初始均为 Infinite，源顶点距离为 0；
> > > 2. 计算最短路径，执行 V - 1 次遍历；
> > >
> > > > 对于图中的每条边$<u, v>$：松弛dist[v]，即松弛条件： $dist[v] > dist[u] + e[u][v]$；
> > >
> > > 3. 检测图中是否有负权边形成了环：执行第V次遍历，若还有边进行了松弛操作，则说明存在环；
> >
> > 直观理解，最短路最多包含 $V-1$ 条边，只需要进行 $V-1$ 次遍历即可获得所有 $V-1$ 条边以内的最短路，若第 $V$ 次遍历仍能松弛则说明存在负环；
> >
> > - 基于邻接矩阵的实现
> >
> > ```c++
> > void bellman_ford() {
> >     for (int i = 1; i <= N; i++) dis[i] = e[1][i];
> >     for (int t = 1; t < N; t++) {
> >         for (int i = 1; i <= N; i++) {
> >             for (int j = 1; j <= N; j++) {
> >                 if (dis[j] > dis[i] + e[i][j]) {
> >                     dis[j] = dis[i] + e[i][j];
> >                 }
> >             }
> >         }
> >     }
> > }
> > ```
> >
> > - 与dijkstra ，floyd 等算法比较
> >
> > > |              | 单源 or 多源 | 是否支持负 | 时间复杂度（Simple） | insight                           |
> > > | ------------ | -------- | ----- | ------------- | --------------------------------- |
> > > | Dijkstra     | 单        | 否     | O($V^{2}$)    | **贪心** 不断向S中加入一个点，松弛边             |
> > > | Floyd        | 多        | 否     | O($V^{3}$)    | **动规** 用每个点来松弛边，得到$e[i][j]$ 的最小距离 |
> > > | Bellman-Ford | 单        | 是     | O(V\*E)       | **动规** 每次迭代，枚举每条边，松弛到该边终点的距离      |
>
> - SPFA
>
> > Shortest path fast algorithm
> >
> > - 功能：求单汇点最短路径 + 判断负环
> > - 方法：
> >
> > > **初始化：**  d数组全部赋值为INF（无穷大）；p数组全部赋值为s（即源点），或者赋值为-1，表示还没有知道前驱然后d[s]=0;  表示源点不用求最短路径，或者说最短路就是0。将源点入队；(另外记住在整个算法中有顶点入队了要记得标记vis数组，有顶点出队了记得消除那个标记)
> > >
> > > **队列+松弛操作: ** 读取队头顶点u，并将队头顶点u出队（记得消除标记）；将与点u相连的所有点v进行松弛操作，如果能更新估计值（即令d[v]变小），那么就更新，另外，如果点v没有在队列中，那么要将点v入队（记得标记），如果已经在队列中了，那么就不用入队；
> > >
> > > 以此循环，直到队空为止就完成了单源最短路的求解。
> >
> > - 解题报告：POJ-1511