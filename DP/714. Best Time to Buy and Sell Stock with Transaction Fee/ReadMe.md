# 714. Best Time to Buy and Sell Stock with Transaction Fee


+ create 2 state machine , buy and sell
+ the buy represent the money after  buying  stock 
+ the sell represent the money after selling  stock 

```c++
class Solution {
public:
    int maxProfit(vector<int>& P, int F) {

        int buy = -P[0], sell=0;     
       
        for(int i=1;i<P.size();i++){  
            
            int todaybuy = max(buy , sell - P[i] );
            int todaysell = max(sell , buy-F+P[i]);
            
            buy = todaybuy;
            sell = todaysell;
        }
        return max(buy,sell);
    }
};
```

