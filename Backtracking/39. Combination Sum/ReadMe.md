# 39. Combination Sum

backtracking

題目說可以重複數字，那就讓下一個backTracking 從 i開始

記得要回收數字

```c++
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
```