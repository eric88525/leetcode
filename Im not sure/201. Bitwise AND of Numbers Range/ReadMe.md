# 201. Bitwise AND of Numbers Range

 如果 right left == 0 , 那肯定是0的
 如果他們的位元數不同,例如: 0001 ~ 1000 那也是0
 其他的話就正常運算

 

```c++
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
            
        if (left == 0 || right == 0) return 0;
        
        if ( int(log2(left)) != int(log2(right))) return 0;
         
        long long ans = left;
        
        for(long long  i=left+1;i<=right;i++){
            ans &= i;
        }
        
        return ans;
    }
};
```

