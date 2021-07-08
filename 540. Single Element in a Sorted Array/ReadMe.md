# solution

https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/628111/C%2B%2B-Solution-O(logn)-with-detailed-explanation

## 當mid = mid +1

1 1 2 2 4
or
0 1 1 2 2 4 4

如果mid is odd ，代表右邊是兩兩一組，如果是even，左邊是兩兩一組

```c++
if( nums[mid] == nums[mid+1] ){
	if(odd) right = mid -1;
    else left = mid + 2;
}
```

## 當mid=mid-1

1 2 2 4 4
or
1 1 2 2 3 4 4
同上理

```c++
else  if( nums[mid] == nums[mid-1]) {
	if(odd) left = mid + 1;
    	else right = mid -2;
}
```

