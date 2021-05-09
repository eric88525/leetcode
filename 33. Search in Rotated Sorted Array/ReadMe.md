## 有2種情況

+ 中 & target 都在同一區塊

```cpp
if (nums[left]<=nums[mid] && nums[left]<=target || nums[left]>nums[mid] && nums[left]>target) 
{
	if (target<nums[mid])
    	right = mid;
    else
    	left = mid+1;
}
```

+ 中  & target 不同區塊

```cpp
else if (nums[left]<=nums[mid] && nums[left]>target) left = mid+1;
```
```cpp
else if (nums[left]>nums[mid] && nums[left]<=target) right = mid;  
```
