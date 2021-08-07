class Solution {
public:

	int  minCut(string s) {

		int n = s.size();
		vector<vector<bool>> dp = vector<vector<bool>>(n , vector<bool>(n ,false));
		vector<int> dp_min = vector<int>(n);

		for (int i = 0; i < n; ++i) {
			dp_min[i] = i;
			for (int j = 0; j <= i;++j) {
				if (  s[i] == s[j]  && (  j + 1 > i - 1  || dp[j + 1][i - 1]  )  ) {
					dp[j][i] = true;
					dp_min[i] = j == 0 ? 0 : min( dp_min[i] , dp_min[j-1] +1);
				}
			}
		}
		return dp_min[n - 1];
	}
};