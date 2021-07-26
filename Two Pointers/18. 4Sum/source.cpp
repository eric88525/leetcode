class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)     {
        
        sort( nums.begin(),nums.end()); 
        
        vector<vector<int>> result;
        
        for (int i=0;i<nums.size();i++){
            
            // check what we still need 
            auto remain_num = target - nums[i];
            
            // call function to solve this
            vector<int> remain_vector( nums.begin()+i+1 ,nums.end() );
            
            auto possible = threeSum( remain_vector ,   remain_num );
            
            // add to result
            for(auto p : possible){    
                p.insert( p.begin() , nums[i]  );
                result.push_back(  p );
            }
            
            while(i+1<nums.size() and nums[i] == nums[i+1]) i++;
        }
        return result;
        
    }
    // edit from question 3sum
    vector<vector<int>> threeSum(vector<int>& nums , int target) {        
        vector<vector<int>> result ;      
        
        for (auto i=0;i<nums.size();i++){      
            auto _target = target-nums[i];         
            auto start = i+1;
            auto end = nums.size()-1 ;      
            while(start < end){
                int sum = nums[start] + nums[end]  ;
                if ( sum < _target ){
                    start++;
                }else if (sum > _target){
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
