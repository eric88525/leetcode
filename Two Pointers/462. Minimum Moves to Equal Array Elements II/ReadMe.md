# 462. Minimum Moves to Equal Array Elements II

這題概念很簡單，找中位數

- 如果 nums 有奇數個
  - 找到中位數，把所有數字移過去
- 如果 nums 有偶數個
  那麼解答為 x，且小於 x 的數字數量等於>x 的數字數量

- 不論如何，步數都是最右邊-最左邊

```c++
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int ans = 0;
        sort(nums.begin(),nums.end());

        for(int i=0,j=nums.size()-1  ;  i<j    ; i++,j--  ){
            ans += nums[j] - nums[i];
        }

        return ans;
    }
};
```
