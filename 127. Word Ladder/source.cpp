class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{

		unordered_set<string> dictionary(wordList.begin(), wordList.end());
        if (!dictionary.count(endWord)) return 0;
        
		queue<string> words;
		words.push(beginWord);

		int ans = 0;

        string curr="",temp="";
        
		while (!words.empty()) {
			int b_size = words.size();
			ans++;
			for (int b = 0; b < b_size; b++) {
				curr = words.front(), temp = "";
				words.pop();
				for (int i = 0; i < curr.size(); i++) {
					temp = curr;
					for (int c = 0; c < 26; c++) {
						temp[i] = char('a' + c);
						if (temp == endWord) return ans + 1;
						if (dictionary.count(temp) ) {
							words.push(temp);
							dictionary.erase(temp);
						}
					}
				}
			}
		}
		return 0;
	}
};
