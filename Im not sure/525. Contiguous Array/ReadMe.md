# 525

+ 先設定一變數，當遇到0就減去一，遇到1就+1。

+ 如果在陣列中，遇到某段有相同數量的0和1的subarray後，數值應該會和遇到前一樣。

  

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int maxLen = 0;  
        map<int,int>seen;
        seen[0] = -1;
        int curr = 0;
        
        for(int i=0;i<n;i++){     
            if(nums[i]==1)curr++;
            else curr--;  
            
            if(seen.count(curr)){
                //cout << i <<" "<<seen[curr]<<endl;
                maxLen = max(maxLen,i-seen[curr]);
            }else{
                seen[curr] = i;
            }     
        }
        return maxLen;
    }
};
```

