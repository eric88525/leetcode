class Solution {
public:

	vector<string> ans;

	vector<string> restoreIpAddresses(string s) {
        
        if(s.size()>12) return ans;     
        
		DFS(s, "" , 1);    
        
		return ans;

	}

	void DFS(string ip, string s , int c) {

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
        
		if (s.size() > 1 && s[0] == '0' || !s.size()) return false;
		if (stoi(s) > 255) return false;
        
		return true;
	}
};
