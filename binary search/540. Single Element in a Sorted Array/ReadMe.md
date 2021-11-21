# solution

https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/628111/C%2B%2B-Solution-O(logn)-with-detailed-explanation

## 當mid = mid +1

1 1 2 2 4
or
0 1 1 2 2 4 4

如果mid is odd ，代表右邊是兩兩一組，如果是even，左邊是兩兩一組


## 當mid=mid-1

1 2 2 4 4
or
1 1 2 2 3 4 4
同上理

```c++
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {

		int left = 0, right = nums.size() - 1, mid;

		while (left < right) {

			mid = left + (right - left) / 2;

            
            if( nums[mid] == nums[mid+1] ){
                if( mid%2) right = mid -1;
                else left = mid + 2;
                
            }else  if( nums[mid] == nums[mid-1]) {
                if( mid%2) left = mid + 1;
                else right = mid -2;
            }else{
                return nums[mid];
            }       
		}
        return nums[left];	
	}
};
```

