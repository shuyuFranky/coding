## KMP 算法

> **简介：** 由 [Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth)/[James H. Morris](https://en.wikipedia.org/wiki/James_H._Morris)/[Vaughan Pratt](https://en.wikipedia.org/wiki/Vaughan_Pratt) 等人发明的字符串模式匹配算法。
>
> **核心思想：**利用已计算的信息减少匹配次数，将朴素算法*O*(n\*m)的时间复杂度降为*O*(n)。
>
> **相关参考资料：**
>
> - [字符串匹配: KMP算法---始终][https://liam0205.me/2016/12/20/KMP-Algorithm/]
> - [从头到尾彻底理解KMP---v_JULY_v][http://blog.csdn.net/v_july_v/article/details/7041827]
>
> **理解：** 
>
> - 当前匹配点不匹配，如果仅将模式串向后移动一位重第一位比较，模式串第二位和第一位不同，则这次匹配一定不会成功，则需要找到最长的匹配前缀和后缀，如下图：
>
>   <img src="https://github.com/shuyuFranky/coding/blob/master/img/img1.png" alt="此处应该有图片" width="300px" align="middle"></img>
>
> - KMP算法伪码
>
>   ```c++
>   // 假设已经计算好了next数组
>   KMP() {
>     p,o = 0;
>     while p < plen && o < olen {
>       if p == -1 || par[p] = ori[o]
>         p++, o++;
>       else
>         p = next[p];
>     }
>     if p == plen
>       // 匹配成功
>       index = o - p
>       return index;
>     else
>       // 匹配失败
>       return -1;
>   }
>   ```
>
> - next数组理解：
>
>   > - 定义：
>   >
>   >   > next[0] = -1;
>   >   >
>   >   > next[q] = k：表示p[q]之前的子串存在长度为k的相同前缀和后缀，即p[0,k-1] = p[q-k,q-1];
>   >   >
>   >   > e.g.:
>   >   >
>   >   > > p[5] = 3, p[0,2] = p[2,4]
>   >   > >
>   <img src="https://github.com/shuyuFranky/coding/blob/master/img/img2.png" alt="此处应该有图片" width="200px" align="middle"></img>
>   >
>   > - 计算next数组：
>   >
>   >   > **递归思想(转化为递推求解)：**假设已知next[0,q]，求next[q+1]
>   >   >
>   >   > ```c++
>   >   > next[q] = k;
>   >   > If p[k] == p[q]:
>   >   > 	// 则p[q+1]之前的前缀存在k+1的匹配前后缀串
>   >   > 	next[q+1] = k+1;
>   >   > else:	
>   >   > 	// 不同，则不存在k+1的串，需找更短的匹配前后缀串
>   >   > 	// 假设长度为j，则
>   >   > 	// p[0,j-1] = p[q-j,q-1] = p[k-j,k-1]
>   >   > 	// 由next数组定义得，j = next[k]
>   >   > 	// 递归查找
>   >   > 	k = next[k]；
>   >   > ```
>   >   >
>   >   >  **实现**
>   >   >
>   >   > ```c++
>   >   > char par[plen];
>   >   > int next[plen];
>   >   > void preNext() {
>   >   >   int i = -1, j = 0;
>   >   >   next[0] = -1;
>   >   >   while (j < plen) {
>   >   >   	if (i == -1 || par[i] == par[j]) {
>   >   >       i++, j++;
>   >   >       next[j] = i;
>   >   >   	} else {
>   >   >       i = next[i];
>   >   >   	}  
>   >   >   }
>   >   > }
>   >   > ```
>   >
>   > - Next数组优化
>   >
>   >   > **核心思想**：避免par[ j ] = par[ next[ j ] ]
>   >   >
>   >   > **理解**：
>   >   >
>   >   > > - 当匹配par[j] 和 ori[o]时，不匹配，回溯p = next[j]，接着将比较par[p] = par[next[j]] ?= ori[o];
>   >   > > - 如果 par[j] = par[next[j]] = par[p]:
>   >   > > - 则显然par[p] != ori[o];
>   >   > > - 故应该避免par[ j ] = par[next[j]]情况产生。
>   >   >
>   >   > **实现**
>   >   >
>   >   > ```c++
>   >   > char par[plen];
>   >   > int next[plen];
>   >   > void preNext() {
>   >   >   int i = -1, j = 0;
>   >   >   next[0] = -1;
>   >   >   while (j < plen) {
>   >   >   	if (i == -1 || par[i] == par[j]) {
>   >   >       i++, j++;
>   >   >       // 从下面开始修改5行
>   >   >       if (j == plen || par[i] != par[j]){
>   >   >         next[j] = i;     // 原来只有这一行
>   >   >       } else {
>   >   >         next[j] = next[i]; // 避免上述情况，继续回溯
>   >   >       }
>   >   >   	} else {
>   >   >       i = next[i];
>   >   >   	}  
>   >   >   }
>   >   > }
>   >   > ```

#### 解题报告

> - hiho coder 1015	&	POJ3461
>
>   > **题目大意：** 找出原串中包含的模式串个数 ，包含可以重叠
>   >
>   > **注意：** 需要计算plen+1位next数组，即某次匹配完成后需要回溯到next[plen]开始下一次查找。
>
> - POJ2752
>
>   > **题目大意：** 求字符串S中所有匹配的前缀后缀
>   >
>   > **解题思路：**
>   >
>   > - 除本身外最大长度匹配前后缀即为next[slen];
>   >
>   > - 子问题：求S[0,next[i]]的匹配前后缀
>   >
>   >   - 即 i = next[i]; 递归查找所有的i，i > 0 为结束条件
>   >
>   >   ```c++
>   >   int ind = 0;
>   >   int len = next[slen];
>   >   int i = len;
>   >   int res[len];  // c++ 新特性，老版本不支持这样写
>   >   res[ind++] = slen;
>   >   while (i>0) {
>   >     res[ind++] = i;
>   >     i = next[i];
>   >   }
>   >   // 反序输出即可
>   >   ```
>
> - POJ2406
>
>   > **题目大意：** S=a^n=a\*a^(n-1), str=str1\*str2=concat(str1,str2); 求n。
>   >
>   > **解题思路：**
>   >
>   > - 如果有子串a，
>   > - - **则a.length = slen - next[slen];**
>   > - - 且slen % a.length == 0
>
> - POJ1961
>
>   > **题目大意：** 求S字符串所有子串存在的循环周期，subS=a^n，则存在循环且周期为n。(要求输出n > 1的解)
>   >
>   > **解题思路：** 同上

