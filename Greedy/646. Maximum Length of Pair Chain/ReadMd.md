# 646. Maximum Length of Pair Chain

+ 用意是希望能找出array內最大 的chain，chain規則:  pair_a[1] < pair_b[0]

+ 如果要找出最大的chain，我們勢必讓裡面的每個 pair 尾端越小越好(因為要是數值太大根本沒人接得上) 
+ 先用 pair[1] 做升排序 ， 再用greedy 依照條件蒐集就好

```c++
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
           
        // call by reference is important! speed up 4X
        sort(  pairs.begin() , pairs.end() , [](vector<int>&a,vector<int>&b){     
            return a[1]<b[1];          
        }  );
        
        int ans=0,last_end=INT_MIN;
         
        // GREEDY
        for(auto x:pairs) {        
            if (x[0] >last_end ){
                last_end = x[1];
                ans++;     
            }    
        }    
        return ans;        
    }
};
```

