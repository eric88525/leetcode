# 547. Number of Provinces
DFS

在看那些點有關連時，從最前面的點開始找，每當有新的關連出現，搜尋新點的所有關連

```c++
class Solution {
public:

	int dotsNum;
	int findCircleNum(vector<vector<int>>& isConnected) {

		// how many dots
		dotsNum = isConnected.size();
        
		int groups = 0;   
        // 有關連的點就不用再搜尋一次
		vector<int> visited(dotsNum,0);
        
		for (int i = 0; i < dotsNum; i++) {
			if (!visited[i]) {
                findRelation(isConnected, i , visited);
			    groups++;
            } 
		}
		return groups;
	}
    
	void findRelation(vector<vector<int>>& isConnected, int d , vector<int> &visited){
        // 把所有跟D有關係的點做標記
		visited[d] = 1;    
		for (int i = 0; i < dotsNum; i++) {
			if ( visited[i]  ||  !isConnected[d][i]  ) continue;
			findRelation(isConnected, i , visited);
		}
	}
};
```

