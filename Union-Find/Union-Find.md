#### 并查集

> 支持两种对集合的操作：==Find(x) 和 Union(x, y)==
>
> > - Make-set(x)：创建一个仅包含 $x$ 的集合
> > - Find(x)：返回 $x$ 所在集合的代表元素
> > - Union(x, y)：将包含 $x$ 和 $y$ 的集合合并
>
> 应用：判断动态图的连通性

> - Link-by-size
> - Link-by-rank

> **Path compression**
>
> 在找到包含 $x$ 的树的根后，令路径上所有的节点父指针指向根节点，如下图![union-find](/Users/fatfat/workplace/hiho/img/union-find.png)

> **实现**
>
> - Link-by-rank + path compression
>
> > ```c++
> > int father[MAX];   /**/
> > int rank[MAX];     /* rank[x]表示x的秩*/
> >
> > /* 初始化集合*/
> > void Make_Set(int x) {
> >     father[x] = x; //根据实际情况指定的父节点可变化
> >     rank[x] = 0;   //根据实际情况初始化秩也有所变化
> > }
> >
> > /* 查找x元素所在的集合,回溯时压缩路径*/
> > int Find_Set(int x) {
> >     if (x != father[x]) {
> >         father[x] = Find_Set(father[x]); //这个回溯时的压缩路径是精华
> >     }
> >     return father[x];
> > }
> >
> > /**
> >  * 按秩合并x,y所在的集合
> >  * 下面的那个if else结构不是绝对的，具体根据情况变化
> >  * 但是，宗旨是不变的即，按秩合并，实时更新秩。
> > */
> > void Union(int x, int y) {
> >     x = Find_Set(x);
> >     y = Find_Set(y);
> >     if (x == y) return;
> >     if (rank[x] > rank[y]) {
> >         father[y] = x;
> >     } else {
> >         if (rank[x] == rank[y]) {
> >             rank[y]++;
> >         }
> >             father[x] = y;
> >     }
> > }
> > ```
>
> - 解题报告：
>
> > POJ1611、POJ2524 并查集模板题。（代码见./Union-Find） 