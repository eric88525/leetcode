
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int row = matrix.size(), col = matrix[0].size();
        int left = matrix[0][0], right = matrix[row - 1][col - 1], mid;

        while (left <= right) {

            mid = (left + right) / 2;

            // 找到lessThanMid:  小於等於lessThanMid的數字剛好等於K個
            int lessThanMid = 0;

            for (int i = 0; i < row; i++)
            {
                lessThanMid += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (lessThanMid < k) {
                left = mid +1 ;
            }
            else{
                right = mid -1 ;
            }

        }
        return left;
    }
};