class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {   
        vector<int> temp;      
        backTracking( 0 , candidates , target  , temp );
        return ans;
    }
    
    
    void backTracking( int left  , vector<int>& candidates,  int target , vector<int> & temp  ){
        
        if(target == 0){
            ans.push_back(temp);
        }else{
            for(int i=left;i<candidates.size();i++){
                if(candidates[i]<= target){
                    temp.push_back(candidates[i]);
                    backTracking(  i ,candidates ,target - candidates[i] ,temp );
                    temp.pop_back();
                }      
            }            
        } 
    }
  
};