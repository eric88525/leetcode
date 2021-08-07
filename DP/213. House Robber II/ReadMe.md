# 213. House Robber II

跟前一題目很像，在判斷第 N間房子最大能搶多少的方法一樣

當下的最大值 =  MAX( 前一間最大值 , 前二間最大 + 當下 )

```c++
int helper( vector<int>& nums , int lo , int hi){    
	int p1= nums[lo] ,p2=0,curr=0;
        
	for(int i=lo+1; i<= hi;i++){  
    	curr = max(nums[i]+p2 , p1);
        p2 = p1;
        p1 = curr;           
    }
    return curr;
}
```

但如果有圓環 ， 搶第一間就不能搶 最後一間

因此比較   1 ~ 倒數第二間  和   2 ~ 最後一間 誰能搶最多