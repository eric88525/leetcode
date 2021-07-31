class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        back(nums, temp, 0 );
        return ans;
    }
    
    void back( vector<int>& nums  ,vector<int>& temp , int level  ){
        
        if(level == nums.size()){
            ans.push_back(temp);
            return ;
        }
        
        back( nums , temp  , level+1);     
        temp.push_back(nums[level]);
        
        back( nums , temp  , level+1);      
        temp.pop_back();
         
    }
};