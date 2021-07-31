# 78. Subsets
在當下的階段，可以選擇要不要把數字加入，進行兩次backTracking就好

需要pop_back是因為這邊用 & 來傳遞參數，不用&的話就不用pop back ，只是這樣會比較慢

```c++
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
```
