class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {

		int left = 0, right = nums.size() - 1, mid;

		while (left < right) {

			mid = left + (right - left) / 2;
            bool odd = mid%2;
            
            if( nums[mid] == nums[mid+1] ){
                if(odd) right = mid -1;
                else left = mid + 2;
                
            }else  if( nums[mid] == nums[mid-1]) {
                if(odd) left = mid + 1;
                else right = mid -2;
            }else{
                return nums[mid];
            }       
		}
        return nums[left];	
	}
};

