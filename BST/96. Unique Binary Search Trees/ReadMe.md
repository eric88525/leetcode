# 96. Unique Binary Search Trees

- binary search tree

count BST possibles

https://www.youtube.com/watch?v=YDf982Lb84o&ab_channel=TusharRoy-CodingMadeSimple

## 概念

- 在計算 root = n 有多少種組合 ，方法為 **n 左邊 node 能形成的的組合數** 乘上 **右邊 node 能形成的的組合數**
- n 個點能形成的組合數，用 dp 來記錄
- 因為 BST 特性， n 左邊的 node 都小於 n ， 右邊的 node 都大於 n，並不會有交集或替換可能。

## 當 n=2 (2 個 node)時

- 先設定初始

  - NODES(0) : 0 node，組合 1 種
  - NODES(1) = 1 ，1 node 組合 1 種

- 假設數字為 [10, 11]:
  - 10 as root : 左邊沒點，右邊 1 點-> NODES(0) \* NODES(1)
  - 11 as root: 左邊 1 點，右邊沒點 -> NODES(1) \* NODES(0)
  - NODES(0) \* NODES(1) + NODES(1) \* NODES(0) = 1 _ 1 + 1 _ 1 = 2

## 當 n=3

if node is [10, 11, 12]

- 10 as root : NODES(0) \* NODES(2)
- 11 as root: NDOES(1) \* NODES(1)
- 12 as root: NODES(2) \* NODES(0)

## 規律

可以發現:

leftIndex 會從 0 ~ n-1，右邊 index 為 n - leftIndex -1

```c++
class Solution {
public:
	int numTrees(int n) {

		vector<int> nodes(n + 1, 0);

		nodes[0] = 1, nodes[1] = 1;


		for (int i = 2; i <= n;i++) {

			for (int j = 0; j < i;j++) {

				nodes[i] += nodes[j] * nodes[i - j - 1];

			}
		}

		return nodes[n];

	}
};
```
