# 300. Longest Increasing Subsequence

This problem can be solved by patience sort or DP.

## DP

DP[i] = max ( DP[j] + 1) , where j < i and  nums[j] < nums[i]

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {   
        
        vector<int>dp(nums.size(),1);     
        int max_v=0;
        
        for(int i=0;i<dp.size();i++){          
            for(int j=0;j<i;j++){             
                if ( nums[i] > nums[j]){
                    dp[i] =  max( dp[i] , dp[j] + 1);
                }                
            } 
            max_v = max(max_v ,dp[i]);
        }
        

        return max_v;
    }
};
```

## Patience Sort

https://www.youtube.com/watch?v=22s1xxRvy28&ab_channel=StableSort

```c++
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {

		vector<int> patient_sort;

		for (auto n : nums) {

			auto it = lower_bound(patient_sort.begin(), patient_sort.end(), n);

			if (it == patient_sort.end()) {
				patient_sort.push_back(n);
			}
			else {
				*it = n;
			}

		}
		return patient_sort.size();
	}
};
```

