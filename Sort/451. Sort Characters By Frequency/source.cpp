class Solution
{
public:
	string frequencySort(const string &s)
	{

		// z 的ascii是 122
		vector<string> v(123);

		// 把char加入各自的格子
		for (auto i : s)
		{
			v[i] += i;
		}
		// 排序 出現次數多的字符會在上面
		sort(v.begin(), v.end(), [](const string &s1, const string &s2)
			 { return s1.size() > s2.size(); });

		string res;
		// 組出答案
		for (auto i : v)
			res += i;
		return res;
	}
};
