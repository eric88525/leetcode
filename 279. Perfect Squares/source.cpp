class Solution {
public:
	int numSquares(int n) {

		if (n < 0) return 0;
		vector<int> table(n+1, 0);
        
		for (int i = 1; i <= n;i++) {	          
            int temp = INT_MAX;           
			for (int j = 1; j*j <= i;j++ ) {                  
                temp = min( temp , table[i-j*j] +1);                  
			}
            table[i] =temp;
		}
		return table[n];
	}
};
