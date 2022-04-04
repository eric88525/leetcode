# 15. 3Sum

+ 先把所有數值排序(小>大), 讓i從頭跑到尾

+ when i=0:
  + 看後面哪2個數值能和nums[i]合為0 , 用start , end 來記錄最大和最小數值
  + 當合不夠時，調整start 反之end
  + 當合為0時，加入到答案，並且把start和end的位置調整，避免重複答案出現

結束後，調整i位置，假設有[0,1,1 ] ，那麼最後一個1會忽略

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size();i++){
            
            int need = -nums[i];
            
            int start = i+1, end = nums.size()-1;
            
            while(start < end){
                int sum = nums[start] + nums[end];
                if(sum < need){
                    start++;
                }else if(sum>need){
                    end--;
                }else{
                    vector<int> temp = {nums[i] , nums[start] , nums[end]};
                    ans.push_back(temp);
                    
                    while(start<end && nums[start] == temp[1]){
                        start++;
                    }
                    while(start<end && nums[end] == temp[2]){
                        end--;
                    }
                }
            }
            while( i+1<nums.size() && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};

```

