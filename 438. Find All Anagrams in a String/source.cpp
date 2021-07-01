class Solution {
public:
	vector<int> findAnagrams(string s, string p) {

		// p_seen: 要求
		// s_seen: 在s裡面看過的
		vector<int> p_seen(26, 0), s_seen(26, 0), ans;

		// 題目有故意搞事情
        if (p.size() > s.size())return ans;

		for (int i = 0; i < p.size(); i++) {
			p_seen[p[i] - 'a']++;
			s_seen[s[i] - 'a']++;
		}

		if (p_seen == s_seen) ans.push_back(0);


		for (int i = p.size(); i < s.size(); i++) {

			// +新看到文字 -舊的文字
			s_seen[s[i] - 'a'] ++;
			s_seen[s[i - p.size()] - 'a'] --;

			// 加入答案
			if (p_seen == s_seen) ans.push_back(i - p.size()+1);

		}
		return ans;
	}
};