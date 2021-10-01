# 698. Partition to K Equal Sum Subsets

 + 用 visited 來紀錄當下情況中,已經看過多少數字
 + backtrack 每次都會嘗試加入數字 j,進行下次backtrack,結束後會恢復,並嘗試其他數字可能性
 + 如果數字已經看過,或是數字超過->跳過

```c++
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) return false;
        
        vector<int> visited(nums.size(), false);
        
        return backtrack(nums, visited, sum / k, 0, 0, k);
        
    } 
    bool backtrack(vector<int>& nums,vector<int>& visited, int target, int curr_sum, int i, int k) {
        if (k == 0) 
            return true;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
            visited[j] = false;
        }   
        return false;
    }
};

```
