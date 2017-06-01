# CodeForces 802 题解



### A~C  Heidi and Library

#### 题意

一个图书馆，最初是空的，任意时刻最多$k$本书。从第$1$天到第$n$天早晨从图书馆中借书，每天借一本。为了满足所有的需求，需要在第$0$天到第$n-1$天晚上扔书/买书，每天晚上可以扔任意本书/买任意次（也可以不买），每次只能买一本。问最少需要买多少次

#### A  Easy

**限制**

$1 \le n, k \le 80$

**思路**

核心idea是，当我们不得不扔掉一本书时，一定选择当前仓库中“下一次”出现最晚的那一本（若将来不再出现，那一定是“最晚”的）。
所以，每当我们需要删去一本书时，只需要枚举每一本书，找出它下一次出现的时间即可实时维护仓库。
时间复杂度$O(n^3)$。

#### B  Medium

**限制**

$1 \le n, k \le 400\ 000$

**思路**

我们把Easy思路中的枚举换为用堆维护即可。大根堆，堆中的每个元素是一个（下一次出现时间，编号）二元组。我们先预处理出每一本书的所有出现时间，接着从前往后扫描每一天的需求，每天都往堆中插入对应书本的二元组。需要扔掉一本书时，选择堆顶的那一本（如果在仓库中）即可。注意一本书在堆中可能会出现多次（类似Dijkstra的过程），所以取出堆顶时，需要判断这本书是否实际上已经不存在仓库中。

时间复杂度$O(n \log {k})$
