class Solution {
public:
	bool search(vector<int>& nums, int target) {


		int left = 0, right = nums.size() - 1, mid = 0;

		if (target == nums[mid]) return true;

		while (right >= left) {
            
            // check mid
			mid = (left + right) / 2;
			if (nums[mid] == target) return true;

            
            // 左邊有排序
			if (nums[left] < nums[mid]) {
				// 看他是不是在左半部
				if (nums[left] <= target && target < nums[mid]) {
					right = mid -1;
				}
				else {
					left = mid + 1;
				}

			//重複的東西 目標應該在左半部 
			}else if ( nums[left] == nums[mid] ){
                
                left++;         
            // 右邊有排序
			}else{
				//確認目標有沒有在右邊
           		if (nums[mid] < target  && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid -1;
				}
            }
		}
		return false;
	}
};