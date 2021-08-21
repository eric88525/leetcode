# 376. Wiggle Subsequence

+ 用down[i] & up[i] 來記錄最後2個數字為上升或下降的序列，在 i 點的最大長度
+ 當 num[i] > num[i -1]
  + 更新 up[i] 為 down[i-1] + 1
  + up[i] 不動 ， 複製
+ 當 num[i] == num[i-1]
  + 不動，完全複製

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return 0;
        }
        vector<int> up(size, 0);
        vector<int> down(size, 0);

        up[0]=1;
        down[0]=1;
        
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]>nums[i-1]){
                up[i] = down[i-1]+1; 
                down[i] = down[i-1];
            }else if(nums[i]<nums[i-1]){
                down[i] = up[i-1]+1;
                up[i] = up[i-1];
            }else{
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(up[size-1], down[size-1]);
        
    }
};
```

