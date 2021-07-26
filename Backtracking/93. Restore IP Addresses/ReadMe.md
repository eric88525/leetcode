# 93. Restore IP Addresses

問題很簡單，找出 4個 (1-3) 的排列組合

每次都去檢查IP是否合格就好

```c++
class Solution {
public:

	vector<string> ans;

	vector<string> restoreIpAddresses(string s) {
        
        // 100% invalid
        if(s.size()>12) return ans;     
    
		DFS(s, "" , 1);    
        
		return ans;

	}

	void DFS(string ip, string s , int c) {
		// c = 第幾個位置
		if ( c == 4 ) {

			if ( !isValid(ip)) return;
			
			ans.push_back(s + ip);
			return;
		}
		for (int i = 1; i <= 3; i ++) {           
    		string temp = ip.substr(0, i);
			if (  ip.size() < i  || !isValid(temp)) return;
			DFS(   ip.substr(i)  , s + temp + ".", c + 1);
		}   
	}

	bool isValid(string s) {
        // 避免 0 開頭數字發生
		if (s.size() > 1 && s[0] == '0' || !s.size()) return false;
		if (stoi(s) > 255) return false;
        
		return true;
	}
};

```

