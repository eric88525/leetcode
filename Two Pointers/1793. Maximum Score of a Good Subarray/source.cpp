class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {

        int max_score = 0;

        int min_num = 0;

        int left = k, right = k;

        int count = 1;

        while (left >= 0 && right < nums.size())
        {

            int min_num = min(min_num, min(nums[left], nums[right]));
            max_score = max(min_num * int(right - left + 1), max_score);

            if (left == 0)
            {
                right++;
            }
            else if (right == nums.size() - 1)
            {
                left--;
            }
            else if (nums[left - 1] < nums[right + 1])
            {
                right++;
            }
            else
            {
                left--;
            }
        }
        return max_score;
    }
};
