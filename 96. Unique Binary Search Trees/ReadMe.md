# 96. Unique Binary Search Trees

+ binary search tree

count BST possibles

https://www.youtube.com/watch?v=YDf982Lb84o&ab_channel=TusharRoy-CodingMadeSimple

## 概念

在計算 root = n 有多少種組合 ，方法為 **n左邊node的組合數** 乘上 **右邊node的組合數**

因為BST特性， n 左邊的node都小於n ， 右邊的node都大於n，並不會有交集或替換可能。

## 當 n=2時

先設定初始 

NODES(0) : 沒點組合1種

NODES(1) = 1 ，1點組合1種

假設數字為 10 11:

+ 10 as root : 左邊沒點，右邊1點-> NODES(0) * NODES(1)
+ 11 as root:  左邊1點，右邊沒點 -> NODES(1) * NODES(0)
+ NODES(0) * NODES(1) + NODES(1) * NODES(0) = 1 * 1 + 1 * 1 = 2

## 當n=3

if node is 10 11 12

+ 10 as root :   NODES(0) * NODES(2)
+ 11 as root:    NDOES(1) * NODES(1)
+ 12 as root:    NODES(2) * NODES(0)

## 規律

可以發現:

leftIndex 會從 0 ~ n-1，右邊index為 n - leftIndex -1

```c++
for (int i = 2; i <= n;i++) {
	for (int j = 0; j < i;j++) {
        int left = j, right = i - j - 1;
		nodes[i] += nodes[j] * nodes[i - j - 1];
    }
}
```

