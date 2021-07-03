class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
	{

		int maxSum = INT_MIN, col = matrix[0].size(), row = matrix.size();

		for (int L = 0; L < col; L++) {

			vector<int> tempCol(row, 0);
			for (int R = L; R < col; R++) {

				// 將直行數值 加入倒合計數值
				for (int i = 0; i < row; i++) {
					tempCol[i] += matrix[i][R];
				}

				// 找到直行的最大和
				int colMax = findMaxInArr(tempCol, k);

				maxSum = max(maxSum, colMax);
			}
		}
		return maxSum;
	}


	// 在arr中 找到< k 的最大合計
	int findMaxInArr(vector<int> arr, int  k) {


		int maxSum = INT_MIN, currentSum = 0;

		// 紀錄從頭看到尾  每階段的合計數值
		set<int> pastSum;
		pastSum.insert(0);


		for (int i = 0; i < arr.size(); i++) {

			// 當下階段看到的總和
			currentSum += arr[i];

			set<int>::iterator it = pastSum.lower_bound(currentSum - k);

			if (it != pastSum.end()) {
				maxSum = max(maxSum, currentSum - *it);
			}
			pastSum.insert(currentSum);
		}
		return maxSum;
	}
};
