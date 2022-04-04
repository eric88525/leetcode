class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while (right >= mid)
        {
            if (nums[mid] == 2)
            {
                swap(nums[mid], nums[right--]);
            }
            else if (nums[mid] == 0)
            {
                swap(nums[mid], nums[left++]);
                mid = left;
            }
            else
            {
                mid++;
            }
        }
    }
};
