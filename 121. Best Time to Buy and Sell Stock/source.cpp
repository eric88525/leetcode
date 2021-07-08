class Solution {
public:

    //想辦法找到最大差價
    
    int maxProfit(vector<int>& prices) {
               
        int minPrice = prices[0] , maxPrice=0;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i] <  minPrice ){
                minPrice = prices[i];
            }else{
                maxPrice = max( maxPrice , prices[i] - minPrice   ) ;  
            }
        }
        return maxPrice;
    }
};

