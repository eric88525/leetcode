class MapSum {
public:
	/** Initialize your data structure here. */

	unordered_map<string, int> data;


	MapSum() {

	}

	void insert(string key, int val) {
		data[key] = val;
	}

	int sum(string prefix) {
		int s = 0;
		for (auto &i : data) {
			if (int(i.first.find(prefix)) ==0) {
				s += i.second;
			}

		}
		return s;
	}
};
