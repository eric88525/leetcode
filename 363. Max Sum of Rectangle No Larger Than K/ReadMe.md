# solution

# 觀念

會用到兩個觀念，第一個是 **在1D arr中 ，如何找到最大合計的subarray**

第二個是，如何套用到 2D矩陣裡面。

https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references

已有相關連結

# Code

+ 找出在1D arr中 ，如何找到 < K 的subarray

```c++
int findMaxInArr(vector<int> arr, int  k) {
 
	int maxSum = INT_MIN, currentSum = 0;
    
 	// 將每階段 i 看到的總和記錄下來
	set<int> pastSum;
	pastSum.insert(0);
    
	for (int i = 0; i < arr.size(); i++) {
        
 		// 目前看過數字的總和
		currentSum += arr[i];
        
        // 找出過去累積數值中，是從哪開始超過的
		set<int>::iterator it = pastSum.lower_bound(currentSum - k);
 
		if (it != pastSum.end()) {
            // 如果有數值超過需要的，那就把它刪掉，並比對最大值
			maxSum = max(maxSum, currentSum - *it);
		}
		pastSum.insert(currentSum);
	}
	return maxSum;
}
```

![](https://github.com/eric88525/leetcode/blob/main/363.%20Max%20Sum%20of%20Rectangle%20No%20Larger%20Than%20K/%E5%9C%96%E8%A7%A3.png)

+ 全部掃一遍

```c++
int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
 
	int maxSum = INT_MIN, col = matrix[0].size(), row = matrix.size();
 
	for (int L = 0; L < col; L++) {
 
		vector<int> tempCol(row, 0);
		for (int R = L; R < col; R++) {
 
			// 將直行數值 加入合計數值
			for (int i = 0; i < row; i++) {
				tempCol[i] += matrix[i][R];
			}
			// 找到直行的最大和
			int colMax = findMaxInArr(tempCol, k);
			maxSum = max(maxSum, colMax);
		}
	}
	return maxSum;
}
```

## 補充

- lower_bound

  ：找出vector中「大於或等於」val的「最小值」的位置：

  - auto it = **lower_bound**(v.begin(), v.end(), val);

- upper_bound

  ：找出vector中「大於」val的「最小值」的位置：

  - auto it = **upper_bound**(v.begin(), v.end(), val);

