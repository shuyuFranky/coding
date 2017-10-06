### Graph

##### 一、图表示

> 1. Adjacency matrix 邻接矩阵
>
> <img src="https://github.com/shuyuFranky/coding/blob/master/img/adj-matrix.png" alt="adj-matrix" width="400px;"></img>
>
> 1. Adjacency list 邻接表
>
> > - 链表实现
> >
> > <img src="https://github.com/shuyuFranky/coding/blob/master/img/adj-list.png" alt="adj-list" width="400px;"></img>
> >
> > - 数组实现
> >
> > <img src="https://github.com/shuyuFranky/coding/blob/master/img/adj-arr-graph.png" alt="adj-array" width="150px;"></img> <br>
> > <img src="https://github.com/shuyuFranky/coding/blob/master/img/adj-array.png" alt="adj-array" width="200px;"></img> <br>
> > <img src="https://github.com/shuyuFranky/coding/blob/master/img/adj-arr-use.png" alt="adj-array" width="200px;"></img> <br>

##### 二、图遍历

> - BFS
> - DFS

##### 三、二部图

> 无向图 G=(V, E) 是二部图，当用两种不同颜色染色所有节点时，能够找到某种染色方法使得每条边连接的两个顶点为不同的颜色。
>
> <img src="https://github.com/shuyuFranky/coding/blob/master/img/bipartite-graph.png" alt="bipartite-graph" width="300px;"></img>
>
> - Bipartiteness
>
>   - **Lemma.** 二部图不含奇数边的环。
>   - **Pf.** 奇数环不能二染色。
>
> - 二部图判断
>
>   - G为连通图，设 $$ L\_{0}, L\_{1}, … , L\_{k} $$ 为 BFS 返回的层
>
>   > 1. G 中没有同层间相连的边，则 G 是二部图。
>   > 2. G 中有同层间相连的边，则 G 存在奇数边的环，故不是二部图。
>   >
>   > **证明：**
>   >
>   > (1) 每一层不同着色，满足二着色，是二部图。
>   >
>   > (2) 设 x-y 为某一层中相连的边，则可以找到他们最近的公共祖先节点 z，由 x → z → y → x 构成的环为奇数环， 长度为 1 + (j - i) + (j - i)，如下图。
>   >
>   > <img src="" alt="pf-bipartite"></img>
>
> - 推论 Corollary
>   > G 是二部图，当且仅当 G 中没有奇数边环。

##### 四、有向图

> - 强连通性：有向图 G 中每个点都相互可达，则 G 是强连通的。
> - 强连通算法：
>
> > 1. 选择一个起点 s
> > 2. 以 s 为起点在G中进行BFS
> > 3. 以 s 为起点在G_reverse中进行BFS
> > 4. 在2，3中均访问到所有节点，则G是强连通的。

##### 五、有向无环图

> DAG : Directed acyclic graphs
>
> - **precedence constraints** : E(v, u)，即任务 v 要先于任务 w 完成。
> - **Lemma.** 如果G有一个拓扑顺序，则G是一个DAG。
> - **Lemma.** 如果G是一个DAG，则G有一个顶点没有入边。
> - **Lemma.** 如果G是一个DAG，则G有一个拓扑顺序。
>
> 拓扑顺序
>
> > 1. 找到没有入边的点 v
> > 2. 将 v 以及其出边删除
> > 3. 新的没有入边的点加入集合 V' 
> > 4. 重复 2，3 过程，
> > 5. 则删除点的顺序为一个拓扑顺序。
