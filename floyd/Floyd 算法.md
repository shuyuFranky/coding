### Floyd 算法

> **算法思想：** 通过中间节点来缩短两点之间的距离
>
> **实现：** 枚举可以使用的中间节点，只使用1号节点做中间节点，只使用1、2号节点做中间节点...... 即只使用前k个节点做中间节点，优化每两个节点间的距离。
>
> ```c++
> for (int k = 1; k <= N; k++) {
>   for (int i = 1; i <= N; i++) {
>     for (int j = 1; j <= N; j++) {
>       if (e[i][k] < inf && e[k][j] < inf && 
>           e[i][j] > e[i][k] + e[k][j]) {
>             e[i][j] = e[i][k] + e[k][j];
>           }
>     }
>   }
> }
> ```
>
> **解题报告：** 
>
> > - [POJ1125](https://github.com/shuyuFranky/coding/blob/master/floyd/POJ1125.cpp)
> > - [POJ1603](https://github.com/shuyuFranky/coding/blob/master/floyd/POJ1603.cpp)
> > - [POJ3268-TLE](https://github.com/shuyuFranky/coding/blob/master/floyd/POJ3268-TLE.cpp)
> >
> > > 一上均是建图然后直接对floyd算法的应用，其中POJ 3268会超时，需要采用dijkstra，见[dijkstra/POJ3268.cpp](https://github.com/shuyuFranky/coding/blob/master/dijkstra/POJ3268.cpp)
