# 279 perfect squares

dynamic programing

> 此題希望找出 N 是由那些數字的平方所組合成的(最小數字數量)

+ N=1
  
  + 1^1 => 1  
  + perfect_squares(N)=1
+ N=2
  
  + 1^1 + 1^1 
  + perfect_squares(N)=2
+ N=3
  
  + 1^1 + 1^1 + 1^1 
  + perfect_squares(N)=3

進一步觀察，當 N=3，我們可以試圖讓他減去  i 平方，( i*i <= N )
  + 問題會變成:
      + when i=1 ,  ANS = 1 + perfect_squares(N-i * i) = 1 +   perfect_squares(N-i * i) = 1 + PS(2)

> CODE

程式可以由1開始建構DP表格

```c++
class Solution {
public:
	int numSquares(int n) {

		int c = 0;
		if (n < 0) return 0;

		vector<int> table(n + 1, 10);
		table[0] = 0;
		// 由1開始建構DP表格
		for (int i = 1; i <= n; i++) {
            // 在建構 table(i)時，嘗試減去比 i 小的平方並找出最小組和數
 			int temp = INT_MAX;           
			for (int j = 1; j*j <= i;j++ ) {                  
                temp = min( temp , table[i-j*j] +1);                  
			}
            table[i] =temp;
		}
		return table[n];

	}
};
```

  
