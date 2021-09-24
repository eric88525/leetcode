# 282. Expression Add Operators

+ 透過 recursion 來找出所有的數字符號組合

+ 每次當下的數值範圍為 pos 到 pos + N

+ 用 multed 來記錄前一個數字:
  + 如果前一個數字為  1 + 2 ， 那麼這個multed 就是 +2

  + 如果前一個數字為  1 - 80， 那麼這個multed 就是 -80
  + 遇上乘法時，做對應動作

```c++
class Solution {
public:

	vector<string> ans;
	int ans_target;


	vector<string> addOperators(string num, int target) {
		ans_target = target;
		helper(num, "", 0, 0 ,0);
		return ans;
    }
	void helper(string num, string temp, long pos, long currNum , long multed) {

		if (pos == num.size()) {
			if (currNum == ans_target) {
				ans.push_back(temp);
			}
		}else{
            for (int i = pos; i < num.size(); i++) {
                // 如果數字的開頭是0 捨棄
                if (i != pos && num[pos] == '0') break;
                
                string curr_string = num.substr(pos, i - pos + 1);
                
                // 目前的數字 POS ~ i
                long curr = stol(curr_string);
                if (pos==0) {
                    helper(num, temp + curr_string, i + 1, curr  , curr);
                }
                else {
                    helper(num, temp + "+" +curr_string, i + 1,  currNum + curr , curr);
                    helper(num, temp +"-" +curr_string, i + 1, currNum - curr ,-curr);
                    helper(num, temp + "*"+ curr_string, i + 1, currNum-multed+ multed*curr, multed*curr);
                }
            }            
        }
	}
};
```

