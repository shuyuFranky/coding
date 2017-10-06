### Stable Matching

#### 稳定婚姻问题

> - **Def.** Perfect matching
>
> >  两个集合中的元素个数相等，且全部参与配对，**不重不漏**。
>
> - **Def.** Unstable pair => m-w
>
> > 比起 m 现在的伴侣，m 更喜欢 w
> >
> > 比起 w 现在的伴侣，w 更喜欢 m
> >
> > > 即 m-w在一起的话，彼此都能提升，获得更好的伴侣
>
> - **Def.** Stable matching
>
> > 即：不存在 unstable pair 的 perfect matching
>
> - **Gale-Shapley 算法**
>
> > Gale-Shapley 算法给出了一种能找出稳定匹配的算法。Gale 和 Shapley 数学上证明了稳定匹配一定存在，并给出了能求解一种稳定匹配的算法。
> >
> > - 算法伪码
> >
> > ```c++
> > Gale-Shapley(preference list for man and woman)
> >
> > INITIZLIZE S to empty matching
> > WHILE (some man m is unmatched and hasn't proposed to every woman)
> > 	w <-- first woman on m's list to whom m has not yet proposed.
> > 	IF (w is unmatched)
> > 		Add pair m-w to matching S.
> > 	ELSE IF (w prefers m to her current partner m')
> > 		Remove pair m'-w from matching S.
> > 		Add pair m-w to matching S.
> > 	ELSE 
> > 		w rejects m.
> >
> > RETURN stable matching S.
> > ```
> >
> > - 正确性证明
> >
> > > 1. 已知：男生按偏好的降序向女生求婚
> > > 2. 已知：被求婚一次后的女生一直保持婚姻状态，只是会不断换更好的伴侣
> > >
> > > - 证 termination
> > >
> > > > **Claim.** 算法最多迭代 n^2 次。
> > > >
> > > > **Pf.** 每次循环一个男生向一个女生求婚，总共有 n^2 种情况。
> > >
> > > - 证 perfection
> > >
> > > > **Claim.** GS 匹配，所有男生和女生都参与配对，是一个 perfect matching
> > > >
> > > > **Pf.** 反证法
> > > >
> > > > 假设男生1没有配对，则有一个女生A没有配对，由已知2得，没有人像A求婚（包括1）
> > > >
> > > > 由循环结束条件得，1没有匹配则他一定向所有女生都求婚了，故矛盾。
> > >
> > > - 证 stability
> > >
> > > > **Claim.** GS匹配是一个稳定匹配。
> > > >
> > > > **Pf.** 给定任意一个GS的匹配S，假设1-A不存在S中，下证1-A一定是稳定的，即S中不存在不稳定的匹配。
> > > >
> > > > ①1从来没有向A求婚，即在S中1的伴侣B，有，1 更喜欢 B 比起 A。
> > > >
> > > > ==> 1-A 是稳定的。
> > > >
> > > > ②1向A求婚，A拒绝了1（立刻拒绝—已经有更好的了 或者 之后遇到更好的了--拒绝了1），即在S中A的伴侣2，有，A 更喜欢 2 比起 1.
> > > >
> > > > ==> 1-A 是稳定的。
> > > >
> > > > 因为①、②，即在任何情况下1-A是稳定的。
> >
> > - GS 是对男性更优的
> >
> > > 通过GS获得的稳定匹配，男性总是获得所有稳定匹配下最优的选择，而女性总是获得所有稳定匹配下最差的选择。
> > >
> > > - 证 man-optimality
> > >
> > > > **Claim.** GS 匹配是男性最优的。
> > > >
> > > > **Pf.** 反证法
> > > >
> > > > 假设男生1没有活动最佳伴侣，因为1是按偏好的降序像女生表白，即1一定被其最佳伴侣拒绝了。
> > > >
> > > > 不妨设1是第一个被其最佳伴侣A拒绝的男生。
> > > >
> > > > 设一个稳定匹配S，其中1-A配对（1号男生有最佳匹配）。
> > > >
> > > > 在GS中，当A拒绝1时，A要么正和2处于婚姻状态，要么刚和1离婚，接受2的求婚。
> > > >
> > > > ① 即 A 更喜欢 2 比起 1。
> > > >
> > > > 假设B是S中2的伴侣。
> > > >
> > > > 在 1 被拒绝的这一时刻，2 没有被自己最佳伴侣拒绝（因为1是第一个被最佳伴侣拒绝的人）。即2先向A表白，还没像B表白。
> > > >
> > > > ② 即 2 更喜欢 A 比起 B。
> > > >
> > > > 由①、② → 2-A 在 S 中是不稳定的，与S是稳定匹配矛盾。
> > >
> > > - 证 woman-pessimality
> > >
> > > > **Claim.** GS 匹配是女性最差匹配。
> > > >
> > > > **Pf.** 反证法
> > > >
> > > > 假设在GS的一个稳定匹配 S\* 中，有1-A，且男生1不是女生A的最差匹配。
> > > >
> > > > 存在一个稳定匹配S，其中有2-A匹配，且 A 更喜欢 1 比起 2。
> > > >
> > > > ① 即 A 更喜欢 1 比起 2
> > > >
> > > > 假设在S中 B 是 1 的伴侣，因为GS是man-optimality（证明如上），则 A 是 1 的最佳伴侣（1-A 在 S\*中）
> > > >
> > > > ② 即 1 更喜欢 A 比起 B
> > > >
> > > > 由于①、②，则在稳定匹配 S 中存在 1-A 不稳定匹配， 矛盾。
> >
> > 由于GS是 man-optimality 且 woman-pessimality ，在知道采用GS时，女生可以选择博弈（选择性的欺诈），即有策略的拒绝某些男生（即使他们比现任好），来最终获得比GS更好的伴侣。
>
> - 解题报告
>
> > POJ 3487
> >
> > GS 算法的直接应用
> >
> > AC 代码见[POJ3487.cpp](https://github.com/shuyuFranky/coding/blob/master/stable-matching/POJ3487.cpp) 
