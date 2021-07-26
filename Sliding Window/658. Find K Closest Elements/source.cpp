class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {

		int window_sum = 0;
		int closest_end = k-1;

		for (int i = 0; i < k; i++) {
			window_sum += abs(arr[i] - x);
		}

		for (int i = k; i < arr.size(); i++) {
			if (abs(arr[i] - x) < abs(arr[i - k] - x) ||
				((abs(arr[i] - x) == abs(arr[i - k] - x)) && arr[i] < arr[i - k])) {
				closest_end = i;
			}
		}
		
		arr.assign(arr.begin() + (closest_end-k+1), arr.begin() + (closest_end+1));
		return arr;
	}
};
