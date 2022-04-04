## point

- 用左右中指針來記錄位置

- 當中間的數 > 最左邊時:

  - 小的數在右邊 > 往右搜索

- 當中數 < 最左邊:
  - 最小數在左邊 > 往左搜索

```cpp
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        // 代表根本沒換過順序 由小到大
        if (nums[right] > nums[left])
        {
            return nums[0];
        }

        // 想辦法找到 最小和最大的分界
        while (left < right)
        {

            int mid = (left + right) / 2;

            if (nums[mid] >= nums[0])
            {
                // 中數 > 最左邊:小的在右邊
                // 往右搜索
                left = mid + 1;
            }
            else
            {
                // 中數 < 左邊: 小的在中數或中數左邊
                // 往左搜索
                right = mid;
            }
        }
        return nums[left];
    }
};

```
