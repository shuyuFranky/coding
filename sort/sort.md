## 排序算法集合

#### 一、快排

> **递归、分治**
>
> **算法思路：** 选择一个轴值，在数组中找到其对应的位置，使其前面的值小它后面的值大于(或等于它)，接着分治左右区间。
>
> **注意：** 
>
> - 递归结束条件 left >= right，即当前区间至多只有一个元素，有序。
> - 对应『挖坑』与『填坑』
>
> ```c++
> qSort(int * arr, int l, int r) {
>   if (l < r) {					// 递归结束条件
>     int i = l, j = r;
>     int x = arr[i];				// 『挖坑』
>     while (i < j) {
>       while (i<j && x <= arr[j]) {
>         j--;					// 从右向左寻找第一个小于x的值
>       }
>       if (i < j) {
>         arr[i++] = arr[j];      // 『填坑』同时『挖』下一个『坑』
>       }
>       while (i<j && x > arr[i]) {
>         i++;
>       }
>       if (i < j) {
>         arr[j--] = arr[i];
>       }
>     }
>     arr[i] = x;
>     qSort(arr, l, i-1);
>     qSort(arr, i+1, r);
>   }
> }
> ```
>
> **解题报告：**
>
> - POJ2388
> - POJ3664
>
> > 以上两题均简单运用快排，无他。



#### 二、堆排序

> 自底向上建堆，自顶向下更新堆
>
> **注意：**
>
> - 从第一个非叶子节点开始自底向上调节堆，每一个子树自顶向下调节
> - 实现时注意边界条件
>
> ```c++
> void sift(int k, int n) {
>     int i = k, j = 2*k;                 // i 为当前根节点， j 为左子节点
>     while (j<=n) {
>         if (j<n && arr[j] < arr[j+1])   // 将j指向较大的子节点，注意检查 j+1 是否越界
>             j++;
>         if (arr[i] > arr[j])            // 已经是最大值堆了，不再调整，
>             break;                      // 自底向上的过程保证了这里break正确
>         else {
>             swap(arr[i], arr[j]);       // 交换
>             i = j;                      // 自顶向下调整
>             j = 2*i;
>         }
>     }
> }
>
> /*
> *   堆排序函数
> */
> void heapsort() {                       
>     for (int i = N/2; i>=1; i--)        // 从最后一个非叶子节点开始
>         sift(i, N);                     // 自顶向下调整子树为最大值堆
>                                         // for 循环自底向上调节整个树为最大值堆
>     for (int i = 1; i<N; i++) {         // N-1 次取出最大值
>         swap(arr[1], arr[N-i+1]);       // 每次交换后 arr[N-i+1, N]为升序
>         sift(1, N-i);                   // 重新调整整棵树
>     }
> }
> ```
>
> **解题报告：**
>
> - POJ2833
>
>   > **题目大意：** n个得分去掉前n1个最高分和n2个最低得分后求均值。
>   >
>   > **分析：** 题目很简单，数据很变态，直接排序会MLE 
>   >
>   > **解题思路：** 
>   >
>   > > - 前 (n1 + n2) 个数qsort一遍，然后分成，n1个最大值组成的最小值堆和n2个最小值组成的最大值堆
>   > > - 即分别维护一个最小值堆和一个最大值堆
>   > > - 每次输入，判断是否大于最大值堆中的最小值，是则替换该最小值；否则判断是否小于最小值堆中的最大值，是则替换该最大值；否则该数据累加，用于统计最后均值
>   >
>   > **注意：** 
>   >
>   > > - 累加器必须用 **long long** ！！！
>   > > - 中间用int处理
>   > > - 最后返回值再转化为double输出
>   >
>   > **coding：**
>   >
>   > > qsort之后，按顺序填入，已经是最大值堆和最小值堆了，之后只需进行维护，代码同上。
>   > >
>   > > 以下为主函数代码，完整代码见POJ2833_heap.cpp
>   >
>   > ```c++
>   > int main() {
>   >     long long ans = 0;                          // 注意：累加器一定要用 long long
>   >     double res = 0;
>   >     while (1) {
>   >         ans = 0;
>   >         scanf("%d %d %lld", &g, &l, &n);
>   >         if (g < 1) break;
>   >         int tmp = 0;                            // 中间过程用int处理
>   >         for (int i = 0; i<g+l; i++) {
>   >             scanf("%d", &arr[i]);
>   >         }
>   >         qsort(0, g+l-1);
>   >         for (int i = 0; i<=g; i++){
>   >             g_minheap[i+1] = arr[g-i-1];
>   >         }
>   >         for (int i = g+1; i<=g+l; i++){
>   >             l_maxheap[i-g] = arr[i-1];
>   >         }
>   >         int c_g_min = g_minheap[1];
>   >         int c_l_max = l_maxheap[1];
>   >         for (int i = g+l; i<n; i++) {
>   >             scanf("%d", &tmp);
>   >             if (tmp > c_g_min) {
>   >             		ans += c_g_min;
>   >                 g_minheap[1] = tmp;
>   >                 sift_min(1, g);
>   >                 c_g_min = g_minheap[1];
>   >             } else if (tmp < c_l_max){
>   >             		ans += c_l_max;
>   >                 l_maxheap[1] = tmp;
>   >                 sift_max(1, l);
>   >                 c_l_max = l_maxheap[1];
>   >             } else {
>   >                 ans += tmp;
>   >             }
>   >         }
>   >         res = double(ans) / (n - g - l);        // 最后结果转回 double
>   >         printf("%.6lf\n", res);
>   >     }
>   >     return 0;
>   > }
>   > ```
>   >
>   > ​



#### 归并排序

> **递归、分治**
>
> **算法过程，如图**
>
> <img src="https://github.com/shuyuFranky/coding/blob/master/img/img3.png" alt="此处应该有图片" width="200px"> </img>
>
> **解题报告：**
>
> POJ1804、POJ2299
>
> > 两道题均为求逆序对，只需对数组进行归并排序，在合并时计算逆序怼数。
> >
> > ```c++
> > void mergearr(int l, int r) {
> >     int i = l;
> >     int m = (l+r) / 2;
> >     int j =  m + 1;
> >     int k = 0;
> >     while (i<=m && j<=r) {
> >         if(arr[i] <= arr[j]) {         // 等于不算逆序数
> >             tmp[k++] = arr[i++];
> >         } else {                       // 当arr[i] > arr[j]时
> >             tmp[k++] = arr[j++];       // 将arr[j]放到arr[i]之前
> >             ans += m-i+1;              // 在前半部分中，比arr[i]大的数均比arr[j]大
> >         }                              // 即，计算逆序数时应加上这部分
> >     }
> >     while (i<=m) {
> >         tmp[k++] = arr[i++];
> >     }
> >     while (j<=r) {
> >         tmp[k++] = arr[j++];
> >     }
> >     for (i = l; i<=r; i++) {
> >         arr[i] = tmp[i-l];
> >     }
> > }
> > ```
> >
> > 



#### 桶排序

> **算法思想：** 
>
> > 排序过程：
> >
> > 1. 假设待排序的一组数统一的分布在一个范围中，并将这一范围划分成几个子范围，也就是桶
> > 2. 将待排序的一组数，分档规入这些子桶，并将桶中的数据进行排序
> > 3. 将各个桶中的数据有序的合并起来
>
> [Data Structure Visualizations](http://www.cs.usfca.edu/~galles/visualization/BucketSort.html) 提供了一个桶排序的分步动画演示。
>
> > 设有数组 array = [29, 25, 3, 49, 9, 37, 21, 43]，那么数组中最大数为 49，先设置 5 个桶，那么每个桶可存放数的范围为：09、1019、2029、3039、40~49，然后分别将这些数放人自己所属的桶，如下图：
>
> > [![img](https://github.com/shuyuFranky/coding/blob/master/img/img4.png)](https://github.com/shuyuFranky/coding/blob/master/img/img4.png)
>
> > 然后，分别对每个桶里面的数进行排序，或者在将数放入桶的同时用插入排序进行排序。最后，将各个桶中的数据有序的合并起来，如下图：
>
> > [![img](https://github.com/shuyuFranky/coding/blob/master/img/img5.png)](https://github.com/shuyuFranky/coding/blob/master/img/img5.png)
>
> **最快的排序算法：**
>
> > 假设数据量N，分M个桶
> >
> > 1. 遍历所有数据分组 => O(N)				①
> >
> > 2. 每个桶采用快排 => N/M*log(N/M)              ②
> >
> > 3. 一起有M个桶，进行M次快排 => M * ②      ③
> >
> >    > 即 O(N) + M*N/Mlog(N/M) = O(N + NlogN - NlogM)，即在桶内数据较均匀时，算法时间复杂度接近O(N)。
>
> **解题报告：**
>
> - POJ1002
>
> > **题目大意：** 电话号码匹配，输出有重复的号码，及号码重复出现的次数。没有重复则输出『No duplicates.』
> >
> > **解法：** 开一个bucket[10,000,000 + 5]大小的数组，运用桶排序的思想，记录重复的号码。时间和空间开销较大，之后可以采用trie树来优化。





— 待更新

