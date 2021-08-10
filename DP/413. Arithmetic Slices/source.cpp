class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {

		if (nums.size() < 3) return 0;

		vector<int> dp(nums.size());

		int temp = 0, total = 0;

		for (int i = 2; i < nums.size(); i++) {
            
			if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
				dp[i] = temp + dp[i - 1] + 1;
				temp++;
			}
			else {
				total += dp[i - 1];
				temp = 0;
			}
		}
		return total + dp[nums.size() - 1];
	}
};