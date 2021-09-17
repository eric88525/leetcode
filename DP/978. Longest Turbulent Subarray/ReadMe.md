# 978. Longest Turbulent Subarray
題目希望找出陣列中，最大的 turbulent subarray
+ 元素必須是連續的  i ~ i+n
+ subarray裡面的元素，如取2的winsize每次向右滑動，符號為大於小於循環

```c++
class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {

		if (arr.size() == 1) {
			return 1;
		}

		// the max len when last element is greater than last-1
        // the max len when last element is smaller than last-1
		int less = 1 , greater = 1 , max_len =0,result=0;
 
		for (int i = 1; i < arr.size(); i++) {
			
            if(arr[i] > arr[i-1]){
                
                greater = less + 1;
                less = 1;
            }else if (arr[i] < arr[i-1]){
                
                less = greater +1;
                greater = 1;
            }else{
                less = 1 , greater = 1;
            }     
            result = max(  result  , max(less,greater) );
		}
		return result;
	}
};
```

