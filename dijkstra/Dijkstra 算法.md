### Dijkstra 算法

> **解决问题：** 单源最短路
>
> - **问题描述：** 在无向图 G=(V,E) 中，假设每条边 E[i] 的长度为 w[i]，找到由顶点 V0 到其余各点的最短路径。（单源最短路径）
> - **算法思想：** 将V划分为两个集合，S和U，将起点*s*加入到S，然后从U中选择距离*s*最近的点v加入S（当所有点加入S后算法结束）。对*s*通过v能访问到的点做**松弛**操作，逐步获得*s*到各点的最短路径。
> - **算法步奏：** 
>   - A. 初始时，S只包含源点，即S＝{ *s* }，*s* 的距离为0。U包含除 *s* 外的其他顶点，即:U={其余顶点}，若 *s* 与U中顶点u有边，则<u,s>正常有权值，若u不是 *s* 的出边邻接点，则<u,s>权值为∞。
>   - B. 从U中选取一个距离 *s* 最小的顶点v，把v，加入S中（该选定的距离就是 *s* 到v的最短路径长度）。
>   - C. 以v为新考虑的中间点，修改U中各顶点的距离；若从源点 *s* 到顶点u的距离（经过顶点v）比原来距离（不经过顶点v）短，则修改顶点到u的距离值，修改后的距离值的顶点v的距离加上边e(v,u)的权。
>   - D. 重复步骤B和C直到所有顶点都包含在S中。
> - 算法执行动画如下：
>
> > <img src="https://github.com/shuyuFranky/coding/blob/master/img/dijkstra.gif" alt="dijkstra 演示gif"> </img>
>
> - 算法核心过程如下：
>
> ```c++
> // 核心算法
>     for (i = 1; i<=N-1; i++) {
>         // 在dis数组中找到距离1最近的点
>         min = INF;
>         for (j = 1; j<=N; j++) {
>             if (book[j] == 0 && dis[j] < min) {
>                 min = dis[j];
>                 u = j;
>             }
>         }
>         book[u] = 1;
>         for (v = 1; v<=N; v++) {
>             // 对以点u为起点的边，做松弛操作
>             if (e[u][v] < INF) { 
>                 if (dis[v] > dis[u] + e[u][v]) {
>                     dis[v] = dis[u] + e[u][v];
>                 }
>             }
>         }
>     }
> ```
>
> - 解题报告：
>
> > - POJ2387
> >
> > > Dijkstra 模板题，直接套用模板，代码见[POJ2387.cpp](https://github.com/shuyuFranky/coding/blob/master/dijkstra/POJ2387.cpp)，注意边重复等细节问题。 
> >
> > - POJ2253
> >
> > > Dijkstra 变形题
> > >
> > > - 题目大意：求从点1(Freddy)到点2(Fiona)的所有路径中，最大间隔(单次跳跃距离)中的最小值。
> > >
> > >
> > > - 解法：
> > >
> > > > - 用dis[i]表示从起点1到点i的所有路径中的最大间隔的最小值。
> > > >
> > > > > 1. 初始化计算所有点到1的距离 $$len\_{i}$$ ，即 $$dis[i] = len\_{i}$$
> > > > >
> > > > >    > **设其中最小值$len\_{v}$，即dis[v] = len，可确定。（证明见下一小节）**
> > > > >
> > > > > 2. 找出dis[]中最小值对应的点v 
> > > > >
> > > > > 3. 将点v加入集合S，对所有边做**松弛**，如下图中dis\[u\]即可松弛为max(dis\[v\], e\[v\]\[u\])
> > > > >
> > > > > ```
> > > > > for j in [1..N]
> > > > > 	if dis[j] > max(dis[v], e[v][j]) {
> > > > >       	dis[j] = max(dis[v], e[v][j]);
> > > > > 	}
> > > > > ```
> > > > >
> > > > > 4. 重复2-3，直到所有点均加入S中
> > > > > 5. 输出dis[2]
> > > >
> > > > - 证明：
> > > >
> > > > > 如图所示
> > > > >
> > > > > <img src="https://github.com/shuyuFranky/coding/blob/master/img/2253-pro.png" width="400px;"> </img>
> > > > >
> > > > > - 因为v为距离s最近的点，即不会存在w点；
> > > > > - 假设有s->u->…->v的路径，不防设其中最大间隔为len = e\[v\]\[u\], 则len一定大于dis\[v\], 否则最大间隔将为dis[u]而不是e\[v\]\[u\]
> > >
> > > AC 代码见[POJ2253.cpp](https://github.com/shuyuFranky/coding/blob/master/dijkstra/POJ2253.cpp)
