class Solution {
public:

	vector<int> topKFrequent(vector<int>& nums, int k) {

		unordered_map <int, int> table;

		for (auto i : nums) {
			table[i]++;
		}

		vector< pair<int, int> > ans;

		for (auto item : table) {
			ans.push_back(make_pair(item.first, item.second));
		}

		sort(ans.begin(), ans.end(), [](pair<int, int>a, pair<int, int> b) { return a.second < b.second; });

		vector<int> result;

		for (int i = ans.size() - 1; k > 0; k--, i--) {
			result.push_back(ans[i].first);
		}

		return result;
	}

};