class Solution {
public:
	vector<int> partitionLabels(string s) {

		// save the end point of every character
		vector<int> endIndex(26, -1);

		for (int i = 0; i < s.size(); i++) {
			endIndex[s[i] - 'a'] = i;
		}

		int end = -1, lastEnd = 0;
		vector<int> ans;


		for (int i = 0; i < s.size(); i++) {
			// upload end position
			end = max(end, endIndex[s[i] - 'a']);

			// i is at end point (the end of a parts)
			if (i == end) {
				ans.push_back(end - lastEnd + 1);
				lastEnd = end+1;
			}
		}
		return ans;
	}
};