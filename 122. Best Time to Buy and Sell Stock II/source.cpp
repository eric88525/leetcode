class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int lowPrice = prices[0], highPrice = prices[0], earn=0;

		for (int i = 1; i < prices.size(); i++) {

			// 當價格大於高點 更新
			if (prices[i] > highPrice) {
				highPrice = prices[i];
			}
			// 當價格掉下來 收取波段收益
			else if (prices[i] < highPrice) {
				earn += max(0, highPrice - lowPrice);
				lowPrice = prices[i];
				highPrice = prices[i];
			}
		}
		// 結算最後一天
		earn += max(0, highPrice - lowPrice);
		return earn;
	}
};
