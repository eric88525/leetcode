# 201. Bitwise AND of Numbers Range 

https://ithelp.ithome.com.tw/articles/10245911

如果 left 和 right 的最大位元數不同，那麼最後結果一定是0

在過程中會&= 0的，也只有二進制中，left和right不同的區域，例如

left  = 11010001
11010010
11010011
right= 11010100

```c++
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
            
        if (left == 0 || right == 0) return 0;
        
        if ( int(log2(left)) != int(log2(right))) return 0;
         
        int shift_count = 0;
        
        while(left != right){
            
            left>>=1;
            right>>=1;
            shift_count+=1;
        }
        
        return right<<shift_count;
    }
};
```

