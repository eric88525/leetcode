# 922. Sort Array By Parity II

+ 問題是希望能讓偶數index有偶數，奇數index有奇數
+ 解法:
	+ 建立2個指標，分別指向偶數index 和 奇數index
	+ 當指標和數字符合，代表這數字放對了 (偶數index + 偶數)
	+ 當兩個指標都不符合，就讓他們換位置

```c++
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {   
        int oddindex=1 , evenindex=0;  
        while(  evenindex < nums.size() &&  evenindex < nums.size()  ){

            if (nums[evenindex] % 2 == 0){
                evenindex+=2;
            }else if (nums[oddindex] % 2 == 1){
                oddindex+=2;
            }else{
                swap( nums[evenindex] , nums[oddindex] );
                evenindex += 2;
                oddindex+=2;
            }
        }     
        return nums;     
    }
};
```


