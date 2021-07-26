class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        vector<vector<int>> result ;      
        sort( nums.begin(),nums.end()); 
        for (auto i=0;i<nums.size();i++){      
            auto target = -nums[i];         
            auto start = i+1;
            auto end = nums.size()-1 ;      
            while(start < end){
                int sum = nums[start] + nums[end]  ;
                if ( sum < target ){
                    start++;
                }else if (sum > target){
                    end--;
                }else{
                    vector<int> temp = {  nums[i] , nums[start] , nums[end] };
                    result.push_back(temp);
                    while( start < end && nums[start] == temp[1] ) start ++;
                    while( start < end && nums[end] == temp[2] ) end --;     
                }               
            }
            while( i+1< nums.size() && nums[i] == nums[i+1]) i++;  
        }
        return result;
    }    
};

