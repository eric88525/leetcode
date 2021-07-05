# solution

## s1

建立 map <  數字 , 出現次數  >

然後轉成 pair 去排序，回傳最後幾個就是答案

這個比較快

# s2

用bucket的方式，桶子編號為出現次數，桶子裡面放 <出現的數字>

```c++
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map <int, int> table;
		for (auto i : nums) {
			table[i]++;
		}
		vector< vector< int > > buckets(nums.size() + 1 );
		for (auto item : table) {
			buckets[item.second].push_back(item.first) ;
		}
		vector<int> result;
		for (int i = buckets.size()-1; k>0 ;i--) {
			if (buckets[i].empty()) continue;

			result.insert(result.begin() ,  buckets[i].begin(),buckets[i].end() );
			if (result.size() == k) break;
		}
		return result;
	}
};
```



