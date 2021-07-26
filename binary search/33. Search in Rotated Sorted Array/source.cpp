class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left=0;
        int right=nums.size()-1;
        int mid;
        
        if (nums.size()==0) return -1;
        
        while (left<right)
        {
            mid = left+(right-left)/2;            
            if (nums[mid]==target) return mid;  
            // in thesame area
			// [5] 6 [7] 1 2 [3]  
			// [5] 6 [1] 2 3 [4]
            if (nums[left]<=nums[mid] && nums[left]<=target || nums[left]>nums[mid] && nums[left]>target) 
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]<=nums[mid] && nums[left]>target) //diff area
                left = mid+1;
            else if (nums[left]>nums[mid] && nums[left]<=target) //diff area  
                right = mid;                
        }
        
        if (nums[left]==target) 
            return left;
        else 
            return -1;
        
    }
};