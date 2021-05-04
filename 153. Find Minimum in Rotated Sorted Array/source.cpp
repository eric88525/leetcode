class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left=0,right=nums.size()-1;
        
      
        // 代表根本沒換過順序 由小到大
        if (nums[right] > nums[left])
        {
            return nums[0];
        }
      
        // 想辦法找到 最小和最大的分界
        while(left < right){
            
            int mid = (left + right) / 2;
            // 中數 > 最左邊:小的在右邊
            // 往右搜索
            if(nums[mid] >= nums[0]){
                left = mid+1;
            // 中數 < 左邊: 小的在中數或中數左邊
            // 往左搜索
            }else{
                right = mid;
            }          
        }
        return nums[left];
    }
};
