class Solution {
public:
	vector<int> diffWaysToCompute(string expression) {
		vector<int> res;
		for (int i = 0; i < expression.size(); i++) {

			char c = expression[i];

			if (c == '*' || c == '-' || c == '+') {
				// cut str from 0 to i 
				vector<int> left = diffWaysToCompute(expression.substr(0, i));
				// i+1 to end
				vector<int> right = diffWaysToCompute(expression.substr(i + 1));

				for (auto l : left) {
					for (auto r : right) {
						switch (c) {
						case '+':
							res.push_back(l + r);
							break;
						case '-':
							res.push_back(l - r);
							break;
						case '*':
							res.push_back(l*r);
							break;
						}
					}
				}
			}
		}
		// 代表傳入純數字
		if (res.empty()) { res.push_back(stoi(expression)); }
		return res;
	}
};