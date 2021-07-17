class Solution {
public:

	int dotsNum;
	int findCircleNum(vector<vector<int>>& isConnected) {

		// how many dots
		dotsNum = isConnected.size();
		int groups = 0;   
		vector<int> visited(dotsNum,0);
        
		for (int i = 0; i < dotsNum; i++) {
			if (!visited[i]) {
                findRelation(isConnected, i , visited);
			    groups++;
            } 
		}
		return groups;
	}
	void findRelation(vector<vector<int>>& isConnected, int d , vector<int> &visited) {	
       
		visited[d] = 1;
      
		for (int i = 0; i < dotsNum; i++) {
			if ( visited[i]  ||  !isConnected[d][i]  ) continue;
			findRelation(isConnected, i , visited);
		}
	}
};