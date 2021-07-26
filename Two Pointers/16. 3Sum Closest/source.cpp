class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        auto closet = 10000;
        auto most_close = 10000;
        int ans = target;
        
        for ( auto i=0;i<nums.size();i++){
            
            auto remain = target - nums[i];     
            
            auto start = i+1;
            auto end= nums.size()-1;       
            
            while( start < end ){
                
                auto sum = nums[start] + nums[end];
                
                if ( abs( remain - sum ) < most_close ){
                    most_close = abs( remain - sum );
                    ans = sum + nums[i];
                }
                           
                if ( sum < remain) start++;
                
                else if ( sum > remain) end--;
                  
                else return target;     
                
            }         
        }
        return ans;
    }
};
