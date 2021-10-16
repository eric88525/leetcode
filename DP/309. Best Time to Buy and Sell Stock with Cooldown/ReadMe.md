# 309. Best Time to Buy and Sell Stock with Cooldown

+ 用狀態機來記錄第i天的最大收益
+ s0 = 冷卻   買入後變  s1  賣出後變 s2

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()<=1) return 0;
        
        vector<int> s1(prices.size(),0);
        vector<int> s2(prices.size(),0);
        vector<int> s0(prices.size(),0);

        s1[0] = -prices[0];
        s0[0] = 0;
        s2[0] = INT_MIN;
               
        for(int i =1;i<prices.size();i++){    
            s0[i] = max( s2[i-1] , s0[i-1]  );
            s1[i] = max( s1[i-1],s0[i-1]-prices[i] );
            s2[i] = s1[i-1] + prices[i];
        }     
        return max( s0[prices.size()-1] , s2[prices.size()-1] );     
    }
};
```

