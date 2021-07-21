class Solution {
public:

	map<char, string> keyboard;

	vector<string> letterCombinations(string digits) {

        if(digits=="") return vector<string>({});
        
		vector<string> ans;
		keyboard['2'] = "abc";
		keyboard['3'] = "def";
		keyboard['4'] = "ghi";
		keyboard['5'] = "jkl";
		keyboard['6'] = "mno";
		keyboard['7'] = "pqrs";
		keyboard['8'] = "tuv";
		keyboard['9'] = "wxyz";
		string temp = "";
		letterDFS(digits, temp, ans);
		return ans;
	}

	void letterDFS(string digits, string s, vector<string> & result) {
		if (!digits.size()) {
			result.push_back(s);
			return;
		}
		char x = digits[0];
		for (auto c : keyboard[x]) {
			letterDFS(digits.substr(1), s + c, result);
		}
	}

};