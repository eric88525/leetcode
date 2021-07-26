# solution

### 大神方法 98%

```c++
string frequencySort(const string& s) {
    
    // z 的ascii是 122
	vector<string> v(123);
    
    // 把char加入各自的格子
	for (auto i : s) { 
		v[i] += i;
	}
    // 排序 出現次數多的字符會在上面
	sort(v.begin(), v.end(), [](const string& s1, const string& s2) {return s1.size() > s2.size(); });
    
	string res;
    // 組出答案
	for (auto i : v) res += i;
	return res;
}
```
###  一般sort 80%
```c++
class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map <char, int> table;
        
        for (auto i : s) {
    		table[i]++;
    	}
        
        vector< pair<char, int> > ans;
    
        for (auto item : table) {
    		ans.push_back(make_pair(item.first, item.second));
    	}
        // 紀錄pair ( char , char出現次數 )
        sort(ans.begin(), ans.end(), [](pair<char, int>a, pair<char, int> b) { return a.second > b.second; });
    
        string result="";
        
        for(auto item: ans){
           // 重組字符
           result += string( item.second, item.first);
 }
        
        return result;
    }
};
```


