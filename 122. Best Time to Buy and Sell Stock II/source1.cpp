class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int  earn=0;

		// 只要有價差 馬上收割
		for (int i = 1; i < prices.size(); i++) {

			if (prices[i] > prices[i-1]) {
                
                earn += prices[i]-prices[i-1];
            }
				
		}
		return earn;
	}
};
