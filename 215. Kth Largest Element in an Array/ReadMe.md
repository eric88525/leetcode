# solution

# s1

參考他 直接用外掛  

https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```

# s2

手刻一個maxHeap 解釋看註解

Heap: 父節點總是 大於/小於  子節點的tree ，並且有2個Node

```c++
int findKthLargest(vector<int>& nums, int k) {     
    buildMaxHeap(nums);       
    int heapSize = nums.size();
    
    // 要找k大 就要做k-1次
    for( int i=0 ; i<k-1 ; i++ ){            
        swap( nums[0] , nums[--heapSize]);      
        // 被交換去最後的 就直接忽略它
        // 因此heapsize會逐漸變少
        heapify(nums,0,  heapSize);
    }      
    return nums[0];
}
```
heap 解析

https://www.geeksforgeeks.org/building-heap-from-array/ 