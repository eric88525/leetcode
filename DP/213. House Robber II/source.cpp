class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        else if(nums.size()==1) return nums[0];
        else if(nums.size()==2) return max(nums[0],nums[1]);
        
        return max(  helper(nums,0,nums.size()-2)  , helper(nums,1,nums.size()-1)   );
    }
    
    
    int helper( vector<int>& nums , int lo , int hi){    
        int p1= nums[lo] ,p2=0,curr=0;
        
        for(int i=lo+1; i<= hi;i++){  
            curr = max(nums[i]+p2 , p1);
            p2 = p1;
            p1 = curr;           
        }
        return curr;
    }
};