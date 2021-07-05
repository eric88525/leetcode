# solution

首先建立一個表，裡面紀錄每個字母前面能出現誰

a e i o u 用 0,1,2,3,4 代表

| a     | e    | i    | o    | u    |
| ----- | ---- | ---- | ---- | ---- |
| e,i,u | a,i  | e,o  | e    | i,o  |

```c++
vector<vector<int>> canFollow = { {1,2,4},{0,2},{1,3},{2},{2,3} };
```



接著按照以下規則:

+ 當下字母的出現組合，須由前一狀態的字母組合累積而成
+ 例如: 前一狀態 a 有 3種組合 ，  i 有 2種組合，那麼當下狀態的e會有 3+2種組合

```c++
while(--n){
	pre_combination = all_combination;
	for(int i=0;i<5;i++){
		all_combination[i] = 0;
		for(auto &pattern:canFollow[i] ){
			all_combination[i] += pre_combination[pattern]  ;
			all_combination[i] %= fixer;
		}        
	}
} 
```
示範:

![]()



## 補充

https://www.zhihu.com/question/49374703

裡面講了大數運算為何需要 % 1e+7