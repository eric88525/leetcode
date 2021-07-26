class Solution {
public:

	vector<vector<int>> ans;

	vector<vector<int>> permute(vector<int>& nums) {

		DFS(0, int(nums.size()) - 1, nums);

		return ans;
	}


	void DFS(int left, int right, vector<int> nums) {

		if (left == right) {
			ans.push_back(nums);
		}else{
            for (int i = left; i <= right; i++) {
                swap(nums[i], nums[left]);
                DFS(left + 1, right, nums);
                swap(nums[i], nums[left]);
            }            
        }
	}
};